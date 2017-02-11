// assign2.cpp by Philip Michael
// .Net Programming - PIN numbers
// Presented to Mrs. Cornelia Chirita

//For the sake of better presentation,
//several things will be outputted to the user.
//Random numbers, the encoded numbers, etc. will be outputted to help testing and grading.
	
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main(){
	//Variables holding PIN numbers.
	//Real pin is 12345 as stated below.
	int realPin[5] = {1,2,3,4,5};
	int encodedNumber[10];
	int input;
	int pinEntered[5];
	srand(time(NULL)); //Set a default seed for the rand() function.

	for( int i = 0; i < 10; i++){
		encodedNumber[i] = rand() % 3 +1;
		cout << "Random number is at: " << encodedNumber[i] << endl;
	}
	
	cout << "Numbers: 0123456789" << endl;
	cout << "Encoded: ";
	for( int k=0; k<10; k++){
		cout << encodedNumber[k];
	}
	cout << "\nEnter PIN:" << endl;
	cin >> input;
	for( int j=4; j>=0; j--){
		pinEntered[j] = input % 10;
		input /= 10;
	}

	int same = 0;
	for( int m=0; m < 5; m++){
		if( pinEntered[m] == encodedNumber[m+1] ){
			same++;
		}
	}
	
	//Check to see if it is correct or not.
	if( same == 5){
		cout << "Correct!" << endl;
	}
	else{
		cout << "Incorrect!" << endl;
	}

	return 0; //End the main.

}