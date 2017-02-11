/**
* Assignment 6 CPP File
* By Philip Michael
* To Ms. Cornelia Badea Chirita
* .Net Programming
*/
#include <iostream>
#include <string>
using namespace std;

class Student{
public:
	Student() {
		name = "";
		numClasses = 0;
	}
	Student(string nm, int classes){
		name = nm;
		numClasses = classes;
	}
	void setName( string nm ) { name = nm; }
	void setNumClasses( int classes ) { numClasses = classes; }
	string getName() { return name; }
	int getNumClasses() { return numClasses; }
	void getInput();
	void outputList();
	void resetListsAndClasses();
	Student operator=(Student& stud);
	~Student() { delete [] classList; } //Destructor
private:
	string name;
	int numClasses;
	string classList[5];
};

int main(){
	Student stud;
	stud.setName("Jack");
	stud.setNumClasses(5);
	stud.getInput();
	stud.outputList();
	Student stud2 = stud;
	stud2.outputList();
	return 0;
}

void Student::getInput(){
	//Fills input from user to array
	cout << "Enter names of your classes." << endl;
	//----HERE GET INPUT FOR THE STRING----//
	for( int i=0; i<numClasses-1;i++){
		cout << "\nEnter for class #" << i+1 << endl;
		cin >> classList[i];
		classList[i] += "\n";
	}
	cin.ignore();
	//outputList();
}

void Student::outputList(){
	for( int i=0; i<numClasses-1; i++){
		cout << classList[i];
	}
}

void Student::resetListsAndClasses(){
	for( int i=0; i<numClasses;i++){
		classList[i] = "";
	}
	name = "";
	numClasses = 0;
}

Student Student::operator=(Student& stud){
	//Copy constructor
	Student studcpy;
	studcpy.setName(stud.getName());
	studcpy.setNumClasses(stud.getNumClasses());
	for( int i=0; i<stud.getNumClasses();i++){
		studcpy.classList[i] = stud.classList[i];
	}

	return studcpy;
}