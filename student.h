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
	Student(); //Parameterless constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, double days[], DegreeProgram degreeProgram);
	~Student();  //Optional. Gets rid of anything created dynamically, which in this case is nothing, but good habit.


	//Getters
	string getID();
	string getFirst();
	string getLast();
	string getEmailAddress();
	int getaAge();
	const double* getDays();
	DegreeProgram getDegreeProgram();


	//Setters
	void setID(string ID);
	void setFirst(string first);
	void setLast(string last);
	void setEmail(string email);
	void setaAge(int age);
	void setDays(const double days[]);
	void setDegreeProgram(DegreeProgram degProg);

	static void printHeader();

	void print();
};
	
