//Navdeep Mangat
//CSCN73030-22F
//Assignment 2
//Due: Sept. 23, 2022
//
//MAKE REPO PUBLIC

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>

using namespace std;

#define PRE_RELEASE

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

int main() {

	#ifdef PRE_RELEASE																	//if PRE_RELEASE, print PRE_RELEASE notice and use student data text file with student emails
		cout << "The application is running PRE_RELEASE source code" << endl;
		string fileName = "StudentData_Emails.txt";
	#else																			
		cout << "The application is running STANDARD source code" << endl;				//else print standard notice and use student data text file with no emails
		string fileName = "StudentData.txt";
	#endif

	vector <STUDENT_DATA> students;														//vector space to hold student data

	ifstream fin;
	fin.open(fileName);

	if (fin.is_open()) {
		STUDENT_DATA readStudentData;													//student object used to read in each student's data from text file
		string line;

		while (!fin.eof()) {
			getline(fin, line);															//get the line from the text file, put it in istringstream object, use delimiter to parse content
			if (line.empty())															//check if empty, skip iteration - just to account for blank lines in the text document
				continue;
			istringstream isLine(line);
			getline(isLine, readStudentData.lastName, ',');								//get last name since it's first and before the ',', put it in student object
			getline(isLine, readStudentData.firstName, ',');							//get first name, put it in student object - until ',' if pre-release, or ends at new line character if standard mode

			#ifdef PRE_RELEASE
				getline(isLine, readStudentData.email);									//get email too only if PRE_RELEASE, put it in PRE_RELEASE student object which has email member
			#endif

			students.push_back(readStudentData);										//add the read in student's data to the vector, loop back to next student, read in their data, add it to the vector and so on until end of file
		}
		fin.close();
	}
	else 
		cout << "Error opening file: " << fileName << endl;
	

	#ifdef _DEBUG																		//print out student data from vector like it appears in text file								
		for (int i = 0; i < students.size(); i++) {
			#ifdef PRE_RELEASE															//if pre-release, print out the email as well
				cout << 
					students[i].lastName << "," << 
					students[i].firstName << "," << 
					students[i].email 
					<< endl;
			#else																		//else standard mode so just print out last and first names
				cout << 
					students[i].lastName << "," << 
					students[i].firstName 
					<< endl;
			#endif
		}
	#endif

	return 1;
}
