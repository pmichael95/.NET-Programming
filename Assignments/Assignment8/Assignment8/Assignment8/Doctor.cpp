#include "Doctor.h"
#include <iostream>
#include <string>
using namespace std;

Doctor::Doctor(){
	this->specialty = "";
	this->visitFee = "0";
}

Doctor::Doctor(string s, string f){
	this->specialty = s;
	this->visitFee = f;
}

Doctor::Doctor(Doctor& doc){
	this->setFee(doc.getFee());
	this->setSpecialty(doc.getSpecialty());
}

string Doctor::getSpecialty(){
	return this->specialty;
}

string Doctor::getFee(){
	return this->visitFee;
}

void Doctor::setFee(string f){
	this->visitFee = f;
}

void Doctor::setSpecialty(string s){
	this->specialty = s;
}

Doctor& Doctor::operator=(Doctor& doc){
	return Doctor(doc);
}