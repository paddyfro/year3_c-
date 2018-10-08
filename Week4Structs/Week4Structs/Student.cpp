#include "StudentType.h"
#include <iostream>
#include <vector>
#include<string>
#include<fstream>

using namespace std;

void readStudents(vector<studentType> &students, string fileName) {
	ifstream in(fileName);
	if (in)
	{
		string garbage;
		while (!in.eof()) {
			studentType stud;
			getline(in, stud.studentFName);
			getline(in, stud.stdentLName);
			in >> stud.testScore;
			getline(in, garbage);
			assignGrade(stud);
			students.push_back(stud);
		}

	}
	else {
		cout << "error reaind ing file" << endl;
	}
}

void printStudents(vector<studentType> &students) {
	for (studentType &stud :students) {
		cout << stud.stdentLName << ", " << stud.studentFName << ", " << stud.testScore << ", " << stud.grade << endl;
	}
}

void studentMain() {
	vector<studentType> students;
	readStudents(students, "studentDetails.txt");
	printStudents(students);
	//findHighest(students);
	printHighestScores(students);
}

void assignGrade(studentType &stud) {
	if (stud.testScore < 0 || stud.testScore > 100) {
		stud.grade = 'N';
	}
	else if (stud.testScore >= 85) {
		stud.grade = 'A';
	}
	else if (stud.testScore >= 70) {
		stud.grade = 'B';
	}
	else if (stud.testScore >= 55) {
		stud.grade = 'C';
	}
	else if (stud.testScore >= 40) {
		stud.grade = 'D';
	}
	else {
		stud.grade = 'F';
	}
}

int findHighest(vector<studentType> &students)
{
	int highest = 0;
	for (studentType &student : students) {
		if (highest < student.testScore)
		{
			highest = student.testScore;
		}
	}

	//cout << "highest test score: " << highest << endl;

	return highest;
}


void printHighestScores(vector<studentType> &students) {
	int highest = findHighest(students);
	cout << "\nStudents with the highest scores->" << endl;
	for (studentType &student : students) {
		if (student.testScore == highest)
		{
			cout << student.stdentLName << ", " << student.studentFName << ", " << student.testScore << ", " << student.grade << endl;
		}
	}
}