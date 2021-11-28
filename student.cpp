#include "student.h"

//Parameterless constructor
Student::Student()
{
this->studentID = "";
this->firstName = "";
this->lastName = "";
this->emailAddress = "";
this->age = age;  //Is an int set to an empty string like (this->age = ""?) Or do I do this? If not either, what do I do?
for (int i = 0; i < numDaysSize; i++) this->days[i] = 0;
this->degreeProgram = DegreeProgram::SECURITY;

//Why is the first item below saying "type name not allowed?" and "expected a ")"? It's no different than the others and I have seen examples of the same as I how I have typed it in Github.
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, double days[], DegreeType degreeType) 
//Full constructor
{
  this->studentID = studentID;
  this->firstName = firstName;
  this->lastName = lastName;
  this->emailAddress = emailAddress;
  this->age = age;  //Again not 100% sure if this works the same for an int (See line 12)
  for (int i = 0; i < numDaysSize; i++) this->days[i] = days[i];
  this->DegreeType = degreeType;
}

 //Would be destructor if Student created anything dynamically
 Student::~Student() {}

//Getters
string Student::getID() {return this->studentID; }
string Student::getFirstName() {return this->firstName; }
string Student::getLastName() {return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
const double* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeProgram { return this degreeProgram;

//Setters
void Student::setID(string ID) {this->studentID = ID; }
void Student::setFirstName(String firstName) {this->firstName = firstName; }
void Student::setLastName(String lastName) {this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(const double days[])
{
	for (int i = 0; i < numDaysSize; i++) this->days[i] = days[i];
}

//Setters for Degree Type 
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

//Printing methods
void Student::printHeader()
{
	cout << "ID: ";
	cout << "First name: ";
	cout << "Last name: ";
	cout << "Email address: ";
	cout << "Age: ";
	cout << "Days1: ";
	cout << "Days2: ";
	cout << "Days3: ";
	cout << "Degree: ";
	cout << endl;
}

//For tab seperation 
void Student::print() 
{
	cout << this->studentID << '\t';
	cout << this->firstName << '\t';
	cout << this->lastName << '\t';
	cout << this->emailAddress << '\t';
	cout << this->age << '\t';
	cout << this->days[0] << '\t';
	cout << this->days[1] << '\t';
	cout << this->days[2] << '\t';
	cout << degreeProgramStrings[(int)this->degreeProgram];
	cout << endl;



void Student::setDays(const double days[])
{
	for (int i = 0; i < numDaysSize; i++) this->days[i] = days[i];
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {this->degreeProgram = degreeProgram;}
