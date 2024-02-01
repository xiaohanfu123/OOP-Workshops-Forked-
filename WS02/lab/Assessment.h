/*/////////////////////////////////////////////////////////////////////////
						Workshop2 Part1
Full Name  : Hanfu Xiao
Student ID#: 033503145
Email      : hxiao15@myseneca.ca
Section    : NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef ASSESSMENT_H
#define ASSESSMENT_H

#include <iostream>
#include <cstdio>
#include <cstring>

namespace seneca {
	
	struct Assessment {
		double* m_mark;
		char* m_title;
	};

	bool read(int& value, FILE* fptr);

	bool read(double& value, FILE* fptr);

	bool read(char* cstr, FILE* fptr);

	bool read(Assessment& assess, FILE* fptr);

	void freeMem(Assessment*& aptr, int size);

	int read(Assessment*& aptr, FILE* fptr);
}


#endif