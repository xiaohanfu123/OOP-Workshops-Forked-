/*/////////////////////////////////////////////////////////////////////////
						Workshop1 Part2
Full Name  : Hanfu Xiao
Student ID#: 033503145
Email      : hxiao15@myseneca.ca
Section    : NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include "StMark.h"
#include "file.h"
#include "graph.h"
#include "io.h"
#include <iostream>


namespace seneca {
	bool printReport(const char* filename) {
		StMark tempMarks[MAX_NO_RECS]; // Allocate temp array with conventional way
		StMark* marks = nullptr;       // Placeholder for array of StMark - marks
		bool success = false;
		int arraySize = 0;
		const int MARK_RANGE = 10;
		int markCounters[MARK_RANGE] = { 0 }; // Array to store counters of each mark range

		if (openFile(filename)) {
			arraySize = readMarks(tempMarks); // To fill tempMarks and get actual size
			closeFile();                      // Close file stream

			if (arraySize > 0) {
				marks = new StMark[arraySize]; // Array with dynamic size
				if (marks != nullptr) {        // In case the array was created successfully
					for (int i = 0; i < arraySize; i++) {
						marks[i] = tempMarks[i]; // Copy data to new array of StMark
					}

					// Count students for each mark range
					for (int i = 0; i < arraySize; i++) {
						int mark = marks[i].mark;
						// If the mark is 0, it should go to the first range (0-10)
						int rangeIndex = mark == 0 ? 0 : (mark - 1) / 10; // "11" will fall into second range (11-20) 
						markCounters[rangeIndex]++;
					}
					
					// Print the graph
					printGraph(markCounters, MARK_RANGE, "Students' mark distribution");

					success = true; // Report printed successfully
				}
				bubbleSort(marks, arraySize);
				printSortedMarks(marks, arraySize);
				delete[] marks; // Delete dynamically allocated array after use
			}

		}


		return success;
	}

	void bubbleSort(StMark* marks, int size) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (marks[j].mark < marks[j + 1].mark) {
					// Swap marks[j] and marks[j + 1]
					StMark temp = marks[j];
					marks[j] = marks[j + 1];
					marks[j + 1] = temp;
				}
			}
		}
	}

	void printSortedMarks(const StMark* marks, int size) {
		for (int i = 0; i < size; i++) {
			printInt(i + 1, 3);  
			std::cout << ": [";
			printInt(marks[i].mark, 3);  
			std::cout << "] " << marks[i].name << " " <<marks[i].surname << std::endl;
		}
		std::cout << "----------------------------------------" << std::endl;
	}

}