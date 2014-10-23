// rosserial_hello_world.cpp : Example of sending command velocities from Windows using rosserial
// ROS includes
#include "stdafx.h"
#include <string>
#include <stdio.h>
#include "ros.h"
#include <geometry_msgs/Twist.h>
#include <windows.h>

#include <fstream>
#include <string>

using namespace std;

// Gesture Recognition includes and methods
#include <thread>
#include <mutex>
#include "GestureRecognition.h"
#include "Kinect2Utils.h"
#include "BodyRGBViewer.h"

// Globals
const bool RGB = true;
bool get_data = true;
mutex mtx;

void dataGetter(Kinect2Utils* k2u, GestureRecognition* gr, BodyRGBViewer* view) {
	bool rightBody = true;
	mtx.lock();
	bool _work = get_data;
	bool first = true;
	UINT64 id = 0;
	mtx.unlock();
	while (_work) {
		IBodyFrame* bodyFrame = k2u->getLastBodyFrameFromDefault();
		if (bodyFrame) {		
			view->setBodyFrameToDraw(bodyFrame);
			Skeleton sk = Kinect2Utils::getTrackedSkeleton(bodyFrame, id, first);
			/// temporal cheat
			if (sk.getTrackingID() > 0) {
				gr->addFrame(sk.getDynamicGestureRecognitionFeatures(rightBody), sk.getStaticGestureRecognitionFeatures(rightBody));
			} // end of cheat
			else if (!first && sk.getTrackingID() == id) {
				gr->addFrame(sk.getDynamicGestureRecognitionFeatures(rightBody), sk.getStaticGestureRecognitionFeatures(rightBody));
			}
			else if (first && id != sk.getTrackingID()) {
				id = sk.getTrackingID(); // Even though the skeleton is empty -i.e. id == -1- this doesn't change nything
				first = false;
				gr->addFrame(sk.getDynamicGestureRecognitionFeatures(rightBody), sk.getStaticGestureRecognitionFeatures(rightBody));
			}
		}
		SafeRelease(bodyFrame); // If not the bodyFrame is not get again
		mtx.lock();
		_work = get_data;
		mtx.unlock();
	}
}

void recognizeGestures(const vector<vector<vector<float>>>& models, Kinect2Utils& k2u, BodyRGBViewer& view) {
	GestureRecognition gr;
	GRParameters params = GestureRecognition::readParameters("Results\\GestureRecognitionParameters.txt");
	get_data = true;
	thread datagetter(dataGetter, &k2u, &gr, &view);
	Gesture gest = gr.RecognizeGesture(models, params);
	mtx.lock();
	get_data = false;
	mtx.unlock();
	datagetter.join();
	cout << "Recognized gesture: " << ((gest == SALUTE)? "HELLO!" : "POINT_AT!") << endl;
}

vector<vector<vector<float>>> readModels() {
	string gestPath = "C:\\Users\\Gerard\\Dropbox\\MAI\\3dSemester\\TFM\\src\\HR2I\\GestureRecorder\\GestureRecorder\\gestures\\";
	std::vector<std::vector<std::vector<float>>> models(N_DYNAMIC_GESTURES);
	models[SALUTE] = Skeleton::gestureFeaturesFromCSV(gestPath + "HelloModel/HelloModel_features.csv");
	//models[POINT_AT] = Skeleton::gestureFeaturesFromCSV(gestPath + "PointAtModel/PointAtModel_features.csv");
	//models[POINT_AT] = GestureRecognition::addThirdFeature(models[POINT_AT]);
	return models;
}
extern void testEqualDTWMethods();
extern void trainDTWParameters();
extern void showValuesGestTh();

// MAIN
int _tmain(int argc, _TCHAR * argv[])
{
	trainDTWParameters();
	Kinect2Utils k2u;
	HRESULT hr = k2u.initDefaultKinectSensor(true);
	if (!SUCCEEDED(hr)) return -1;

	hr = k2u.openBodyFrameReader();
	if (!SUCCEEDED(hr)) return -1;

	BodyRGBViewer view(&k2u);
	thread iface = view.RunThreaded(RGB, true, false);
	std::vector<std::vector<std::vector<float>>> models = readModels();
	while (true) { recognizeGestures(models, k2u, view); }
	iface.join();
	return 0;
	// End of test


	std::ifstream myfile;
	myfile.open("ROS_MASTER_HOST.txt");
	std::string ROS_MASTER_HOST;
	std::getline(myfile, ROS_MASTER_HOST);
	while (ROS_MASTER_HOST[0] == '#') std::getline(myfile, ROS_MASTER_HOST);
	myfile.close();


	ros::NodeHandle nh;
	char *ros_master = const_cast<char*>(ROS_MASTER_HOST.c_str());

	printf("Connecting to server at %s\n", ros_master);
	nh.initNode(ros_master);

	printf("Advertising cmd_vel message\n");
	geometry_msgs::Twist twist_msg;
	ros::Publisher cmd_vel_pub("cmd_vel", &twist_msg);
	nh.advertise(cmd_vel_pub);

	printf("Go robot go!\n");
	while (1)
	{
		twist_msg.linear.x = 5.1;
		twist_msg.linear.y = 0;
		twist_msg.linear.z = 0;
		twist_msg.angular.x = 0;
		twist_msg.angular.y = 0;
		twist_msg.angular.z = -1.8;
		cmd_vel_pub.publish(&twist_msg);

		nh.spinOnce();
		Sleep(100);
	}

	printf("All done!\n");
	return 0;
}