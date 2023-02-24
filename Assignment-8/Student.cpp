#include "StdAfx.h"
#include "Student.h"
#include "HelperFunctions.h"

//--------------------------------------------------------------------------------

Student::Student(const int id, const std::string& name, int englishmarks, int mathmarks, int sciencemarks, int historymarks, int geographymarks) {
	m_id = id;
	m_name = name;
	m_englishmarks = englishmarks;
	m_mathmarks = mathmarks;
	m_sciencemarks = sciencemarks;
	m_historymarks = historymarks;
	m_geographymarks = geographymarks;
	m_percentage = CalculatePercent(m_englishmarks, m_mathmarks, m_sciencemarks, m_historymarks, m_geographymarks);
	m_grade = EvaluateGrade(m_percentage);
}

//--------------------------------------------------------------------------------

const int Student::GetId() const {
	return Student::m_id;
}

//--------------------------------------------------------------------------------

const std::string& Student::GetName() const {
	return Student::m_name;
}

//--------------------------------------------------------------------------------

int Student::GetEnglishMarks() const {
	return Student::m_englishmarks;
}

//--------------------------------------------------------------------------------

int Student::GetMathMarks() const {
	return Student::m_mathmarks;
}

//--------------------------------------------------------------------------------

int Student::GetScienceMarks() const {
	return Student::m_sciencemarks;
}

//--------------------------------------------------------------------------------

int Student::GetHistoryMarks() const {
	return Student::m_historymarks;
}

//--------------------------------------------------------------------------------

int Student::GetGeographyMarks() const {
	return Student::m_geographymarks;
}

//--------------------------------------------------------------------------------

float Student::GetPercentage() const {
	return Student::m_percentage;
}

//--------------------------------------------------------------------------------

std::string Student::GetGrade() const {
	return Student::m_grade;
}

//--------------------------------------------------------------------------------

void Student::SetID(const int &ID) {
	Student::m_id = ID;
}

//--------------------------------------------------------------------------------

void Student::SetName(const std::string& st) {
	Student::m_name = st;
}

//--------------------------------------------------------------------------------

void Student::SetEnglishMarks(const int &M) {
	Student::m_englishmarks = M;
}

//--------------------------------------------------------------------------------

void Student::SetMathMarks(const int &M) {
	Student::m_mathmarks = M;
}

//--------------------------------------------------------------------------------

void Student::SetScienceMarks(const int &M) {
	Student::m_sciencemarks = M;
}

//--------------------------------------------------------------------------------

void Student::SetHistoryMarks(const int &M) {
	Student::m_historymarks = M;
}

//--------------------------------------------------------------------------------

void Student::SetGeographyMarks(const int &M) {
	Student::m_geographymarks = M;
}

//--------------------------------------------------------------------------------

Student::~Student(void) {
}

//--------------------------------------------------------------------------------