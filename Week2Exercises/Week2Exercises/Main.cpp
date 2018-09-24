#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::sin;
using std::setw;
using std::ofstream;
using std::ifstream;
using std::to_string;

int squareNumbers(int number);
double totalGrade(int fg, int ca);
string::size_type longestString(string lines[], int lengthArray);
void frame(string arr[], int length);
void frame(string arr[], int length, int alignment = 1);
void doubleIntValueRef(int num);
void doubleIntValueVal(int &num);
string StringPadding(string original, size_t charCount);


//ex 1
int main1()
{
	string name;
	cout << "Please enter your name: " << endl;
	getline(cin, name);

	ofstream outFile("C:\\Users\\paddy\\Desktop\\testfiles\\name.txt");
	if (outFile)
	{
		outFile << name << endl;
		outFile.close();
	}
	else
	{
		cout << "error opening file" << endl;
	}
	system("pause");
	return 0;
}
//ex2
int main2()
{
	ifstream inFile("C:\\Users\\paddy\\Desktop\\testfiles\\name.txt");
	if (inFile)
	{
		string name;
		//inFile >> name;
		getline(inFile, name);
		string::size_type len = name.length();
		cout << string(len+4, '*')<< endl;
		cout << "* " << name << " *" << endl;
		cout << string(len + 4, '*')<< endl;
		inFile.close();
	}
	else {
		cout << "error opening file" << endl;
	}
	system("pause");
	return 0;
}
//es3
int main3()
{
	int num;
	int total=0;
	int count=0;
	ifstream inFile("C:\\Users\\paddy\\Desktop\\testfiles\\num.txt");
	if (inFile)
	{
	
		while (!inFile.eof())
		{
			inFile >> num;
			total += num;
			count++;
		}
		double avg = total / (float)count;
		cout << "average: " << avg << endl;

	}
	else
	{
		cout << "error opening file";
	}
	system("pause");
	return 0;
}
//ex4
int main4()
{
	string name;
	int final, ca;
	float grade;
	ofstream out("C:\\Users\\paddy\\Desktop\\testfiles\\finalResults.txt");
	ifstream in("C:\\Users\\paddy\\Desktop\\testfiles\\grades.txt");
	if (in)
	{
		while (!in.eof())
		{
			in >> name;
			in >> final;
			in >> ca;
			grade = ((float)final * 0.6) + ((float)ca *0.4);
			if (out)
			{
				out << name << " "<< grade << endl;
				out.close();
			}
			else
			{
				cout << "error opening file" << endl;
			}
		}
		//cout << "name: " << name << " final: " << final << " ca: " << ca << endl;
		//grade = ((float)final / 100 * 60) + ((float)ca / 100 * 40);
		//cout << name << "'s final mark is: " << grade<< endl;
	}
	else
	{
		cout << "error reading in file"<< endl;
	}
	system("pause");
	return 0;
}
//ex5
int main5()
{
	for (int i = 1; i <= 100; i++)
	{
		cout << i << " * "<< i <<" = " << squareNumbers(i) << endl;
	}
	system("pause");
	return 0;
}
//ex6
int main6()
{
	int finalgrade, ca;
	cout << "final grade: " << endl;
	cin >> finalgrade;
	cout << "CA: " << endl;
	cin >> ca;
	double tg = totalGrade(finalgrade, ca);

	cout << "total mark: " << tg << endl;

	system("pause");
	return 0;
}
//ex 10 11
int main7()
{
	string lines[] = { "hello", "i am here", "where are you now?", "over yonder" };
	cout << "max length is: " << longestString(lines, 4)<< endl;
	frame(lines, 4,1);
	frame(lines, 4, 2);
	frame(lines, 4, 3);

	system("pause");
	return 0;
}
//ex 12
int main8(){
	int num= 20;
	//ref
	doubleIntValueRef(num);

	//value
	doubleIntValueVal(num);
	system("pause");
	return 0;
}



//ex5
int squareNumbers(int number)
{
	return number * number;
}
//ex7
double totalGrade(int fg, int ca)
{
	return (fg *.6) + (ca * 0.4);
}

