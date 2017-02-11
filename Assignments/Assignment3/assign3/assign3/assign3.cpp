//Assignment 3 - .NET Programming
//Philip Michael 1279765

#include <iostream>
#include <string>
using namespace std;

class zipCode{
public:
	zipCode(int code); //Constructor for passing in the zip code
	zipCode(string code); //Constructor for passing in the bar code
	string encode(); //Encode with the bar code
	int decode(); //Decode with the zip code
	void setCode(string barcode); //Set the bar code again

private:
	int zip;
	string barCode;
	int digits[5]; //The ZIP code which is added from decode 0->4 (5 digits)
};

int main(){
	int zipNum = 0;
	string barcode = "";
	int zipGiven[5];

	cout << "Enter the first set of 5 digits: ";
	cin >> barcode;
	zipCode zipObj(barcode);
	zipGiven[0] = zipObj.decode();

	cout << "\nEnter the second set of 5 digits: ";
	cin >> barcode;
	zipObj.setCode(barcode);
	zipGiven[1] = zipObj.decode();

	cout << "\nEnter the third set of 5 digits: ";
	cin >> barcode;
	zipObj.setCode(barcode);
	zipGiven[2] = zipObj.decode();

	cout << "\nEnter the fourth set of 5 digits: ";
	cin >> barcode;
	zipObj.setCode(barcode);
	zipGiven[3] = zipObj.decode();

	cout << "\nEnter the fifth set of 5 digits: ";
	cin >> barcode;
	zipObj.setCode(barcode);
	zipGiven[4] = zipObj.decode();

	cout << "\nPrinting the zip code." << endl;
	for( int i=0; i<5; i++){
		cout << zipGiven[i];
	}

	cout << "Enter a zip code digit.";
	cin >> zipNum;
	zipCode encodeObj(zipNum);
	cout << "Got: " << encodeObj.encode();


	return 0;
}

zipCode::zipCode(int code): zip(code){}
zipCode::zipCode(string code): barCode(code){}
string zipCode::encode(){
	//Work with the int (zip) to return a string relating to the associated 5 digit
	//bar code consisting of 2 1's and 0's.
	string bc = "";
	switch( zip ){
	case 1:
		bc = "00011";
		break;
	case 3:
		bc = "00110";
		break;
	case 5:
		bc = "01010";
		break;
	case 6:
		bc = "01100";
		break;
	case 7:
		bc = "10001";
		break;
	case 8:
		bc = "10010";
		break;
	case 9:
		bc = "10100";
		break;
	default:
		//If it's a given 0
		bc = "00001";
		break;
	} //End switch statement
	return bc;
}

void zipCode::setCode(string barcode){
	barCode = barcode;
}

int zipCode::decode(){
	//Work with the string to return an int
	//String represents the bar code (1s and 0s)
	cout << "\nReached decode! Current bar code is:" << barCode << endl;

	int bcode = stoi(barCode);

	cout << "Converted barCode into int. Result is: " << bcode << endl;

	for( int i=4; i>=0; i--){
		digits[i] = bcode % 10;
		bcode /= 10;
		cout << "\nCode left: " << bcode;
	}

	cout << "\nPrinting digits." << endl;
	
	for( int k=0; k<5; k++){
		cout << digits[k];
	}

	/*---AT THIS POINT:
	*	We have in the digits[] array the whole 5 digits submitted by the user.
	*	Must now analyze each and associate a corresponding value.
	* -----*/

	//Loop and analyze the array for the index.
	int total = 0;
	for( int j=0; j<5; j++ ){
		switch( j ){
		case 0:
			if( digits[j] == 1 )
				total += 7;
			else
				total += 0;
			break;
		case 1:
			if( digits[j] == 1 )
				total += 4;
			else
				total += 0;
			break;
		case 2:
			if( digits[j] == 1 )
				total += 2;
			else
				total += 0;
			break;
		case 3:
			if( digits[j] == 1 )
				total += 1;
			else
				total += 0;
			break;
		case 4:
			total += 0;
			break;
		default:
			total += 0;
			break;
		} //End switch statement
	} //End FOR loop

	cout << "\nTotal is " << total;

	
	if( total >= 10 )
		return 0;
	else
		return total;

}