//Assignment 1: Which Day Was It?
//Programmed by Philip Michael

#include <iostream>
using namespace std;

bool isLeapYear( int year ){
	//Check if it's a leap year
	return ( (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0) );
}

int getCenturyValue( int year ){
	//Assuming we're still in 4 digit years
	//Get the first two digits and get the century value
	int firstTwo = (year/100) % 4;
	return (3 - firstTwo) * 2;
}

int getYearValue( int year ){
	//Get a value based on years since the beginning of the century
	int lastTwo = year % 100;
	int yearVal = lastTwo / 4;
	return lastTwo + yearVal;
}

int getMonthValue( int month, int year ){
	int mVal = 0;
	if( month == 1 ){
		if( isLeapYear(year) )
			mVal = 6;
		else
			mVal = 0;
	}
	else if( month == 2 ){
		if( isLeapYear(year) )
			mVal = 2;
		else
			mVal = 3;
	}
	else if( month == 3){
		mVal = 3;
	}
	else if( month == 4){
		mVal = 6;
	}
	else if( month == 5){
		mVal = 1;
	}
	else if( month == 6){
		mVal = 4;
	}
	else if( month == 7){
		mVal = 6;
	}
	else if( month == 8){
		mVal = 2;
	}
	else if( month == 9){
		mVal = 5;
	}
	else if( month == 10){
		mVal = 0;
	}
	else if( month == 11){
		mVal = 3;
	}
	else{
		mVal = 5;
	}

	return mVal;
}

int main(){
	int day, month, year = 0;
	cout << "Enter a date (dd mm yyyy):";
	cin >> day >> month >> year;
	cout << "Day is: " << day;
	cout << "\nMonth is: " << month;
	cout << "\nYear is: " << year;

	int sum = day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year);
	cout << "\nMonth value is: " << getMonthValue(month, year);
	cout << "\nYear value is: " << getYearValue(year);
	cout << "\nCentury value is: " << getCenturyValue(year);
	int remainder = sum % 7;
	cout << "\nRemainder is:" << remainder;

	switch(remainder){
	case 0: 
		cout << "\nThe day is Sunday.";
		break;
	case 1:
		cout << "\nThe day is Monday.";
		break;
	case 2:
		cout << "\nThe day is Tuesday.";
		break;
	case 3:
		cout << "\nThe day is Wednesday.";
		break;
	case 4:
		cout << "\nThe day is Thursday.";
		break;
	case 5:
		cout << "\nThe day is Friday.";
		break;
	case 6:
		cout << "\nThe day is Saturday.";
		break;
	default:
		cout << "\nUnexpected error. Please try again later.";
		break;
	}
}
