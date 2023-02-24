#include "StdAfx.h"
#include <conio.h>
#include "Student.h"
#include "UserInterface.h"

int main() {
	StudentDatabase SD;
	UserInterface UI;
	int Choice;

	while (true) {
		system("CLS");
		UI.UIDisplay();
		Choice = UI.UIChoice();
		std::cout<<std::endl;
		system("CLS");
		switch (Choice) {
			case 1: {
				SD.ShowAll();
				system("pause");
				break;
			}

			case 2: {
				SD.ShowAll();
				Student Student(-1, "", -1, -1, -1, -1, -1);
				UI.UISetID(Student, SD);
				UI.UISetName(Student);
				UI.UISetEnglishMarks(Student);
				UI.UISetMathMarks(Student);
				UI.UISetScienceMarks(Student);
				UI.UISetHistoryMarks(Student);
				UI.UISetGeographyMarks(Student);
				SD.MakeAnEntry(Student);
				SD.SaveAll();
				UI.UIDisplaySavedSuccessfully();
				system("pause");
				system("CLS");
				SD.ShowAll();
				system("pause");
				break;
			}

			case 3: {
				SD.ShowAll();
				int Index, Subject, NewMarks;
				Index = UI.UIReadAndValidateRowNumber(SD);
				UI.UIColumnsForMarksUpdate();
				Subject = UI.UIReadAndValidateSubjectColumnNumber();
				NewMarks = UI.UIReadAndValidateMarks();
				SD.ModifyData(Index, Subject, NewMarks);
				SD.SaveAll();
				UI.UIDisplaySavedSuccessfully();
				system("pause");
				system("CLS");
				SD.ShowAll();
				system("pause");
				break;
			}

			case 4: {
				SD.ShowAll();
				int row;
				row = UI.UIReadAndValidateRowNumber(SD);
				SD.RemoveAnEntry(row);
				system("CLS");
				SD.ShowAll();
				system("pause");
				break;
			}

			case 5: {
				SD.ShowAll();
				int column;
				UI.UIColumnsForSorting();
				column = UI.UIReadAndValidateSortColumnNumber();
				SD.Sort(column);
				system("CLS");
				SD.ShowAll();
				system("pause");
				break;
			}

			case 6: {
				SD.SaveAll();
				UI.UIDisplaySavedSuccessfully();
				system("pause");
				break;
			}

			case 7: {
				return 0;
				break;
			}

			default: {
				break;
			}
		}
	}
	return 0;
} 