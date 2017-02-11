#ifndef PATIENT_H
#define PATIENT_H
#include "Person.h"
#include "Doctor.h"
#include <iostream>
#include <string>
using namespace std;

class Patient : public Person 
{
public:
	Patient();
	Patient( string name );
	Patient( Doctor phys );
	Patient( string name, Doctor phys);
	Patient( Patient& patient);
	Doctor& getDoctor();
	void setDoctor(Doctor doc);
	Patient& operator = (Patient& patient);
private:
	Doctor physician;
};

#endif