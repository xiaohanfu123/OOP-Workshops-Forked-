/*/////////////////////////////////////////////////////////////////////////
						Workshop1 Part1
Full Name  : Hanfu Xiao
Student ID#: 033503145
Email      : hxiao15@myseneca.ca
Section    : NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
/////////////////////////////////////////////////////////////////////////*/


#ifndef IO_H 
#define IO_H
namespace seneca {

	
	// prints the int value in width of fieldWidth
	void printInt(int value, int fieldWidth);
	// returns number of digits in an integer
	int intDigits(int value);
	// Performs a fool-proof integer entry assuming the user will only enter numeric values.
	// if the user enters non digit values, the function will hang in an endless loop.
	int getInt(int min, int max);
	// moves the cursor backwards
	void goBack(int n);
	// displays the user interface menu
	int menu(int noOfSamples);
	// Draws a line and adds a label
	void labelLine(int n, const char* label);
	// Draws a line
	void line(int n);
}
#endif