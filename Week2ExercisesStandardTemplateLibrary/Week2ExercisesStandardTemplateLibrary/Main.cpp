#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <list>
#include <algorithm>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::list;
using std::sort;
using std::greater;

void examp01();
void vectorPrint(vector<int> vect);
void examp02();
void listPrint(list<int> numbers);
void examp03();
void examp04();
void examp05();
void examp06();
double getMedian(vector<int> nums);
void examp07();
void print(const vector<int> &nums, const string prompt);


int main() {
	cout << "enter exercise number: " << endl;
	int exNum;
	cin >> exNum;

	switch (exNum) {
	case 1:
		examp01();
		break;
	case 2:
		examp02();
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
	case 7:
		examp07();
		break;
	default:
		cout << "dont no have exercise of that number (1-20)" << endl;
	}
	system("pause");
	return 0;
}
//ex01
//dynamic array - vector
void examp01() {
	/*

	  std::vector<int> first;                                // empty vector of ints
  std::vector<int> second (4,100);                       // four ints with value 100
  std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (third);                       // a copy of third


	ofstream out("outputData.txt");
	if (out) {
		cout << "writing to file" << endl;
		out << "hello world" << endl;
		out.close();
	}
	else {
		cout << "error opening file" << endl;
	}
	*/
	// vector<int> num(10); - set default size of vector
	vector<int> numbers;
	int num;
	ifstream in("tester.txt");
	if (in) {
		while (!in.eof())
		{
			in >> num;
			numbers.push_back(num);
		}
	}
	else {
		cout << "error opening file" << endl;
	}
	vectorPrint(numbers);

	int userNum;
	do {
		cout << "enter number you wish to search for: (-1 to exit)" << endl;

		cin >> userNum;
		bool found = false;
		for (vector<int>::size_type i = 0; i < numbers.size(); i++)
		{
			if (numbers.at(i) == userNum) {
				cout << "found at position: " << i << endl;
				found = true;
			}
			/*
			if (numbers[i] == userNum) {
				cout << "found at position: " << i << endl;
				found = true;
			}
			*/
		}
		if (!found && userNum != -1) {
			cout << "number not found!" << endl;
		}
	} while (userNum != -1);
}

void vectorPrint(vector<int> vect)
{
	for (unsigned i = 0; i < vect.size(); i++)
		cout << ' ' << vect.at(i);
	cout << '\n';
}

//list object - linked list
void examp02() {
	list<int> numbers;
	int num;
	ifstream in("tester.txt");
	if (in) {
		while (!in.eof())
		{
			in >> num;
			numbers.push_back(num);
		}
	}
	else {
		cout << "error opening file" << endl;
	}
	listPrint(numbers);

	cout << "enter number you wish to search for: " << endl;
	int userNum;
	cin >> userNum;
	bool found = false;
	int count = 0;
	for (list<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter)
	{
		// *iter - dereference the iterator to return the value not the memory location reference
		if (*iter == userNum) {
			cout << "number found at position: " << count << endl;
			found = true;
		}
		count++;
	}
		
	if (!found) {
		cout << "number not found!" << endl;
	}
}

void listPrint(list<int> numbers) {
	cout << "mylist contains:";
	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';
}

void examp03() {
	vector<int> numbers;
	int num;
	ifstream in("tester.txt");
	if (in) {
		while (!in.eof())
		{
			in >> num;
			numbers.push_back(num);
		}
	}
	else {
		cout << "error opening file" << endl;
	}
	vectorPrint(numbers);
	//sort vector
	sort(numbers.begin(), numbers.end());
	vectorPrint(numbers);
	/*
	cout << "enter number you wish to search for: " << endl;
	int userNum;
	cin >> userNum;
	bool found = false;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers.at(i) == userNum) {
			cout << "found at position: " << i << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "number not found!" << endl;
	}
	*/
}


void examp04() {
	vector<int> numbers;
	int num;
	ifstream in("tester.txt");
	if (in) {
		while (!in.eof())
		{
			in >> num;
			numbers.push_back(num);
		}
	}
	else {
		cout << "error opening file" << endl;
	}
	vectorPrint(numbers);
	//sort vector
	// https://stackoverflow.com/questions/9025084/sorting-a-vector-in-descending-order
	sort(numbers.begin(), numbers.end(), greater<>());
	vectorPrint(numbers);

	cout << "enter number you wish to search for: " << endl;
	int userNum;
	cin >> userNum;
	bool found = false;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers.at(i) == userNum) {
			cout << "found at position: " << i << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "number not found!" << endl;
	}
}

/*
bool greater(int a, int b)
{
	return a > b;
}
*/
void examp05() {
	vector<int> numbers;
	int num;
	ifstream in("tester.txt");
	if (in) {
		while (!in.eof())
		{
			in >> num;
			numbers.push_back(num);
		}
	}
	else {
		cout << "error opening file" << endl;
	}
	

	cout << "median is: " << getMedian(numbers) << endl;
}

double getMedian(vector<int> nums) {
	int median = 0;
	sort(nums.begin(), nums.end());
	vectorPrint(nums);
	vector<int>::size_type mid = nums.size() / 2;
	if (nums.size() % 2 == 1) {
		return nums.at(mid);
	}
	else {
		median = (nums.at(mid - 1) + nums[mid]) / 2.0f;
	}
	return median;
}

void examp06() {
	vector<int> numbers, numBelow, numAbove;
	int num;
	ifstream in("tester.txt");
	if (in) {
		while (!in.eof())
		{
			in >> num;
			numbers.push_back(num);
		}
	}
	else {
		cout << "error opening file" << endl;
	}
	double median = getMedian(numbers);
	sort(numbers.begin(), numbers.end());
	for (vector<int>::size_type i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] < median) {
			numBelow.push_back(numbers[i]);
		}
		else
		{
			numAbove.push_back(numbers[i]);
		}
	}
	cout << "Median: " << median << endl;
	print(numAbove, "Above");
	print(numBelow, "Below");
}

void examp07() {
	vector<int> numbers;
	int num;
	ifstream in("tester.txt");
	if (in) {
		while (!in.eof())
		{
			in >> num;
			numbers.push_back(num);
		}
	}
	else {
		cout << "error opening file" << endl;
	}
	print(numbers, "*********** My Vector *************");
}

void print(const vector<int> &nums, const string prompt)
{
	cout << prompt << endl;
	for (unsigned i = 0; i < nums.size(); i++)
		cout << ' ' << nums.at(i);
	cout << '\n';
}