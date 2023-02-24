#include "StdAfx.h"
#include "StudentDatabase.h"
#include "HelperFunctions.h"

//--------------------------------------------------------------------------------

StudentDatabase::StudentDatabase(void) {
	StudentDatabase::ReadFromFile();
};

//--------------------------------------------------------------------------------

void StudentDatabase::ReadFromFile(void){
	std::fstream Read("Data.txt", std::ios::in);
	std::string Line, TempString;
	std::stringstream SStream;

	int id, englishmarks, mathmarks, sciencemarks, historymarks, geographymarks;
	std::string name;

	while (getline(Read, Line, '\n')) {
		std::stringstream SStream(Line);
		getline(SStream, TempString, ',');
		id = atoi(TempString.c_str());
		getline(SStream, TempString, ',');
		name = TempString.c_str();
		getline(SStream, TempString, ',');
		englishmarks = atoi(TempString.c_str());
		getline(SStream, TempString, ',');
		mathmarks = atoi(TempString.c_str());
		getline(SStream, TempString, ',');
		sciencemarks = atoi(TempString.c_str());
		getline(SStream, TempString, ',');
		historymarks = atoi(TempString.c_str());
		getline(SStream, TempString, ',');
		geographymarks = atoi(TempString.c_str());
		Student Student(id, name, englishmarks, mathmarks, sciencemarks, historymarks, geographymarks);
		StudentDatabase::m_studentrecord.push_back(Student);
	}
	Read.close();
}

//--------------------------------------------------------------------------------

void StudentDatabase::MakeAnEntry(const Student& st){
	StudentDatabase::m_studentrecord.push_back(st);
}

//--------------------------------------------------------------------------------

void StudentDatabase::ShowAll(void) const{
	std::cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|  " << std::setw(10) << std::left << "Sr No." << std::setw(10) << std::left << "ID" << std::setw(25) << std::left << "Name" << std::setw(15) << std::left << "English" << std::setw(15) << std::left << "Math" << std::setw(15) << std::left << "Science" << std::setw(15) << std::left << "History" << std::setw(15) << std::setw(15) << std::left << "Geography" << std::setw(15) << std::left << "Percentage" << std::setw(7) << std::left << "Grade" << "|" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < StudentDatabase::m_studentrecord.size(); i++) {
		std::cout << "|    " << std::setw(7) << std::left << i + 1;
		std::cout << std::setw(11) << std::left  << StudentDatabase::m_studentrecord[i].GetId();
		std::cout << std::setw(27) << std::left  << StudentDatabase::m_studentrecord[i].GetName();
		std::cout << std::setw(14) << std::left  << StudentDatabase::m_studentrecord[i].GetEnglishMarks();
		std::cout << std::setw(16) << std::left  << StudentDatabase::m_studentrecord[i].GetMathMarks();
		std::cout << std::setw(15) << std::left  << StudentDatabase::m_studentrecord[i].GetScienceMarks();
		std::cout << std::setw(16) << std::left  << StudentDatabase::m_studentrecord[i].GetHistoryMarks();
		std::cout << std::setw(12) << std::left  << StudentDatabase::m_studentrecord[i].GetGeographyMarks();
		std::cout << std::setw(05) << std::right << StudentDatabase::m_studentrecord[i].GetPercentage() << std::setw(12) << std::left << "%";
		std::cout << std::setw(05) << std::left  << StudentDatabase::m_studentrecord[i].GetGrade() << "|" << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
}

//--------------------------------------------------------------------------------

void StudentDatabase::RemoveAnEntry(const int &Index){
	StudentDatabase::WriteToFile(Index);
	StudentDatabase::m_studentrecord.clear();
	StudentDatabase::ReadFromFile();
}

//--------------------------------------------------------------------------------

