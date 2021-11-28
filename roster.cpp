#include "student.h"
#include <vector> //Needed for one of the parsing routines, but not sure which one so when complete try with and without this to see if needed. 
#include <sstream> //Needed for one of the parsing routines, but not sure which one so when complete try with and without this to see if needed.
#include "roster.h"
using std::stringstream; //Needed for one of the parsing routines  (See line 3)

Student** ClassRoster::getStudents()
{
return ClassRoster::students;
}

//Parsing method 3 chosen. 
void ClassRoster::parse3(string items)
{
	cout << "Parsing method 3\n";
	DegreeProgram degProgram = DegreeProgram::SECURITY;
	if (items.back() == 'K') degProgram = DegreeProgram::NETWORK;
	else if (items.back() == 'E') degProgram = DegreeProgram::SOFTWARE;
	string parsed[6];
	int rhs = 0;
	int lhs = 0;
	for (int i = 0; i < 6; i++)
	{
		rhs = items.find(",", lhs);
		parsed[i] = items.substr(lhs, rhs - lhs);
		lhs = rhs + 1;
	}
	add(parsed[0], parsed[1], parsed[2], parsed[3], stod(parsed[4]), stod(parsed[5]), degProgram);  //Why does it say "Too few arguments in a function call here?"
}


//Remove Student by ID
void ClassRoster::removeStudentByID(string studentID)
{
	bool success = false;
	for (int i = 0; i <=ClassRoster::lastIndex; i++)
	{
		if (students[i]->getID() == studentID)
		 {
			success = true;
			Student* temp = students[i];
			students[i] = students[numDays -1];
			students[numDays -1] = temp;
			ClassRoster::lastIndex--;
		}
	}
	if (success)
	{
		cout << "Student " << studentID << " removed." << endl;
		printAll();
	}
	else cout << "Student " << studentID << " could not find." << endl;
	}

ClassRoster::~ClassRoster()
{
	for (int i = 0; i < numDays; i++)
	 {
		cout << "Destructor called on " << students[i]->getID() << endl;
		delete students[i];
		students[i] = nullptr;
	 }
}



//Print
void ClassRoster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= ClassRoster::lastIndex; i++)
		ClassRoster::students[i]->print();
}

//Degree program pass
void ClassRoster::printByDegreeProgram(DegreeProgram degProgram)
{
	Student::printHeader();
	for (int i = 0; i <= ClassRoster::lastIndex; i++)
		if (ClassRoster::students[i]->getDegreeProgram() == degProgram) students[i]->print();
}

//Invalid IDs
void ClassRoster::printInvalidIDs()
{
	for (int i = 0; i <= ClassRoster::lastIndex; i++)
		{ 
		 string id = ClassRoster::getStudents()[i]->getID();
		 if (id.find(' ') != string::npos || id.find('.') == string::npos)
	     cout << id << " is invalid." << endl;
}



//Remove a student by ID
	void ClassRoster::removeStudentByID(string studentID)  //"May not be declared outside of it's class"?
	{
		bool success = false;
		for (int i = 0; i <= ClassRoster::lastIndex; i++)
		{
			if (students[i]->getID() == studentID)
			{
				success = true;
				Student* temp = students[i];
				students[i] = students[numDays - 1];
				students[numDays - 1] = temp;
				ClassRoster::lastIndex--;
			}
		}
		if (success)
		{
			cout << "Student " << studentID << " deleted." << endl;
			printAll();
		}
		else cout << "Student " << studentID << " can't be found." << endl;
	}

	ClassRoster::~ClassRoster()
	{
		for (int i = 0; i < numDays; i++)
		{
			cout << "Destructor called on " << students[i]->getID() << endl;
			delete students[i];
			students[i] = nullptr; //sets to null after deletion
		}
	}

	//Average days
	void ClassRoster::printAverageDays(string studentID)
	{
		//Find ID matches
		for (int i = 0; i <= ClassRoster::lastIndex; i++)
		{
			if (students[i]->getID() == = studentID) //If ID matches then can display average days 
			{
				cout << studentID << ":";
				cout << (students[i]->getDays()[0] +
					students[i]->getDays()[1] +
					students[i]->getDays()[2])
					/ 3.0 << endl;
			}
		}
	}
