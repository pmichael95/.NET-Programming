/*
Assignment 5 CPP file
Integers and Prime numbers
By Philip Michael
For Ms. Cornelia Badea Chirita
*/

#include <iostream>
#include "myInteger.h"
#include "PrimeNumber.h"
using namespace std;

int main(){
	//Test myInteger class
	cout << "\nTesting myInteger now..." << endl;
	MyInteger myInt(418);
	cout << "Expect 4, got: " << myInt[0] << "\nExpect 1, got: " << myInt[1] << "\nExpect 8, got: " << myInt[2] << endl;

	//Test PrimeNumber class
	cout << "\nTesting prime numbers now." << endl;
	PrimeNumber primeNum(5);
	cout << "Expect 5, got: " << primeNum.getNum() << endl;
	++primeNum;
	cout << "Expect 7, got: " << primeNum.getNum() << endl;
	--primeNum;
	cout << "Expect 5, got: " << primeNum.getNum() << endl;
	--primeNum;
	cout << "Expect 3, got: " << primeNum.getNum() << endl;
	++primeNum;
	cout << "Expect 5, got: " << primeNum.getNum() << endl;

	return 0;
}