//first c++ program!

#include <iostream>
#include <string>
#include <iomanip>
//setw

using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::setw;

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
void exercise_10();
void exercise_11();
void exercise_13();
void exercise_14();
void exercise_15();
string::size_type getMaxLength(string lines[], int size);

string::size_type getMaxLength(string lines[], int size)
{
	if (size > 0)
	{
		string::size_type max = lines[0].length();
		for (int i = 1; i < size; i++)
		{
			if (max < lines[i].length())
			{
				max = lines[i].length();
			}
		}
		return max;
	}
	return -1;
}

void printArrayAlignment(string lines[], int size, int alignment=1)
{
	//string lines[] = { "hello, there", "this", "is SPARTA!" };
	string::size_type max = getMaxLength(lines, size);
	string top(max + 4, '*');
	
	//int numElements = sizeof(lines) / sizeof(lines[0]);
	//cout << numElements << endl;
	cout << top << endl;
	for (int i = 0; i < size; i++) {
		if (alignment == 1) {
			string::size_type paddL = max - lines[i].length();
			cout << "* " << lines[i] << string(paddL, ' ') << " *" << endl;
		}
		else if (alignment == 2)
		{			
			string::size_type paddL = max - lines[i].length();
			cout << "* " << string(paddL, ' ') << lines[i] << " *" << endl;
		}
		else {
			string::size_type diff = (max - lines[i].length());
			string::size_type paddL = diff / 2;
			string::size_type paddR = diff - paddL;
			cout << "* " << string(paddL, ' ') << lines[i] << string(paddR, ' ') << " *" << endl;
		}
		
	}
	cout << top << endl;
}


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
	case 10:
		exercise_10();
		break;
	case 11:
		exercise_11();
		break;
	case 13:
		exercise_13();
		break;
	case 14:
		exercise_14();
		break;
	case 15: 
		exercise_15();
		break;
	default:
		cout << "invalid entry (1-10)" << endl;
	}
	//exercise_1();
	//exercise_2();
	//exercise_4();
	//exercise_5();
	//exercise_6();
	//exercise_7();
	//exercise_8();
	system("pause");
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

void exercise_10()
{
	int product = 0;
	for (int i = 1; i <= 10; i++)
	{
		product = product + i * i;
	}
	cout << "the product of all numbers from 1-10: " << product << endl;


}

void exercise_11() {
	/*cout << "What shape would you like?\n 1) Square\n 2) Rectangle\n 3) Triangle" << endl;
	int shape;
	cin >> shape;
	cout << "how high?" <<endl;
	int height;
	cin >> height;
	if (shape == 2)
	{
		cout << "width? " << endl;

	}
	*/

	cout << "height?" << endl;
	int squareH, rectangleH, triangleH;
	cin >> squareH >> rectangleH >> triangleH;


	int rows = squareH > rectangleH ? squareH : rectangleH;
	if (triangleH > squareH && triangleH > rectangleH)
	{
		rows = triangleH;
	}


		for(int i = 1; i <= rows; i++)
		{			
			if (squareH+1 > i)
			{
				cout << string(squareH, '*');
				cout << "    ";
			}
			else
			{
				cout << string(squareH, ' ');
				cout << "    ";
			}

			if (rectangleH+1 > i)
			{
				cout << string(rectangleH*2, '*');
				cout << "    ";
			}
			else
			{
				cout << string(rectangleH*2, ' ');
				cout << "    ";
			}

			if (triangleH+1 > i)
			{
				cout << string(triangleH - i, ' ');
				cout << string((i * 2) - 1, '*');				
			}
			cout << endl;
				
		}


		/*
		//square
	for (int i = 0; i < 5; i++)
	{
		for (int x = 0; x < 5; x++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "\n\n" << endl;

	//rectangle
	for (int i = 0; i < 5; i++)
	{
		for (int x = 0; x < 10; x++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "\n\n" << endl;
	
	//pyramid
	int width = 5;
	
	for (int i = 1; i <= width; i++)//height
	{
		for (int x = 0; x < (width-i); x++)//width
		{
			cout << " ";		
		}
		for (int x = 0; x < (i * 2) - 1; x++)
		{
			cout << "*";
		}
		
		cout << endl;
	}
	cout << "\n\n" << endl;
	*/


}

void exercise_13()
{
	cout << "enter your name: " << endl;
	string name;
	cin.ignore();
	getline(cin, name);
	cout << "how much padding is needed?" << endl;
	int paddingSize;
	cin >> paddingSize;

	string msg = "hello, " + name;
	string::size_type length = msg.size()+4 + (paddingSize*2);
	string top(length, '*');
	//string buffer(msg.size()+2, ' ');
	string padd = "* " + string(length - 4, ' ') + " *";
	
	cout << top << endl;
	for (int i = 0; i < paddingSize; i++) {
		cout << padd << endl;
	}
	//cout << "*" << buffer << "*" << endl;
	cout << "* " <<string(paddingSize, ' ')  << msg << string(paddingSize, ' ') << " *" << endl;
	for (int i = 0; i < paddingSize; i++) {
		cout << padd << endl;
	}
	//cout << "*" << buffer << "*" << endl;
	cout << top << endl;
}



void exercise_14()

{
	/*int foo[5];
	int foo1[5] = { 1,2,3,4,5 };
	foo[2] = 9;
	cout << foo[2] << endl;

	*/
	string lines[] = { "hello, there", "this", "is SPARTA!" };
	string::size_type max = getMaxLength(lines, 3);
	string top(max + 4, '*');
	cout << top << endl;
	int numElements = sizeof(lines) / sizeof(lines[0]);
	//cout << numElements << endl;
	for (int i = 0; i < 3; i++)
	{
		string::size_type paddL = max - lines[i].length();
		cout << "* " << lines[i] << string(paddL, ' ') << " *" << endl;		
	}
	cout << top << endl<< endl;

	cout << top << endl;
	for (int i = 0; i < 3; i++)
	{
		string::size_type paddL = max - lines[i].length();
		cout << "* " << string(paddL, ' ')  << lines[i]  << " *" << endl;
	}
	cout << top << endl;

	 

	cout << top << endl;
	for (int i = 0; i < 3; i++)
	{
		string::size_type diff = (max - lines[i].length());
		string::size_type paddL = diff / 2;
		string::size_type paddR = diff - paddL;
		cout << "* " << string(paddL, ' ') << lines[i] << string(paddR, ' ') << " *" << endl;
	}
	cout << top << endl;



}


void exercise_15()
{
	string lines[] = { "The elephant is a bonnie bird", "it flits from tree to tree", "it lays its nest in a rhubarb bush","and whistles like a bee, buzz buzz buzz buzz" };
	cout << "please enter alignment, 1 -left, 2 -right, 3 -centre" << endl;
	int align;
	cin >> align;
	printArrayAlignment(lines, 4, align);
	printArrayAlignment(lines,4);
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



