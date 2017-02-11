/*
Assignment 7 file
by Philip Michael
presented to Ms. Cornelia Badea Chirita
*/
#include <iostream>
#include <string>
using namespace std;

class DynamicStringArray{
private:
	string* dynamicArray;
	int size;
public:
	DynamicStringArray() {
		dynamicArray = NULL;
		size = 0;
	}
	int getSize() { return size; }
	void addEntry( string input );
	bool deleteEntry( string input );
	string getEntry( int index );
	DynamicStringArray& operator =( const DynamicStringArray& ar );
	~DynamicStringArray() { delete [] dynamicArray; }
};

int main(){
	DynamicStringArray str;
	string entry = "ok";
	string entry2 = "oh";
	str.addEntry(entry);
	cout << str.getEntry(0) << endl;
	str.addEntry(entry2);
	cout << str.deleteEntry(entry);
	cout << str.getEntry(0) << endl;
	/*DynamicStringArray ar = str;
	cout << "ar's size is: " << ar.getSize() << endl;
	cout << ar.getEntry(0) << endl;*/
	cout << "Done.";
	return 0;
}

string DynamicStringArray::getEntry( int index ){
	if( index <= getSize() ){
		return dynamicArray[index];
	}
	else{
		return NULL;
	}
}

void DynamicStringArray::addEntry( string input ){
	int newSize = size+1;
	string* newStr;
	newStr = new string[newSize];
	for( int i=0; i < getSize(); i++ ){
		newStr[i] = dynamicArray[i];
	}
	newStr[newSize-1] = input;
	delete [] dynamicArray;
	size++;
	dynamicArray = newStr;
}

DynamicStringArray& DynamicStringArray::operator=( const DynamicStringArray& ar ){
	size = ar.size;
	dynamicArray = new string[size];
	for( int i=0; i<ar.size; i++ ){
		dynamicArray[i] = ar.dynamicArray[i];
	}
	return *this;
}

bool DynamicStringArray::deleteEntry( string input ){
	bool isInArray = false;
	int index = 0;
	for( int i=0; i<getSize(); i++ ){
		if( dynamicArray[i] == input ){
			isInArray = true;
			index = i;
		}
	}

	if( ! isInArray ){
		return false;
	}
	else{
		string* newStr;
		newStr = new string[getSize()-1];
		for( int i=0; i<getSize(); i++ ){
			if( i != index ){
				newStr[i] = dynamicArray[i];
			}
			else{
				newStr[i] = dynamicArray[i+1];
				i++;
			}
		}
		delete [] dynamicArray;
		dynamicArray = newStr;
	}
	return true;
}