#pragma once
#include<string>
using std::string;

struct fruit {
	string name;
	string colour;
	int fat;
	int carbs;
	int sugar;


};

std::ostream& operator<<(std::ostream &out, fruit myFruit);
void print(const fruit &myFruit);
void fruitMain();