#include <vector> //Needed for one of the parsing routines, but not sure which one so when complete try with and without this to see if needed. 
#include <sstream> //Needed for one of the parsing routines, but not sure which one so when complete try with and without this to see if needed. 
//#include <regex>  //optional? (Guessing so, if use regex parsing method prob)
#include "roster.h" 

using std::vector; //Needed for one of the parsing routines (See line 1).
using std::stringstream; //Needed for one of the parsing routines  (See line 2)
//using std::regex;  //Likely optional (See line 3)

//Do I really need this ClassRoster class twice? It is listed in both roster.CPP and roster.h in class sheet of what should be included, but seems redunant. 
class ClassRoster
{
private:
	int lastIndex = -1;
	const static int numstuds = 5;
	Student* students[numStuds] = { nullptr, nullptr, nullptr, nullptr, nullptr };

public:
	Student** getStudents();
	//Parsing methods
	void parse1(string row); //parses 1 row of long data at a time (classic)
	void parse2(string row); //slightly diff than above parsing routine
	void parse3(string row); //different parsing routine
	void parse4(string row); //different still parsing routine
	void parse5(string row); //uses regex to split parsing routine


	//More methods Optional??
	void add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, double sDay1, double sDay2, double sDay3, DegreeProgram degProg);
	void printAll();
	void printByDegreeProgram(DegreeProgram degProg);
	void printInvalidIDs();
	void printAverageDays(string studentID);
	void removeStudentByID(string studentID);

	//Destuctor (not as optonal bc things are created dynamically here)
	~ClassRoster();
}; 

Student** ClassRoster::getStudents()
{
return ClassRoster::students;
}



//Below are parsing methods learned in class video 8 beginning at around 2:34. Picked the one with the least amount of errors :) . Parse3. 

//Parsing method 1. Will remove if not used. 
/*void ClassRoster::parse1(string studentData)
{
cout << "Using parsing method 1\n"; //Optional?
ClassRoster degProgram = DegreeProgram::SOFTWARE;
if (studentData.back() == 'Y') degProgram = DegreeProgram::NETWORK;
else if (studentData.back() == 'N') degProgram = DegreeProgram::SECURITY;
int rhs = studentData.find(",");
string sID = studentData.substr(0, rhs);
int lhs = rhs + 1;
rhs = studentData.find(",", lhs);
string ttl = studentData.substr(lhs, rhs - lhs);
lhs = rhs + 1;
rhs = studentData.find(",", lhs);
string dir = studentData.substr(lhs, rhs - lhs);
double d[3]; //p
for (int i = 0; i < 3; i++)
{
lhs = rhs + 1;
rhs = studentData.find(",", lhs);
d[i] = stod(studentData.substr(lhs, rhs - lhs));
}
add(sID, ttl, dir, d[0], d[1], d[2], degProgram);
*/

//Parsing method 2. Will remove if not used. 
/*void ClassRoster::parse2(string row)
{
cout << "Using parsing method 2\n"; //Optional?
vector<string> result;
stringstream input(row);
while (inpiut.good())
{
	string token;
	getline(input, token, ',');
	result.push_back(token);
}
DegreeProgram degProgram = DegreeProgram::SOFTWARE;
if (row.back() == 'Y') degProgram = DegreeProgram::NETWORK;
if (row.back() == 'N') degProgram = DegreeProgram::SECURITY;

add(result.at(0), result.at(1), result.at(2), stod(result.at(3)), stod(result.at(4)), stod(result.at(5)), degProgram);
}
*/


//Parsing method 3 chosen. 
void ClassRoster::parse3(string items)
{
	cout << "Parsing method 3\n"; 
	DegreeProgram degProgram = DegreeProgram::SECURITY;
	if (items.back() == 'Y') degProgram = DegreeProgram::NETWORK;
	else if (items.back() == 'N') degProgram = DegreeProgram::SOFTWARE;
	string parsed[6]; 
	int rhs = 0;
	int lhs = 0;
	for (int i = 0; i < 6; i++)
	{
		rhs = items.find(",", lhs);
		parsed[i] = items.substr(lhs, rhs - lhs);
		lhs = rhs + 1;
	}

	add(parsed[0], parsed[1], parsed[2], parsed[3], stod(parsed[4]), stod(parsed[5]), degProgram);
	


//Parsing method 4. Will remove if not used. 
/*void ClassRoster::parse4(string row)
{
	cout << "Using parsing method 4\n"; //Optional?
	vector<string> tokens;
	size_t start;
	size_t end = 0;
	while ((start = row.find_first_not_of(',', end)) != string::npos)
	{
		end = row.find(',', start);
		tokens.push_back(row.substr(start, end - start));
	}
	DegreeProgram degProgram = DegreeProgram::SOFTWARE; //Default??
	switch (tokens.at(6).back())
	{
	case 'Y': degProgram = DegreeProgram::NETWORK; break;
	case 'N': degProgram = DegreeProgram::SECURITY; break;
	}
	add(tokens.at(0), tokens.at(1), tokens.at(2), stod(tokens.at(3)), stod(tokens.at(4)), stod(tokens.at(5)), degProgram);
	}
*/

//Parsing medod 5. Will remove if not used. 
/*
void ClassRoster::parse5(string row)
{
	cout << "Using parsing method 5\n"; //Optional?
	regex regex("\\,");
	std::vector<string> splitter(
		std::sregrex_token_iterator(row.begin(), row.end(), regex, -1), std::sregex_token_iterator()
 );

 DegreeProgram degProgram = DegreeProgram::SOFTWARE;
 if (splitter.at(6).back() =='Y') degProgram = DegreeProgram::NETWORK;
 if (splitter.at(6).back() == 'N') degProgram = DegreeProgram::SECURITY;
 add(splitter.at(0), splitter.at(1), splitter.at(2), stod(splitter.at(3)), stod(splitter.at(4)), stod(splitter.at(5)), degProgram);
 }

//Add method??
void ClassRoster::add(string degProgram, string firstName, string lastName, double days1, double days2, double days3, DegreeProgram degProgram) 
{
double numDaysArray[3] = { days1,days2,days3 };
students[++lastIndex] = new Student(studentID, firstName, lastName, numDaysArray, degType);
}
*/








//Remove Student by ID

void ClassRoster::removeStudentByID(string studentID)
{
	bool success = false;
	for (int = 0; i <=ClassRoster::lastIndex; i++)
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
	void ClassRoster::removeStudentByID(string studentID)
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
