//PrimeNumber class for Assignment 5
//By Philip Michael
//Presented to Cornelia Badea Chirita
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class PrimeNumber{
public:
	PrimeNumber() { prime = 2; }
	PrimeNumber( int num ) { prime = num; }
	int getNum() { return prime; }
	friend PrimeNumber operator ++( PrimeNumber& number );
	friend PrimeNumber operator --( PrimeNumber& number );
	void setPrime( int number ) { prime = number; }
	bool isPrime( int number);
private:
	int prime;
};

PrimeNumber operator++( PrimeNumber& number ){
	number.setPrime(number.getNum()+1);
	while( ! number.isPrime(number.getNum()) ){
		number.setPrime(number.getNum()+1);
	}
	return number.getNum();
}

PrimeNumber operator--( PrimeNumber& number){
	number.setPrime(number.getNum()-1);
	while( ! number.isPrime(number.getNum()) ){
		number.setPrime(number.getNum()-1);
	}
	return number.getNum();
}


bool PrimeNumber::isPrime( int number){
	bool isprime = true;
	for( int i=2; i<number; ++i){
		if( number % i == 0){
			isprime = false;
			break;
		}
	}

	return isprime;
}