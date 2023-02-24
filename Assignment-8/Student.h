#pragma once
#include <string>

class Student {
private:
	//Data members
	std::string m_name, m_grade;
	int m_id, m_englishmarks, m_mathmarks, m_sciencemarks, m_historymarks, m_geographymarks;
	float m_percentage;

public:
	//Constructor
	Student() {};
	Student(const int id, const std::string& name, int englishmarks, int mathmarks, int sciencemarks, int historymarks, int geographymarks);

	//Member functions
	const int GetId() const;
	const std::string& GetName()const;
	int GetEnglishMarks() const;
	int GetMathMarks() const;
	int GetScienceMarks() const;
	int GetHistoryMarks() const;
	int GetGeographyMarks() const;
	float GetPercentage() const;
	std::string GetGrade() const;

	void SetID(const int &ID);
	void SetName(const std::string &st);
	void SetEnglishMarks(const int &M);
	void SetMathMarks(const int &M);
	void SetScienceMarks(const int &M);
	void SetHistoryMarks(const int &M);
	void SetGeographyMarks(const int &M);

	//Friends
	friend class StudentDatabase;

	//Destructor
	~Student(void);
};