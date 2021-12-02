#include "Stack.hpp"

class Data {
public:
	Data(int trecordNum = 0, int tid = 0, std::string tname = "", std::string temail = "", std::string tunits = "", std::string tprogram = "", std::string tlevel = "", int tabsenceNum = 0);
	Data(Data& cData);

	int getRecordNum();
	int getId();
	std::string getName();
	std::string getEmail();
	std::string getUnits();
	std::string getProgram();
	std::string getLevel();
	int getAbsenceNum();
	Stack getAbsenceDates();

	void display();
	void incrementAbsence();
private:
	int recordNum;
	int id;
	std::string name;
	std::string email;
	std::string units;
	std::string program;
	std::string level;

	int absenceNum;
	Stack absenceDates;
};