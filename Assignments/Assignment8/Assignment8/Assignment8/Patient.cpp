#include "Patient.h"
#include "Person.h"
#include "Doctor.h"
#include <iostream>
#include <string>
using namespace std;

Patient::Patient(){
	this->name = "";
}

Patient::Patient(string name){
	this->name = name;
}

Patient::Patient(Doctor phys){
	this->physician = phys;
	this->setName("");
}

Patient::Patient(string name, Doctor phys){
	this->setName(name);
	this->physician = phys;
}

Patient::Patient(Patient& patient){
	this->setName(patient.getName());
	this->setDoctor(patient.getDoctor());
}


Doctor& Patient::getDoctor(){
	return this->physician;
}

void Patient::setDoctor(Doctor doc){
	this->physician = doc;
}

Patient& Patient::operator=(Patient& patient){
	return Patient(patient);
}
