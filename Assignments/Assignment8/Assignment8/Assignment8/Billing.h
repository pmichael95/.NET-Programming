#ifndef BILLING_H
#define BILLING_H
#include <iostream>
#include "Doctor.h"
#include "Patient.h"
using namespace std;

class Billing
{
public:
	Billing();
	Billing( Billing& bill);
	Doctor getDoctor();
	double getAmountDue();
	void setPatient(Patient pat );
	void setDoctor(Doctor doctor);
	void setAmountDue(double amount);
	Billing& operator = (Billing& bill);
private:
	Patient patient;
	Doctor doc;
	double amountDue;
};

#endif