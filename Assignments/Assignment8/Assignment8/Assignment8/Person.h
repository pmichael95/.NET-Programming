#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

class Person{
public:
	Person();
	Person(string theName);
	Person(const Person& pers);
	string getName();
	void setName(string name);
	Person& operator=(const Person& rtSide);
protected:
	string name;
};

#endif