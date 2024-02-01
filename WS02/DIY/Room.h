/*/////////////////////////////////////////////////////////////////////////
						Workshop2 Part2
Full Name  : Hanfu Xiao
Student ID#: 033503145
Email      : hxiao15@myseneca.ca
Section    : NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef ROOM_H
#define ROOM_H
#include "Guest.h"
#include <cstring>
#include<iostream>
namespace seneca {
	struct Room
	{
		char m_roomNumber[6];
		int m_noOfGuests;
		Guest* m_guests;
	};

	// sets the Room by allocating a dynamic array of guests and setting the room number 
	// (no validation is done for room number)
	void set(Room& room, int numberOfGuests, const char* roomNumber);

	// Prints the room number and names of the guests in the following lines with four 
	// spaces of indentaion 
	// See correct_output.txt for the exact format
	void print(const Room& room);

	// Books a room by receiving the room number, number of guests and the guest information.
	// See correct_output.txt for the exact format
	void book(Room& room);

	// vacates the room by dallocating all the memory used.
	void vacate(Room& room);
}
#endif 