#pragma once
#include<string>
#include<iostream>
#include<vector>
using std::string;
using std::vector;


struct studentType {
	string studentFName;
	string stdentLName;
	int testScore;
	char grade;
};

void readStudents(vector<studentType> &students, string fileName);
void printStudents(vector<studentType> &students);
void studentMain();
void assignGrade(studentType &stud);
int findHighest(vector<studentType> &students);
void printHighestScores(vector<studentType> &students);

