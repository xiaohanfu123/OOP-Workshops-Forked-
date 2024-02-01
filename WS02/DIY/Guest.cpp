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
#include "Guest.h"

// sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
namespace seneca {
	void set(Guest& guest, const char* first, const char* last, int age)
	{
		if (first == nullptr || last == nullptr || *first == '\0' || *last == '\0') {
			guest.m_firstName = nullptr;
			guest.m_lastName = nullptr;
		}
		else {
			guest.m_firstName = new char[strlen(first) + 1];
			guest.m_lastName = new char[strlen(last) + 1];
			strcpy(guest.m_firstName, first);
			strcpy(guest.m_lastName, last);
			if (age >= 18) {
				guest.m_adult = true;
			}
			else {
				guest.m_adult = false;
			}
		}


	};

	// Prints the guest name:
	// "Name Surname(child)"
	// The child flag is printed if the guest is not an adult
	// and if the names are not set, "Vacated!" is printed.
	void print(const Guest& guest) {
		if (guest.m_firstName!=nullptr && guest.m_lastName!=nullptr && *(guest.m_firstName) != '\0' && *(guest.m_lastName )!= '\0') {
			std::cout << guest.m_firstName << " " << guest.m_lastName
				<< (guest.m_adult ? "" : "(Child)") << std::endl;
		}
		else {
			std::cout << "Vacated!" << std::endl;
		}
	};

	// books the guest information from the console:
	// Name: Jake<ENTER>
	// Lastname: Doe<ENTER>
	// Age: 10<ENTER>
	void book(Guest& guest) {
		int tempAge;
		char tempFirstName[100];
		char tempLastName[100];


		std::cout << "Name: ";
		std::cin >> tempFirstName;
		guest.m_firstName = new char[strlen(tempFirstName) + 1];
		strcpy(guest.m_firstName, tempFirstName);
		std::cout << "Lastname: ";
		std::cin >> tempLastName;
		guest.m_lastName = new char[strlen(tempLastName) + 1];
		strcpy(guest.m_lastName, tempLastName);
		std::cout << "Age: ";
		std::cin >> tempAge;
		if (tempAge >= 18) {
			guest.m_adult = true;
		}
		else {
			guest.m_adult = false;
		}
	};

	// vacates the guest by dallocating its memory.
	void vacate(Guest& guest) {
		if (guest.m_firstName != nullptr) {
			delete[] guest.m_firstName;  
			guest.m_firstName = nullptr;
		}
		if (guest.m_lastName != nullptr) {
			delete[] guest.m_lastName;  
			guest.m_lastName = nullptr;
		}
	}

}
