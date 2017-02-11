//MyInteger class for Assignment5
//By Philip Michael
//Presented to Cornelia Badea Chirita

#include <iostream>
#include <string>
using namespace std;

class MyInteger{
public:
	MyInteger();
	MyInteger( int n );
	int getNum() { return num; }
	void setNum( int n ) { num = n; }
	int operator []( int i );
private:
	int num;
};

MyInteger::MyInteger(){
	num = 0;
}

MyInteger::MyInteger( int  n ){
	num = n;
}

int MyInteger::operator[]( int i ){
	char buffer[33];
	string number = itoa(num,buffer,10);
	char n = number.at(i);
	int intNum = n - 48;
	return intNum;
}