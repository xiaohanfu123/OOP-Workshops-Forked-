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
#ifndef GUEST_H
#define GUEST_H
#include <iostream>
#include <cstring>
namespace seneca {
	struct Guest
	{
		char* m_firstName;
		char* m_lastName;
		bool m_adult;
	};
	// sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
	void set(Guest& guest, const char* first, const char* last, int age);

	// Prints the guest name:
	// "Name Surname(child)"
	// The child flag is printed if the guest is not an adult
	// and if the names are not set, "Vacated!" is printed.
	void print(const Guest& guest);

	// books the guest information from the console:
	// Name: Jake<ENTER>
	// Lastname: Doe<ENTER>
	// Age: 10<ENTER>
	void book(Guest& guest);

	// vacates the guest by dallocating its memory.
	void vacate(Guest& guest);
}
#endif // !GUEST_H