#pragma once
#include <iostream>
#include <vector>
#include "Student.h"
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>

class StudentDatabase { //StudentDatabase
private:
	//Data members
	std::vector<Student> m_studentrecord;

public:
	//Constructor
	StudentDatabase(void);

	//Member functions
	void ReadFromFile(void);
	void MakeAnEntry(const Student& st);
	void ShowAll(void) const;
	void RemoveAnEntry(const int& Index);
	void ModifyData(const int& VecIndex, const int& Subject, const int& NewMarks);
	void Sort(const int& Choice);
	void WriteToFile(const int&) const;
	void SaveAll(void);

	int Size(void) const;
	int GetID(const int& Index) const;

	//Destructor
	~StudentDatabase(void);
};