108
SOAR_ID 0
SOAR_ID 1
SOAR_ID 2
SOAR_ID 3
SOAR_ID 4
ENUMERATION 5 1 state
ENUMERATION 6 1 nil
ENUMERATION 7 1 hr2i
ENUMERATION 8 1 initialize-hr2i
SOAR_ID 9
INTEGER_RANGE 10 -2147483648 2147483647
SOAR_ID 11
INTEGER_RANGE 12 -2147483648 2147483647
ENUMERATION 13 1 yes
INTEGER_RANGE 14 -2147483648 2147483647
SOAR_ID 15
INTEGER_RANGE 16 -2147483648 2147483647
SOAR_ID 17
INTEGER_RANGE 18 -2147483648 2147483647
ENUMERATION 19 1 yes
INTEGER_RANGE 20 -2147483648 2147483647
SOAR_ID 21
ENUMERATION 22 1 navigate
ENUMERATION 23 1 yes
SOAR_ID 24
ENUMERATION 25 1 initialize-hr2i
SOAR_ID 26
ENUMERATION 27 1 search-object
SOAR_ID 28
ENUMERATION 29 1 grasp
INTEGER_RANGE 30 -2147483648 2147483647
SOAR_ID 31
ENUMERATION 32 1 search-person
SOAR_ID 33
ENUMERATION 34 1 deliver
INTEGER_RANGE 35 -2147483648 2147483647
ENUMERATION 36 1 yes
SOAR_ID 37
ENUMERATION 38 1 learn-person
SOAR_ID 39
ENUMERATION 40 1 navigate-to-person
SOAR_ID 41
ENUMERATION 42 1 point-obj
ENUMERATION 43 1 yes
SOAR_ID 44
ENUMERATION 45 1 recognize-person
ENUMERATION 46 1 yes
SOAR_ID 47
ENUMERATION 48 1 memorize-person
ENUMERATION 49 1 yes
SOAR_ID 50
ENUMERATION 51 1 ask-name
ENUMERATION 52 1 yes
SOAR_ID 53
ENUMERATION 54 1 exit-apartment
SOAR_ID 55
ENUMERATION 56 1 introduce-me
ENUMERATION 57 1 yes
SOAR_ID 58
ENUMERATION 59 1 record
ENUMERATION 60 13 ask-name deliver exit-apartment grasp initialize-hr2i introduce-me memorize-person navigate none point-obj recognize-person search-object search-person
SOAR_ID 61
ENUMERATION 62 1 prohibitions-in-run-time
SOAR_ID 63
SOAR_ID 64
SOAR_ID 65
SOAR_ID 66
ENUMERATION 67 1 complete
INTEGER_RANGE 68 -2147483648 2147483647
ENUMERATION 69 1 complete
INTEGER_RANGE 70 -2147483648 2147483647
ENUMERATION 71 1 complete
INTEGER_RANGE 72 -2147483648 2147483647
ENUMERATION 73 1 complete
INTEGER_RANGE 74 -2147483648 2147483647
ENUMERATION 75 1 yes
SOAR_ID 76
ENUMERATION 77 1 complete
INTEGER_RANGE 78 -2147483648 2147483647
ENUMERATION 79 1 succeeded
SOAR_ID 80
ENUMERATION 81 1 complete
INTEGER_RANGE 82 -2147483648 2147483647
ENUMERATION 83 1 yes
ENUMERATION 84 1 yes
SOAR_ID 85
ENUMERATION 86 1 complete
SOAR_ID 87
ENUMERATION 88 1 complete
SOAR_ID 89
ENUMERATION 90 1 complete
SOAR_ID 91
ENUMERATION 92 1 complete
SOAR_ID 93
ENUMERATION 94 1 complete
INTEGER_RANGE 95 -2147483648 2147483647
INTEGER_RANGE 96 -2147483648 2147483647
INTEGER_RANGE 97 -2147483648 2147483647
INTEGER_RANGE 98 -2147483648 2147483647
INTEGER_RANGE 99 -2147483648 2147483647
SOAR_ID 100
ENUMERATION 101 1 complete
INTEGER_RANGE 102 -2147483648 2147483647
ENUMERATION 103 1 yes
ENUMERATION 104 1 yes
INTEGER_RANGE 105 -2147483648 2147483647
SOAR_ID 106
INTEGER_RANGE 107 -2147483648 2147483647
131
0 desired 106
0 io 1
0 last-operator 60
0 location 9
0 name 7
0 object 11
0 operator 4
0 operator 21
0 operator 24
0 operator 26
0 operator 28
0 operator 31
0 operator 33
0 operator 37
0 operator 39
0 operator 41
0 operator 44
0 operator 47
0 operator 50
0 operator 53
0 operator 55
0 operator 58
0 operator 61
0 person 17
0 robot 15
0 superstate 6
0 top-state 0
0 type 5
1 input-link 2
1 output-link 3
2 action-result 79
3 achived 80
3 ask-name 85
3 deliver 76
3 exit-apartment 87
3 grasp 65
3 introduce-me 89
3 memorize-person 91
3 navigate 66
3 point-obj 100
3 recognize-person 93
3 search-object 64
3 search-person 63
4 name 8
9 id 10
9 pointed-at 84
11 delivered 36
11 found 23
11 grasped 13
11 id 12
11 locId 14
11 near 104
11 pointed 43
11 toBeGrasped 75
15 introduced 57
15 locId 16
15 obj1Id 30
15 pointed-at-loc 107
17 askedName 52
17 followed 83
17 found 103
17 id 18
17 locId 20
17 memorized 49
17 near 19
17 obj1Id 35
17 recognized 46
21 name 22
21 toLoc 9
21 withRob 15
24 name 25
26 name 27
26 objToSearch 11
26 toLoc 9
28 name 29
28 objToGrasp 11
28 withRob 15
31 name 32
31 persToSearch 17
31 toLoc 9
33 name 34
33 toPers 17
33 withRob 15
37 name 38
39 name 40
41 locId 105
41 name 42
41 withRob 15
44 name 45
44 toPers 17
44 withRob 15
47 name 48
47 toPers 17
47 withRob 15
50 name 51
50 toPers 17
50 withRob 15
53 localization 9
53 name 54
53 robot 15
55 name 56
55 withRob 15
58 name 59
61 name 62
63 pers 74
63 status 73
64 obj 72
64 status 71
65 obj 68
65 status 67
66 loc 70
66 status 69
76 pers 78
76 status 77
80 status 81
80 true 82
85 aux 95
85 status 86
87 loc 99
87 status 88
89 aux 96
89 status 90
91 aux 97
91 status 92
93 aux 98
93 status 94
100 loc 102
100 status 101
106 object 11
106 person 17
106 robot 15
