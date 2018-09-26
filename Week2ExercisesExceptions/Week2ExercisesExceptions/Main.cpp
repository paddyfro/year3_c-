#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
//setw

using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::ifstream;


double ex1(int a, int b);
double average(int arr[], int len);
void examp01();
void examp03();
void examp04();
void examp05();
void examp06();

int main()
{
	int exNum = 9;
	while (exNum != -1) {
		cout << "enter exercise number: (-1 to exit)" << endl;
		cin >> exNum;

		switch (exNum) {
		case -1 :
			break;
		case 1:
			examp01();
			break;
		case 2:
			examp01();
			break;
		case 3:
			examp03();
			break;
		case 4:
			examp04();
			break;
		case 5:
			examp05();
			break;
		case 6:
			examp06();
			break;
		default:
			cout << "invalid entry (1-6) or (-1) to exit" << endl;
		}
	}
	system("pause");
	return 0;
}

//ex01 ex02
void examp01()
{
	int choice =1;

	while (choice != 2)
	{
		cout << "enter 2 numbers: " << endl;
		int a, b;
		cin >> a >> b;
		try {
			cout << ex1(a,b) << endl;
		}
		catch (std::domain_error e) {
			cout << e.what() << endl;
		}
		cout << "go again? 1 = yes, 2 = no" << endl;
		cin >> choice;
	}

}

void examp03() {
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int arr01[] = {0,0,0,0,0,0,0,0,0,0};
	int arr02[] = { 1,2,3,4,5,6,7,8,9,0};

	try {
		cout << "arr: " << average(arr, 10) << endl;
		cout << "arr02: " << average(arr02, 10) << endl;
		cout << "arr01: " << average(arr01, 10) << endl;
	}
	catch (std::logic_error e)
	{
		cout << e.what() << endl;
	}
}

void examp04() {
	cout << "please enter 5 ints:" << endl;
	int a, b, c, d, e;
	//cin >> a >> b >> c >> d >> e;
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}

	try {
		cout << "average : " << average(arr, 5) << endl;
	}
	catch(std::logic_error e)
	{
		cout << e.what() << endl;
	}

	
}

void examp05() {
	/*
				exception
	    ____________|___________________________________________
		|							|							|
	runtime_error					|					logic_error
	______|______________			|		______________________|_________________________________________
	|					|			|		|					|					|						|
overflow_error		underflow_error	|	domain_error	  length_error		invalid_argument		  out_of_range
									|
									|
					________________|_____________________________			
					|				|			|				  |
				bad_alloc		bad_cast	bad_type_id		bad_exception	
	*/

}

/*exceptions to test for:
- all zero
- file empty
- not int in file (string, double)
- 
*/
void examp06(){
	ifstream in("C:\\Users\\paddy\\Desktop\\testfiles\\numbers5.txt");
	if (in)
	{
		int arr[5];
		for (int i = 0; i < 5; i++)
		{
			in >> arr[i];
			cout << arr[i] << " ";
		}
		cout << endl;
		try {
			cout << "average: " << average(arr, 5) << endl;
		}
		catch (std::logic_error e)
		{
			cout << e.what() << endl;
		}
	}
	else {
		cout << "error opening file" << endl;
	}
}

double ex1(int a, int b)
{
	if (b == 0)
	{
		throw std::domain_error("cannot divide by zero");
	}
	else {
		return (double)a / b;
	}
}

double average(int arr[], int len)
{
	int total = 0;
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] != 0)
		{
			total += arr[i];
		}
		else {
			count++;
		}
	}
	if (count == len)
	{
		throw std::logic_error("all values in array zero");
	}
	return total/((double)len-count);
}