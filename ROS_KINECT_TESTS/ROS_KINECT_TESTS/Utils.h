#pragma once
#include "Kinect.h"
#define _USE_MATH_DEFINES // To have PI and other constants
#include <math.h>
#include <iostream>
#include <vector>
#include <set>

class Utils
{
public:
	Utils();
	~Utils();
	static float euclideanDistance(Joint a, Joint b);
	static float euclideanDistance(std::vector<float> a, std::vector<float> b);
	static float L1Distance(std::vector<float> a, std::vector<float> b);
	static float L1Distance(std::vector<float> a, std::vector<float> b, float alpha);
	static float getAngleBetween(Joint a, Joint mid, Joint c, bool rad);
	static float magnitude(float vec[3]);
	static void printPercentage(int cur, int total);
	static float overlap(const std::set<int>& detections, const std::set<int>& gt);
};