void StudentDatabase::ModifyData(const int& VecIndex, const int& Subject, const int& NewMarks) {
	int* ptr = 0;
	if (Subject == COLUMNNAME::English) {
		ptr = &m_studentrecord[VecIndex - 1].m_englishmarks;
	}
	else if (Subject == COLUMNNAME::Math) {
		ptr = &StudentDatabase::m_studentrecord[VecIndex - 1].m_mathmarks;
	}
	else if (Subject == COLUMNNAME::Science) {
		ptr = &StudentDatabase::m_studentrecord[VecIndex - 1].m_sciencemarks;
	}
	else if (Subject == COLUMNNAME::History) {
		ptr = &StudentDatabase::m_studentrecord[VecIndex - 1].m_historymarks;
	}
	else if (Subject == COLUMNNAME::Geography) {
		ptr = &StudentDatabase::m_studentrecord[VecIndex - 1].m_geographymarks;
	}
	else {
		// Invalid Input
	}
	if (ptr != 0) {
		*ptr = NewMarks;
	}

}

//--------------------------------------------------------------------------------

void StudentDatabase::Sort(const int& Choice){

	bool (*ptr) (Student&, Student&) = 0;
	if (Choice == COLUMNNAME::Id) {
		ptr = CompareById;
	}
	else if (Choice == COLUMNNAME::English) {
		ptr = CompareByEnglishMarks;
	}
	else if (Choice == COLUMNNAME::Math) {
		ptr = CompareByMathMarks;
	}
	else if (Choice == COLUMNNAME::Science) {
		ptr = CompareByScienceMarks;
	}
	else if (Choice == COLUMNNAME::History) {
		ptr = CompareByHistoryMarks;
	}
	else if (Choice == COLUMNNAME::Geography) {
		ptr = CompareByGeographyMarks;
	}
	else if (Choice == COLUMNNAME::Percentage) {
		ptr = CompareByPercentage;
	}
	else {
		// Invalid Input
	}
	if (ptr != 0) {
		std::sort(StudentDatabase::m_studentrecord.begin(), StudentDatabase::m_studentrecord.end(), *ptr);
	}
}

//--------------------------------------------------------------------------------

void StudentDatabase::WriteToFile(const int& Index = -1) const{
	std::fstream Write("temp.txt", std::ios::out | std::ios::app);
	for (int i = 0; i < StudentDatabase::m_studentrecord.size(); i++) {
		if (i + 1 != Index) {
			Write << StudentDatabase::m_studentrecord[i].GetId() << ',';
			Write << StudentDatabase::m_studentrecord[i].GetName() << ',';
			Write << StudentDatabase::m_studentrecord[i].GetEnglishMarks() << ',';
			Write << StudentDatabase::m_studentrecord[i].GetMathMarks() << ',';
			Write << StudentDatabase::m_studentrecord[i].GetScienceMarks() << ',';
			Write << StudentDatabase::m_studentrecord[i].GetHistoryMarks() << ',';
			Write << StudentDatabase::m_studentrecord[i].GetGeographyMarks() << ',';
			Write << StudentDatabase::m_studentrecord[i].GetPercentage() << ',';
			Write << StudentDatabase::m_studentrecord[i].GetGrade();
			Write << '\n';
		}
	}
	Write.close();
	remove("Data.txt");
	rename("temp.txt", "Data.txt");
}

//--------------------------------------------------------------------------------

void StudentDatabase::SaveAll(void){
	StudentDatabase::WriteToFile();
	StudentDatabase::m_studentrecord.clear();
	StudentDatabase::ReadFromFile();
}

//--------------------------------------------------------------------------------

int StudentDatabase::Size(void) const{
	int size = StudentDatabase::m_studentrecord.size();
	return size;
}

//--------------------------------------------------------------------------------

int StudentDatabase::GetID(const int& Index) const{
	return StudentDatabase::m_studentrecord[Index].GetId();
}

//--------------------------------------------------------------------------------

StudentDatabase::~StudentDatabase(void) {
	StudentDatabase::WriteToFile();
}

//--------------------------------------------------------------------------------