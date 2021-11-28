#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h" 

using std::string;
using std::cout;
using std::endl;

class Student
{
public:
	const static int numDaysSize = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	double days[numDaysSize];
	DegreeProgram degreeProgram;

public:
	Student(); //Empty constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, double days[], DegreeProgram degreeProgram);
	~Student();  //Optional. Gets rid of anything created dynamically, which in this case is nothing, but good habit.


	//Getters
	string getID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	const double* getDays();
	DegreeProgram getDegreeProgram();


	//Setters
	void setID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDays(const double days[]);
	void setDegreeProgram(DegreeProgram degProg);

	static void printHeader();

	void print(); //paricular related
};
	
