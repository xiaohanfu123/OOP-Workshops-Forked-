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
#define _CRT_SECURE_NO_WARNINGS
#include "Room.h"
// sets the Room by allocating a dynamic array of guests and setting the room number 
// (no validation is done for room number)
namespace seneca {
	void set(Room& room, int numberOfGuests, const char* roomNumber) {
		room.m_noOfGuests = numberOfGuests;
		strcpy(room.m_roomNumber, roomNumber);

		room.m_guests = new Guest[numberOfGuests];

		for (int i = 0; i < numberOfGuests; ++i) {
			room.m_guests[i].m_firstName = nullptr;
			room.m_guests[i].m_lastName = nullptr;
		}
	}

	// Prints the room number and names of the guests in the following lines with four 
	// spaces of indentaion 
	// See correct_output.txt for the exact format
	void print(const Room& room) {
		if (room.m_guests != nullptr) {
			std::cout << "Room Number: " << room.m_roomNumber << std::endl;
			int i;
			for (i = 0; i < room.m_noOfGuests; i++) {
				std::cout << "    ";
				print(room.m_guests[i]);
			}
		}
		else {
			std::cout << "Empty Room!" << std::endl;
		}
	}

	// Books a room by receiving the room number, number of guests and the guest information.
	// See correct_output.txt for the exact format
	void book(Room& room) {
		std::cout << "Room number: ";
		std::cin >> room.m_roomNumber;

		std::cout << "Number of guests: ";
		std::cin >> room.m_noOfGuests;

		room.m_guests = new Guest[room.m_noOfGuests];
		int i;
		for (i = 0; i < room.m_noOfGuests; i++) {
			std::cout << i + 1 << ":" << std::endl;
			book(room.m_guests[i]);
		}

	};


	// vacates the room by dallocating all the memory used.
	void vacate(Room& room) {
		if (room.m_guests != nullptr) {
			for (int i = 0; i < room.m_noOfGuests; ++i) {
				delete[] room.m_guests[i].m_firstName;
				delete[] room.m_guests[i].m_lastName;
				room.m_guests[i].m_firstName = nullptr;
				room.m_guests[i].m_lastName = nullptr;
			}
			delete[] room.m_guests;
			room.m_guests = nullptr;
			room.m_noOfGuests = 0;  // Reset the number of guests
		}
	}
}
