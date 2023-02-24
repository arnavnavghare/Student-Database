#include "StdAfx.h"
#include <string>
#include "UserInterface.h"
#include "HelperFunctions.h"

//--------------------------------------------------------------------------------

bool (*ptr1) (std::string str) = ChoiceInputCheck;
bool (*ptr2) (std::string str, int* arr, int Size) = IdInputCheck;
bool (*ptr3) (std::string str) = MarksInputCheck;
bool (*ptr4) (std::string str, int Size) = RowInputCheck;
bool (*ptr5) (std::string str) = MarksColumnInputCheck;
bool (*ptr6) (std::string str) = SortColumnInputCheck;

//--------------------------------------------------------------------------------

void UserInterface::UIDisplay() const{
	std::cout << std::setw(40) << std::endl << std::setw(40) <<"**********************  STUDENT DATA MANAGEMENT SYSTEM  ***********************"<< std::setw(40) << std::endl;
	std::cout << std::setw(57) << std::right << "------------------------------------" << std::endl;
	std::cout << std::setw(50) << std::right << "|	Show All Entry   -->  [1]	|"   << std::endl;
	std::cout << std::setw(50) << std::right << "|	Make New Entry   -->  [2]	|"   << std::endl;
	std::cout << std::setw(50) << std::right << "|	Modify Data      -->  [3]	|"   << std::endl;
	std::cout << std::setw(50) << std::right << "|	Remove An Entry  -->  [4]	|"   << std::endl;
	std::cout << std::setw(50) << std::right << "|	Sort Data        -->  [5]	|"   << std::endl;
	std::cout << std::setw(50) << std::right << "|	Save All         -->  [6]	|"   << std::endl;
	std::cout << std::setw(50) << std::right << "|	Exit             -->  [7]	|"   << std::endl;
	std::cout << std::setw(57) << "------------------------------------" << std::endl;
	std::cout << std::setw(40) << std::setw(40) <<"*******************************************************************************"<< std::endl;
}

//--------------------------------------------------------------------------------

int UserInterface::UIChoice() const{
	std::string str;
	int choice = 0;
	while (choice < 1 || choice > 7) {
		std::cout << "Please enter your choice  -->  ";
		getline(std::cin, str);
		if (CompatibleInput(str, ptr1) == -1) {
			std::cout << "Choose from above 1 to 7 options!" << std::endl << std::endl;
		}
		else {
			choice=(atoi(str.c_str()));
		}
	}
	return choice;
}

//--------------------------------------------------------------------------------

void UserInterface::UISetID(Student& st, const StudentDatabase& SD) const{
	int val = SD.Size();
	int* ArrayofID = NULL;
	ArrayofID = new int[val];
	for (int i = 0; i < SD.Size(); i++) {
		ArrayofID[i] = SD.GetID(i);
	}
	while (st.GetId() < 999 || st.GetId() > 9999) {
		std::string str;
		std::cout << "Enter ID : ";
		getline(std::cin, str);
		if (CompatibleInput(str, ptr2, ArrayofID, val) == -1) {
			std::cout << "Enter 4 Digit Unique Numeric ID!" << std::endl;
		}
		else {
			st.SetID(atoi(str.c_str()));
		}
	}
	delete[] ArrayofID;
	ArrayofID = NULL;
}

//--------------------------------------------------------------------------------

void UserInterface::UISetName(Student& st) const{
	std::cout << "Enter Name : ";
	std::string name;
	getline(std::cin, name);
	st.SetName(name);
}

//--------------------------------------------------------------------------------

void UserInterface::UISetEnglishMarks(Student& st) const{
	while (st.GetEnglishMarks() < 0 || st.GetEnglishMarks() > 100) {
		std::string str;
		std::cout << "Enter English Marks : ";
		getline(std::cin, str);
		if (CompatibleInput(str, ptr3) == -1) {
			std::cout << "Enter valid marks!" << std::endl << std::endl;
		}
		else {
			st.SetEnglishMarks(atoi(str.c_str()));
		}
	}
}

//--------------------------------------------------------------------------------

void UserInterface::UISetMathMarks(Student& st) const{
	while (st.GetMathMarks() < 0 || st.GetMathMarks() > 100) {
		std::string str;
		std::cout << "Enter Math Marks : ";
		getline(std::cin, str);
		if (CompatibleInput(str, ptr3) == -1) {
			std::cout << "Enter valid marks!" << std::endl << std::endl;
		}
		else {
			st.SetMathMarks(atoi(str.c_str()));
		}
	}
}

//--------------------------------------------------------------------------------

void UserInterface::UISetScienceMarks(Student& st) const{
	while (st.GetScienceMarks() < 0 || st.GetScienceMarks() > 100) {
		std::string str;
		std::cout << "Enter Science Marks : ";
		getline(std::cin, str);
		if (CompatibleInput(str, ptr3) == -1) {
			std::cout << "Enter valid marks!" << std::endl << std::endl;
		}
		else {
			st.SetScienceMarks(atoi(str.c_str()));
		}
	}
}

