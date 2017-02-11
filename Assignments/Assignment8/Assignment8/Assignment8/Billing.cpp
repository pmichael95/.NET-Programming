#include "Billing.h"
#include "Patient.h"
#include "Doctor.h"
#include <iostream>
#include <string>
using namespace std;

Billing::Billing(){
	amountDue = 0;
}

Billing::Billing( Billing& bill){
	setAmountDue(bill.getAmountDue());
	setDoctor(bill.doc);
}

double Billing::getAmountDue(){
	return this->amountDue;
}

void Billing::setPatient(Patient pat){
	this->patient = pat;
}

void Billing::setAmountDue(double amount){
	this->amountDue = amount;
}

void Billing::setDoctor(Doctor doctor){
	this->doc = doctor;
}

Billing& Billing::operator=(Billing& bill){
	return Billing(bill);
}