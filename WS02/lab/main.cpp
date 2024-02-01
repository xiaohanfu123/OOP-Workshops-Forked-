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

#include <iostream>
#include <cstdio>
#include <cstring>
#include "Assessment.h"
#include "Assessment.h"
#include "Assessment.h"
using namespace seneca;
using namespace std;
void display(const Assessment& a);
bool readTesters();
int main() {
   if(readTesters()) {
      int cnt;
      Assessment* aptr = nullptr;
      FILE* fptr = fopen("baddata.txt", "r");
      cnt = read(aptr, fptr);
      if(cnt) {
         cout << "This should have failed, keep working on the workshop!" << endl;
      } else {
         cout << "File records and number of records do not match!" << endl;   // this is the correct output
      }
      fclose(fptr);
      cout << "Listing Good Data:" << endl;
      fptr = fopen("gooddata.txt", "r");
      cnt = read(aptr, fptr);
      if(cnt) {
         for(int i = 0; i < cnt; i++) {
            cout << (i + 1) << ": ";
            display(aptr[i]);
         }
         freeMem(aptr, cnt);
      } else {
         cout << "This should not have failed, keep working on the workshop!" << endl;
      }
      fclose(fptr);
   }
   return 0;
}
void display(const Assessment& a) {
   cout.setf(ios::fixed);// setting the number of digits
   cout.precision(1);    // after the decimal point to 1
                         // this will be covered later
   cout << a.m_title << ": " << *a.m_mark << endl;
}

bool readTesters() {
   FILE* fptr = fopen("gooddata.txt", "r");
   bool passed = true;
   int i;
   double d;
   char str[61];
   if(read(i, fptr) && i == 13) {
      cout << "bool read(int& value, FILE* fptr) test passed" << endl;
   }
   else {
      cout << "bool read(int& value, FILE* fptr) test failed" << endl;
      passed = false;
   }
   if(passed && read(d, fptr) && (d - 70.9) < 0.0001 && (d - 70.9) > -0.0001) {
      cout << "bool read(double& value, FILE* fptr) test passed" << endl;
   } 
   else {
      cout << "bool read(double& value, FILE* fptr) test failed" << endl;
      passed = false;
   }
   if(passed && read(str, fptr) && strcmp(str, "Applied Problem Solving") == 0)  {
      cout << "bool read(double& value, FILE* fptr) test passed" << endl;
   } 
   else {
      cout << "bool read(double& value, FILE* fptr) test failed" << endl;
      passed = false;
   }
   fclose(fptr);
   return passed;
}