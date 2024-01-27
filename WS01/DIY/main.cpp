/***********************************************************************
// Workshop 1 # p2: tester program
//
// File	main.cpp
// Version 1.0
// Date	 winter 2024
// Author Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
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


#include <iostream>
#include "StMark.h"
using namespace std;
using namespace seneca;
int main() {
   bool done = false;
   char filename[256];
   while (!done) {
      cout << "Enter filename to generate report for or 'X' to exit:\n> ";
      cin >> filename;
      if ((filename[0] == 'X' || filename[0] == 'x') && filename[1] == 0) {
         done = true;
      }
      else if (!printReport(filename)) {
         cout << "Can not open \"" << filename << "\"!" << endl;
      }
   }
   cout << "Exiting program!" << endl;
   return 0;
}