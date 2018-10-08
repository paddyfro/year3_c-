#pragma once
#include <iostream>
#include <string>
#include"menuItemType.h"
#include <fstream>
#include <iomanip>

using namespace std;

void readInMenu(vector<menuItemType> &menuItems, string filename) {
	ifstream in(filename);
	if (in) {
		string garbage;
		while (!in.eof()) {
			menuItemType menuItem;
			getline(in, menuItem.menuItem);
			in >> menuItem.menuPrice;
			getline(in, garbage);
			menuItems.push_back(menuItem);
		}
	
	}
	else {
		cout << "issue with reading in file" << endl;
	}
}
void showMenu(vector<menuItemType> &menuItems) {
	int num = 1;
	for (menuItemType menuItem : menuItems) {
		cout << num << ") " << setw(15) << left << menuItem.menuItem << " $" << menuItem.menuPrice<< endl;
		num++;
	}
}

void printCheck(vector<menuItemType> &selectedItems) {
	double total = 0;
	double tax;
	cout << "Welcome to Johnny's Restaurant" << endl;
	for (menuItemType item : selectedItems) {
		total += item.menuPrice;
		cout << setw(15) << left << item.menuItem << " $" << item.menuPrice << endl;
	}
	tax = total * 0.05;
	total += tax;
	cout << setw(15) << left << "tax" << " $" << setprecision(2) << tax << endl;
	cout << "\n" << setw(15) << left << "Amount Due" << " $" << setprecision(4) << total << endl;
}

void getData(vector<menuItemType> &menuList, vector<menuItemType> &customerOrder) {
	int customerChoice = -2;
	showMenu(menuList);
	while (customerChoice != -1) {		
		cout << "what item would you like? (1-8) (-1 to exit)" << endl;
		cin >> customerChoice;
		if (customerChoice > 0 && customerChoice <= 8)
		{
			customerOrder.push_back(menuList[customerChoice-1]);
		}
	}
}

void menuMain() {
	vector<menuItemType> menuList;
	vector<menuItemType> customerOrder;
	string filename = "restaurantItems.txt";
	readInMenu(menuList, filename);
	//showMenu(menuList);
	getData(menuList, customerOrder);
	printCheck(customerOrder);

}