#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

struct menuItemType {
	string menuItem;
	double menuPrice;
};

void readInMenu(vector<menuItemType> &menuItems, string filename);
void showMenu(vector<menuItemType> &menuItems);
void menuMain();
void printCheck(vector<menuItemType> &selectedItems);
void getData(vector<menuItemType> &menuList, vector<menuItemType> &customerOrder);