#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <list>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::list;

void examp01();
void vectorPrint(vector<int> vect);
void examp02();
void listPrint(list<int> numbers);

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
	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		if (*it == userNum) {
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
