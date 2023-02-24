#pragma once
#include "StudentDatabase.h"

class UserInterface{
public:
	//Member functions
	void UIDisplay() const;
	int  UIChoice() const;
	void UISetID(Student& st, const StudentDatabase& SD) const;
	void UISetName(Student& st) const;
	void UISetEnglishMarks(Student& st) const;
	void UISetMathMarks(Student& st) const;
	void UISetScienceMarks(Student& st) const;
	void UISetHistoryMarks(Student& st) const;
	void UISetGeographyMarks(Student& st) const;

	void UIColumnsForSorting() const;
	void UIColumnsForMarksUpdate() const;
	void UIDisplaySavedSuccessfully() const;

	int UIReadAndValidateRowNumber(const StudentDatabase& SD) const;
	int UIReadAndValidateSubjectColumnNumber() const;
	int UIReadAndValidateSortColumnNumber() const;
	int UIReadAndValidateMarks() const;

	int Size(const StudentDatabase&) const;
};