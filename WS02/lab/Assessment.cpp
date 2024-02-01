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
#define _CRT_SECURE_NO_WARNINGS
#include "Assessment.h"

namespace seneca {
    bool read(int& value, FILE* fptr) {

        return fscanf(fptr, "%d", &value) == 1;
    }

    bool read(double& value, FILE* fptr) {

        return fscanf(fptr, "%lf", &value) == 1;
    }

    bool read(char* cstr, FILE* fptr) {

        return fscanf(fptr, ",%60[^\n]\n", cstr) == 1;
    }

    bool read(Assessment& assess, FILE* fptr) {
        double tempMark;
        char tempTitle[61];  // 60 characters + 1 for null terminator

        if (fscanf(fptr, "%lf,%60[^\n]\n", &tempMark, tempTitle) == 2) {
            assess.m_mark = new double(tempMark);
            assess.m_title = new char[strlen(tempTitle) + 1]; //actual size + 1
            strcpy(assess.m_title, tempTitle);

            return true;
        }
        return false;
    }

    void freeMem(Assessment*& aptr, int size) {
        for (int i = 0; i < size; i++) {
            delete aptr[i].m_mark;
            delete[] aptr[i].m_title;
        }
        delete[] aptr;
        aptr = nullptr;
    }

    int read(Assessment*& aptr, FILE* fptr) {
        int numRecords;
        if (!read(numRecords, fptr)) {
            return 0;
        }

        aptr = new Assessment[numRecords];
        int i;
        for (i = 0; i < numRecords; ++i) {
            if (!read(aptr[i], fptr)) {
                break;
            }
        }

        if (i != numRecords) {
            freeMem(aptr, i);
            return 0;
        }

        return numRecords;
    }
}
