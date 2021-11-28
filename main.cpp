#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
#include "roster.h"


using std::string;
using std::cout;
using std::endl;

int main()
{
const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	 "A5,Cora,Worley,cworl30@wgu.edu,37,28,29,30,SOFTWARE" };

const int numStuds = 5;

std::cout << "Scripting & Programming Applications, C867" << std::endl;
std::cout << "C++" << std::endl;
std::cout << "Cora Worley - 007444954" << std::endl << std::endl << std::endl << std::endl;


ClassRoster classRoster;
for (int i = 0; i < numDays; i++) classRoster.parse3(studentData[i]);
cout << "All students:" << endl;
classRoster.printAll();
 
//Related to degreePrograms
for (int i = 0; i < 3; i++)
 { 
	cout << "Students by degree program:" << degreeProgramStrings[i] << endl;
	classRoster.printByDegreeProgram((DegreeProgram)i);
 }

 cout << "Students with invalid IDs:" << endl;
 classRoster.printInvalidIDs();

 cout << "Average days: " << endl;
 for (int i = 0;  i < numDays; i++) classRoster.printAverageDays(classRoster.getStudents()[i]->getID());

 cout << "Removing student A1:" << endl;
 classRoster.removeStudentByID("A1");
 system("pause");
 cout << "Removed.";
 return 0;


