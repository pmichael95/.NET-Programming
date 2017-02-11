#ifndef DOCTOR_H
#define DOCTOR_H
#include <iostream>
#include <string>
using namespace std;

class Doctor
{
public:
	Doctor();
	Doctor(string s, string f );
	Doctor(Doctor& doc);
	string getSpecialty();
	string getFee();
	void setFee(string f);
	void setSpecialty( string s );
	Doctor& operator =(Doctor& doc);
private:
	string specialty;
	string visitFee; 
};

#endif