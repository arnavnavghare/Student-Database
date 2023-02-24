#include "StdAfx.h"
#include "HelperFunctions.h"
#include "StudentDatabase.h"

//--------------------------------------------------------------------------------

const float CalculatePercent(const int &marks1, const int &marks2, const int &marks3, const int &marks4, const int &marks5){
	float avg;
	avg = (marks1 + marks2 + marks3 + marks4 + marks5) / 5.0;
	return avg;
}

//--------------------------------------------------------------------------------

const std::string EvaluateGrade(const float& percentage){
	std::string grade;
	if (percentage > 90) {
		grade = "A+";
	}
	else if (percentage > 80 && percentage <= 90) {
		grade = "A";
	}
	else if (percentage > 70 && percentage <= 80) {
		grade = "B+";
	}
	else if (percentage > 60 && percentage <= 70) {
		grade = "B";
	}
	else if (percentage > 50 && percentage <= 60) {
		grade = "C+";
	}
	else if (percentage > 40 && percentage <= 50) {
		grade = "C";
	}
	else {
		grade = "D";
	}
	return grade;
}

//--------------------------------------------------------------------------------

int CompatibleInput(const std::string& Str, bool (*ptr) (std::string Str)) {
	if (ptr(Str) == true) {
		int val = atoi(Str.c_str());
		return val;
	}
	else {
		return -1;
	}
}

//--------------------------------------------------------------------------------

int CompatibleInput(const std::string& Str, bool (*ptr) (std::string Str, int Size), const int& Size) {
	if (ptr(Str, Size) == true) {
		int val = atoi(Str.c_str());
		return val;
	}
	else {
		return -1;
	}
}

//--------------------------------------------------------------------------------

int CompatibleInput(const std::string& Str, bool (*ptr) (std::string Str, int* arr, int Size), int* arr, const int& Size) {
	if (ptr(Str, arr, Size) == true) {
		int var = atoi(Str.c_str());
		return var;
	}
	else {
		return -1;
	}
}

//--------------------------------------------------------------------------------

bool ChoiceInputCheck(std::string Str) {
	for (int i = 0; i < Str.length(); i++) {
		if (Str[i] < '1' || Str[i]>'7') {
			return false;
		}
	}
	if (atoi(Str.c_str()) >= 1 && atoi(Str.c_str()) <= 7) {
		return true;
	}
	else {
		return false;
	}
}

//--------------------------------------------------------------------------------

bool IdInputCheck(const std::string Str, int* arr, int Size ) {
	for (int i = 0; i < Str.length(); i++) {
		if (Str[i] < '0' || Str[i]>'9') {
			return false;
		}
	}
	if (atoi(Str.c_str()) >= 1000 && atoi(Str.c_str()) <= 9999) {
		for (int i = 0; i < Size; i++) {
			if (atoi(Str.c_str()) == arr[i]) {
				return false;
			}
		}
		return true;
		
	}
	else {
		return false;
	}
}

//--------------------------------------------------------------------------------

bool MarksInputCheck(const std::string Str) {
	for (int i = 0; i < Str.length(); i++) {
		if (Str[i] < '0' || Str[i]>'9') {
			return false;
		}
	}
	if (atoi(Str.c_str()) >= 0 && atoi(Str.c_str()) <= 100) {
		return true;
	}
	else {
		return false;
	}
}

//--------------------------------------------------------------------------------

bool RowInputCheck(const std::string Str, int Size) {
	for (int i = 0; i < Str.length(); i++) {
		if (Str[i] < '1' || Str[i]>'9') {
			return false;
		}
	}
	if (atoi(Str.c_str()) >= 1 && atoi(Str.c_str()) <= Size) {
		return true;
	}
	else {
		return false;
	}
}

//--------------------------------------------------------------------------------

bool MarksColumnInputCheck(const std::string Str) {
	for (int i = 0; i < Str.length(); i++) {
		if (Str[i] < '1' || Str[i]>'5') {
			return false;
		}
	}
	if (atoi(Str.c_str()) >= 1 && atoi(Str.c_str()) <= 5) {
		return true;
	}
	else {
		return false;
	}
}

//--------------------------------------------------------------------------------

bool SortColumnInputCheck(const std::string Str) {
	for (int i = 0; i < Str.length(); i++) {
		if (Str[i] < '1' || Str[i]>'7') {
			return false;
		}
	}
	if (atoi(Str.c_str()) >= 1 && atoi(Str.c_str()) <= 7) {
		return true;
	}
	else {
		return false;
	}
}

//--------------------------------------------------------------------------------

bool CompareById(Student& A, Student& B) {
	return(A.GetId() < B.GetId());
};

//-------------------------------------------------------------------------------

bool CompareByEnglishMarks(Student& A, Student& B) {
	return(A.GetEnglishMarks() > B.GetEnglishMarks());
};

//-------------------------------------------------------------------------------

bool CompareByMathMarks(Student& A, Student& B) {
	return(A.GetMathMarks() > B.GetMathMarks());
};

//-------------------------------------------------------------------------------

bool CompareByScienceMarks(Student& A, Student& B) {
	return(A.GetScienceMarks() > B.GetScienceMarks());
};

//-------------------------------------------------------------------------------

bool CompareByHistoryMarks(Student& A, Student& B) {
	return(A.GetHistoryMarks() > B.GetHistoryMarks());
};

//-------------------------------------------------------------------------------

bool CompareByGeographyMarks(Student& A, Student& B) {
	return(A.GetGeographyMarks() > B.GetGeographyMarks());
};

//-------------------------------------------------------------------------------

bool CompareByPercentage(Student& A, Student& B) {
	return(A.GetPercentage() > B.GetPercentage());
};

//-------------------------------------------------------------------------------