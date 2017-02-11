#include "Patient.h"
#include "Person.h"
#include "Doctor.h"
#include "Billing.h"
#include <iostream>
#include <string>
using namespace std;


int main(){
	Patient p1;
	Patient p2;
	Doctor doc1("Childcare", "500");
	Doctor doc2("Birth", "1000");

	p1.setName("Jake");
	p1.setDoctor(doc1);
	p2.setName("Jenna");
	p2.setDoctor(doc2);
	
	Billing bill1;
	Billing bill2;
	
	bill1.setAmountDue(500);
	bill1.setDoctor(doc1);
	bill1.setPatient(p1);

	bill2.setAmountDue(1000);
	bill2.setDoctor(doc2);
	bill2.setPatient(p2);

	cout << bill1.getAmountDue() << endl;
	cout << bill2.getAmountDue() << endl;
}