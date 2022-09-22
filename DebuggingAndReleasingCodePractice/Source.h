#pragma once

using namespace std;

#define PRE_RELEASE			//comment out for standard mode

#ifdef PRE_RELEASE			//if PRE_RELEASE, STUDENT_DATA object has email, else standard and it only has first and last names
struct STUDENT_DATA {
	string firstName;
	string lastName;
	string email;
};
#else
struct STUDENT_DATA {
	string firstName;
	string lastName;
};
#endif
