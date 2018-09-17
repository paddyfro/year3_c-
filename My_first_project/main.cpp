//first c++ program!

#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;
using std::cin;

int sum(int x, int y);
void print_Ham();
void get_Name();
void exercise_1();
void exercise_2();
void exercise_3();
void exercise_4();
void exercise_5();
void exercise_6();
void exercise_7();
void exercise_8();

int main() {
	/*
	print_Ham();
	get_Name();
	int num = sum(2,5);
	cout << "summed num : " << num << endl;
	*/
	cout << "enter exercise number: " << endl;
	int exNum;
	cin >> exNum;

	switch (exNum) {
	case 1:
		exercise_1();
		break;
	case 2:
		exercise_2();
		break;
	case 3:
		exercise_3();
		break;
	case 4:
		exercise_4();
		break;
	case 5:
		exercise_5();
		break;
	case 6:
		exercise_6();
		break;
	case 7:
		exercise_7();
		break;
	case 8:
		exercise_8();
		break;
	case 9:
		cout << "implemented switch menu system" << endl;
	default:
		cout << "invalid entry (1-8)" << endl;
	}
	//exercise_1();
	//exercise_2();
	//exercise_4();
	//exercise_5();
	//exercise_6();
	//exercise_7();
	//exercise_8();
	return 0;
}

void exercise_1()
{
	cout << "Hello World!" << endl;
}

void exercise_2()
{
	cout << "please enter your name: " << endl;
	string name;
	cin >> name;
	cout << "Hello, " << name << endl;
}

void exercise_3()
{
	exercise_1();
}

void exercise_4()
{
	cout << "please enter your name: " << endl;
	string name;
	getline(cin, name);
	cout << "your name is : " << name << endl;
}

void exercise_5()
{
	cout << "enter your full name: " << endl;
	string fName, lName;
	cin >> fName >> lName;
	cout << "your name is : " << lName << ", " << fName << endl;
}

void exercise_6()
{
	cout << "please enter two numbers: " << endl;
	int max, num1, num2;
	cin >> num1 >> num2;
	max = num1;
	if (num2 >= max)
	{
		max = num2;
	}
	cout << "largest number is: " << max;
	
}

void exercise_7()
{
	cout << "please enter your age: " << endl;
	int age;
	cin >> age;
	if (age < 0)
	{
		cout << "you aren't even born yet, how did you get here?" << endl;
	}
	else if (age < 18)
	{
		cout << "you are a child" << endl;
	}
	else if (age <= 65)
	{
		cout << "you are an adult" << endl;
	}
	else
	{
		cout << "you are a senior" << endl;
	}
}

void exercise_8()
{
	int mark;
	cout << "please enter your mark" << endl;
	cin >> mark;
	if (mark > 100 || mark < 0)
	{
		cout << "invalid" << endl;
	}
	else if (mark >= 85)
	{
		cout << "A" << endl;
	}
	else if (mark >= 70)
	{
		cout << "B" << endl;
	}
	else if (mark >= 55)
	{
		cout << "C" << endl;
	}
	else if (mark >= 40)
	{
		cout << "D" << endl;
	}
	else
	{
		cout << "F" << endl;
	}
}

int sum(int x, int y)
{
	return x + y;
}

void print_Ham() {
	cout << "ham\n";
}

void get_Name() {
	cout << "example" << endl;
	string name;
	cout << "Hello World!\n";
	cout << "please enter your name:";
	cin >> name;
	cout << "hello " << name << endl;
}



