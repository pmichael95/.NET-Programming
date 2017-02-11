#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

Person& Person::operator=(const Person& rtSide){
	return Person(rtSide);
}

Person::Person(){
	this->name = "";
}

Person::Person(string theName){
	this->name = theName;
}

Person::Person(const Person& pers){
	this->name = pers.name;
}

string Person::getName(){
	return this->name;
}

void Person::setName(string name){
	this->name = name;
}