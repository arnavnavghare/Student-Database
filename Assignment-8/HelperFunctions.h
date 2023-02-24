#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

//--------------------------------------------------------------------------------

enum COLUMNNAME { Id = 1, English, Math, Science, History, Geography, Percentage };

//--------------------------------------------------------------------------------

const float CalculatePercent(const int &marks1, const int &marks2, const int &marks3, const int &marks4, const int &marks5);
const std::string EvaluateGrade(const float& percentage);

//--------------------------------------------------------------------------------

int  CompatibleInput(const std::string& Str, bool (*ptr) (std::string Str));
int  CompatibleInput(const std::string& Str, bool (*ptr) (std::string Str, int Size), const int& Size);
int  CompatibleInput(const std::string& Str, bool (*ptr) (std::string Str, int* arr, int Size), int* arr, const int& Size);
bool ChoiceInputCheck(const std::string Str);
bool IdInputCheck(const std::string Str, int* arr, int size);
bool MarksInputCheck(const std::string Str);
bool RowInputCheck(const std::string Str, int Size);
bool MarksColumnInputCheck(const std::string Str);
bool SortColumnInputCheck(const std::string Str);

//--------------------------------------------------------------------------------

bool CompareById(Student& A, Student& B);
bool CompareByEnglishMarks(Student& A, Student& B);
bool CompareByMathMarks(Student& A, Student& B);
bool CompareByScienceMarks(Student& A, Student& B);
bool CompareByHistoryMarks(Student& A, Student& B);
bool CompareByGeographyMarks(Student& A, Student& B);
bool CompareByPercentage(Student& A, Student& B);

//--------------------------------------------------------------------------------