//--------------------------------------------------------------------------------

void UserInterface::UISetHistoryMarks(Student& st) const{
	while (st.GetHistoryMarks() < 0 || st.GetHistoryMarks() > 100) {
		std::string str;
		std::cout << "Enter History Marks : ";
		getline(std::cin, str);
		if (CompatibleInput(str, ptr3) == -1) {
			std::cout << "Enter valid marks!" << std::endl << std::endl;
		}
		else {
			st.SetHistoryMarks(atoi(str.c_str()));
		}
	}
}

//--------------------------------------------------------------------------------

void UserInterface::UISetGeographyMarks(Student& st) const{
	while (st.GetGeographyMarks() < 0 || st.GetGeographyMarks() > 100) {
		std::string str;
		std::cout << "Enter Geography Marks : ";
		getline(std::cin, str);
		if (CompatibleInput(str, ptr3) == -1) {
			std::cout << "Enter valid marks!" << std::endl << std::endl;
		}
		else {
			st.SetGeographyMarks(atoi(str.c_str()));
		}
	}
}

//--------------------------------------------------------------------------------

void UserInterface::UIColumnsForSorting() const{
	std::cout << "Sort by ID                -->    [1]" << std::endl;
	std::cout << "Sort by English Marks     -->    [2]" << std::endl;
	std::cout << "Sort by Math Marks        -->    [3]" << std::endl;
	std::cout << "Sort by Science Marks     -->    [4]" << std::endl;
	std::cout << "Sort by History Marks     -->    [5]" << std::endl;
	std::cout << "Sort by Geography Marks   -->    [6]" << std::endl;
	std::cout << "Sort by Percentage        -->    [7]" << std::endl << std::endl;
}

//--------------------------------------------------------------------------------

void UserInterface::UIColumnsForMarksUpdate() const{
	std::cout << "Sort by English Marks     -->    [1]" << std::endl;
	std::cout << "Sort by Math Marks        -->    [2]" << std::endl;
	std::cout << "Sort by Science Marks     -->    [3]" << std::endl;
	std::cout << "Sort by History Marks     -->    [4]" << std::endl;
	std::cout << "Sort by Geography Marks   -->    [5]" << std::endl << std::endl;
}

//--------------------------------------------------------------------------------

void UserInterface::UIDisplaySavedSuccessfully() const{
	std::cout << "Data Saved Successfully!" << std::endl << std::endl;
}

//--------------------------------------------------------------------------------

int UserInterface::UIReadAndValidateRowNumber(const StudentDatabase& SD) const{
	int Row = -1;
	int var = SD.Size();
	while (Row < 1 || Row > var) {
		std::string str;
		std::cout << "Enter Sr. No. : ";
		getline(std::cin, str);
		if (CompatibleInput(str, ptr4, var) == -1) {
			std::cout << "Choose from above data!" << std::endl << std::endl;
		}

		else {
			Row = atoi(str.c_str());
		}
	}
	return Row;
}

//--------------------------------------------------------------------------------

int UserInterface::UIReadAndValidateSubjectColumnNumber() const{
	int column = -1;
	while (column < 1 || column > 5) {
		std::string str;
		std::cout << "Enter Column Number : ";
		getline(std::cin, str);
		if (CompatibleInput(str, ptr5) == -1) {
			std::cout << "Choose from above 1 to 5 marks columns!" << std::endl << std::endl;
		}
		else {
			column = (atoi(str.c_str()));
		}
	}
	return ++column;
}

//--------------------------------------------------------------------------------

int UserInterface::UIReadAndValidateSortColumnNumber() const{
	int column = -1;
	while (column < 1 || column > 7) {
		std::string str;
		std::cout << "Enter Column Number : ";
		getline(std::cin, str);
		if (CompatibleInput(str, ptr6) == -1) {
			std::cout << "Choose from above 1 to 7 columns!" << std::endl << std::endl;
		}
		else {
			column = (atoi(str.c_str()));
		}
	}
	return column;
}

//--------------------------------------------------------------------------------

int UserInterface::UIReadAndValidateMarks() const{
	int Marks = -1;
	while (Marks < 0 || Marks > 100) {
		std::string str;
		std::cout << "Enter New Marks to Update: ";
		getline(std::cin, str);
		if (CompatibleInput(str, ptr3) == -1) {
			std::cout << "Enter valid marks!" << std::endl << std::endl;
		}
		else {
			Marks = (atoi(str.c_str()));
		}
	}
	return Marks;
}

//--------------------------------------------------------------------------------

int UserInterface::Size(const StudentDatabase& SD) const{
	return SD.Size();
}

//--------------------------------------------------------------------------------