//string::size_type longestString(string (&lines)[], int lengthArray)
string::size_type longestString(string lines[], int lengthArray)
{
	if (lengthArray > 0)
	{
		string::size_type max = lines[0].length();
		for (int i = 0; i < lengthArray; i++)
		{
			if (lines[i].length() > max)
			{
				max = lines[i].length();
			}
		}
		return max;
	}
	
}
//esercisse 9
void frame(string arr[], int length)
{
	string::size_type max = longestString(arr, length);
	string top(max + 4, '*');

	cout << top << endl;
	for (int i = 0; i < length; i++)
	{
		string::size_type paddL = max - arr[i].length();
		cout << "* " << arr[i] << string(paddL, ' ') << " *" << endl;
	}
	cout << top << endl;
}
//exercise 11
void frame(string arr[], int length, int alignment)
{

	string::size_type max = longestString(arr, length);
	string top(max + 4, '*');

	cout << top << endl;
	for (int i = 0; i < length; i++) {
		if (alignment == 1) {
			string::size_type paddL = max - arr[i].length();
			cout << "* " << arr[i] << string(paddL, ' ') << " *" << endl;
		}
		else if (alignment == 2)
		{
			string::size_type paddL = max - arr[i].length();
			cout << "* " << string(paddL, ' ') << arr[i] << " *" << endl;
		}
		else {
			string::size_type diff = (max - arr[i].length());
			string::size_type paddL = diff / 2;
			string::size_type paddR = diff - paddL;
			cout << "* " << string(paddL, ' ') << arr[i] << string(paddR, ' ') << " *" << endl;
		}

	}
	cout << top << endl;
}

//ex12 pass by reference
void doubleIntValueRef(int num)
{
	cout << num << " *2= " << num * 2 << endl;
}

//ex 12 pass by value
void doubleIntValueVal(int &num)
{
	cout << num << " *2= " << num * 2 << endl;
}

//ex 13
int main9()
{
	//string deetsToBeWritten ="";
	string fileName;
	cout << "please enter name of file you wish to export to(include file extension): " << endl;
	getline(cin, fileName);
	fileName = "C:\\Users\\paddy\\Desktop\\testfiles\\" + fileName;

	string name;
	int final, ca;
	float grade;
	ofstream out(fileName);
	ifstream in("C:\\Users\\paddy\\Desktop\\testfiles\\grades1.txt");
	if (in)
	{
		while (!in.eof())
		{
			in >> final;
			in >> ca;
			getline(in, name);
			grade = (final * 0.6) + (ca *0.4);
			//deetsToBeWritten = deetsToBeWritten + grade + " " + name + "\n";
			if (out)
			{
				out << grade << " " << name << endl;
				out.close();
			}
			else
			{
				cout << "error opening file" << endl;
			}
		}

		
		//cout << "name: " << name << " final: " << final << " ca: " << ca << endl;
		//grade = ((float)final / 100 * 60) + ((float)ca / 100 * 40);
		//cout << name << "'s final mark is: " << grade<< endl;
	}
	else
	{
		cout << "error reading in file" << endl;
	}
	system("pause");
	return 0;
}

//ex14
int main()
{
	//append a int to a string
	//op = name + std::to_string(num);
	
	
	string op = "";
	cout << "enter value to go to (1,000,000 max)" << endl;
	int maxValue;
	cin >> maxValue;
	int halfValue = maxValue / 2;
	if(maxValue %2 != 0)
	{
		halfValue += 1;
		cout << "halfV :" << halfValue << endl;
	}
	/*
	for (int i = 1; i <= halfValue; i++)
	{
		
		cout <<i << " * " << i << " = " << squareNumbers(i) << "     ";
		if (i + halfValue <= maxValue) {
			cout << setw(10) << i + halfValue << " * " << i + halfValue << " = " << squareNumbers(i + halfValue);
		}
		cout << endl;
	}
	*/
	for (int i = 1; i <= halfValue; i++)
	{

		//cout << i << " * " << i << " = " << squareNumbers(i) << "     ";
		op = to_string(i) + " * " + to_string(i) + " = " + to_string(squareNumbers(i));
		cout << StringPadding(op, 25);
		if (i + halfValue <= maxValue) {
			cout <<  i + halfValue << " * " << i + halfValue << " = " << squareNumbers(i + halfValue);
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

string StringPadding(string original, size_t charCount)
{
	original.resize(charCount, ' ');
	return original;
}
