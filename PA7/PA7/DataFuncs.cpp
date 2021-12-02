#include "Data.hpp"

Data::Data(int trecordNum, int tid, std::string tname, std::string temail, std::string tunits, std::string tprogram, std::string tlevel, int tabsenceNum) {
	recordNum = trecordNum;
	id = tid;
	name = tname;
	email = temail;
	units = tunits;
	program = tprogram;
	level = tlevel;
	absenceNum = tabsenceNum;
	absenceDates;
}

Data::Data(Data& cData) {
	recordNum = cData.getRecordNum();
	id = cData.getId();
	name = cData.getName();
	email = cData.getEmail();
	units = cData.getUnits();
	program = cData.getProgram();
	level = cData.getLevel();
	absenceNum = cData.getAbsenceNum();
	absenceDates = cData.getAbsenceDates();
}

int Data::getRecordNum() {
	return recordNum;
}

int Data::getId() {
	return id;
}

std::string Data::getName() {
	return name;
}

std::string Data::getEmail() {
	return email;
}

std::string Data::getUnits() {
	return units;
}

std::string Data::getProgram() {
	return program;
}

std::string Data::getLevel() {
	return level;
}

int Data::getAbsenceNum() {
	return absenceNum;
}

Stack Data::getAbsenceDates() {
	return absenceDates;
}

void Data::display() {
	std::cout << "(" << getRecordNum() << ") ID:" << getId() << " Name:" << getName();
	std::cout << " Email:" << getEmail() << " Units:" << getUnits() << " Program:" << getProgram();
	std::cout << " level:" << getLevel() << " Absences:" << getAbsenceNum() << " AbsenceList:" << getAbsenceDates().getStack() << "\n";
}

void Data::incrementAbsence() {
	time_t t = time(0);
	struct tm* now = localtime(&t);
	std::string total;
	total += std::to_string(now->tm_year + 1900);
	total += "-";
	total += std::to_string(now->tm_mon + 1);
	total += "-";
	total += std::to_string(now->tm_mday);

	absenceNum++;
	absenceDates.push(total);
}