#pragma once
#include <iostream>
#include <string>
#include"Fruit.h";

using std::cout;
using std::cin;
using std::endl;
using std::string;

std::ostream& operator<<(std::ostream &out, fruit myFruit) {
	out << "name: " << myFruit.name << endl;
	out << "colour: " << myFruit.colour << endl;
	out << "fat: " << myFruit.fat << endl;
	out << "carbs: " << myFruit.carbs << endl;
	out << "sugar: " << myFruit.sugar << endl;
	return out;
}

void print(const fruit &myFruit) {
	cout << "name: " << myFruit.name << endl;
	cout << "colour: " << myFruit.colour << endl;
	cout << "fat: " << myFruit.fat << endl;
	cout << "carbs: " << myFruit.carbs << endl;
	cout << "sugar: " << myFruit.sugar << endl;
}

void fruitMain() {
	fruit myFruit;
	cout << "name fruit:" << endl;
	getline(cin, myFruit.name);
	cout << "color" << endl;
	getline(cin, myFruit.colour);
	cout << "fat: " << endl;
	cin >> myFruit.fat;
	cout << "carbs: " << endl;
	cin >> myFruit.carbs;
	cout << "sugar: " << endl;
	cin >> myFruit.sugar;

	//print(myFruit);
	cout << myFruit;

}
