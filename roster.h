#include "degree.h"
#include <vector> //Needed for one of the parsing routines, but not sure which one so when complete try with and without this to see if needed. 
#include "student.h"
#include "degree.h"

class ClassRoster
{
private:
	int lastIndex = -1;
	const static int numstuds = 5;
	//Array of pointers to students.
	Student* students[numStuds] = { nullptr, nullptr, nullptr, nullptr, nullptr }; //Why is numStuds not identified??

public:
	Student** getStudents();
	
	//Parsing methods. Probably only need to keep the once used.
	//void parse1(string row); //parses 1 row of long data at a time (classic)
	//void parse2(string row); //slightly diff than above
	void parse3(string row); 
	//void parse4(string row); //different still
	//void parse5(string row); //uses regex to split


	//More methods. (Are these Optional??)
	void add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, double sDay1, double sDay2, double sDay3, DegreeProgram degProg);
	void printAll();
	void printByID(string sID);
	void printByFirstName(string sFirstName);
	void printByLastName(string sLastName);
	void printByEmailAddress(string sEmail);
	void printByDegreeProgram(DegreeProgram degProg);
	void printInvalidIDs();
	void printAverageDays(string studentID);
	void removeStudentByID(string studentID);
	

	//Destuctor (not totally optonal bc things ARE created dynamically here)
	~ClassRoster();
};
