/* Assignment 4 cpp file
Temperature conversion
By Philip Michael
Presented to Ms. Cornelia Badea Chirita */

#include <iostream>
using namespace std;

class Temperature{
public:
	Temperature();
	void setTempKelvin(double kelvin ) {
		kelv = kelvin;
		cels = kelvin - 273.15;
		fah = ( cels + 32 ) * (5/9);
	}
	void setTempFahrenheit(double fahrenheit ) {
		fah = fahrenheit;
		cels = (5/9) * (fah - 32);
		kelv = cels + 273.15;
	}
	void setTempCelsius(double celsius ) {
		cels = celsius;
		fah = ( cels + 32 ) * (5/9);
		kelv = cels + 273.15;
	}
	//----Overloaded operators----//
	friend bool operator ==(const Temperature temp1, const Temperature temp2);
	friend ostream& operator <<(ostream& outputStream, Temperature& temp);
	friend istream& operator >>(istream& inputStream, Temperature& temp);
	double getKelvin() const { return kelv; }
	double getCelsius() const { return cels; }
	double getFahrenheit() const { return fah; }
private:
	double kelv;
	double cels;
	double fah;
};

int main(){
	//Tests the operators.
	Temperature* temp = new Temperature(); //Create a new Temperature object by calling the default constructor
	Temperature* temp2 = new Temperature(); //Other temperature to test with
	//cin >> temp; isn't working?
	cout << temp;
	cout << (temp == temp2);
	cout << "Enter celsius temperature." << endl;
	cin >> (temp2);


	return 0;
}

Temperature::Temperature(){
	//Default constructor
	cels = 0;
	kelv = 273.15;
	fah = 32;
}

bool operator ==(const Temperature temp1, const Temperature temp2){
	if ( temp1.getKelvin() == temp2.getKelvin() && temp1.getCelsius() == temp2.getCelsius() && temp1.getFahrenheit() == temp2.getFahrenheit() ){
		return true;
	}
	else{
		return false;
	}
}

ostream& operator <<(ostream& outputStream, const Temperature& temp){
	outputStream << "Temperature in Celsius: " << temp.getCelsius() << endl;
	outputStream << "Temperature in Kelvin: " << temp.getKelvin() << endl;
	outputStream << "Temperature in Fahrenheit: " << temp.getFahrenheit() << endl;
	return outputStream;
}

istream& operator >>(istream& inputStream, Temperature& temp){
	double celsius;
	inputStream >> celsius;
	temp.setTempCelsius(celsius);
	return inputStream;
}