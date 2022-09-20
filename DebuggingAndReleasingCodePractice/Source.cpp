//Navdeep Mangat
//CSCN73030-22F
//Assignment 2
//Due: Sept. 23, 2022
//
//MAKE REPO PUBLIC
//questions
//want all this in the source.cpp?

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>

using namespace std;


struct STUDENT_DATA {
	string firstName;
	string lastName;
};

int main() {

	vector <STUDENT_DATA> students;														//vector space to hold student data

	ifstream fin;
	fin.open("StudentData.txt");

	if (fin.is_open()) {
		STUDENT_DATA readStudentData;													//student object used to read in each student's data from text file
		string line;

		while (!fin.eof()) {
			getline(fin, line);															//get the line from the text file, put it in istringstream object, use delimiter to parse content
			istringstream isLine(line);
			getline(isLine, readStudentData.lastName, ',');								//get last name since it's first and before the ',', put it in student object

			getline(isLine, readStudentData.firstName, '\n');							//get first name, put it in student object, 

			if (readStudentData.lastName == "" || readStudentData.firstName == "")		//condition for if it reads in blank for first or last name, skip the iteration, mostly to work around extra blank lines in the file
				continue;

			students.push_back(readStudentData);
		}
		fin.close();
	}
	else {
		cout << "Error opening file: StudentData.txt" << endl;
	}

	return 1;
}
