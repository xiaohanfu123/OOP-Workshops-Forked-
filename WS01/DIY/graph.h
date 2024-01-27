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


#ifndef GRAPH_H 
#define GRAPH_H

namespace seneca {

	// Maximum number of samples in an graph
	/*const int MAX_NO_OF_SAMPLES = 20;*/
	const int GRAPH_WIDTH = 65;

	// Fills the samples array with the statistic samples
	void getSamples(int samples[], int noOfSamples);
	// Finds the largest sample in the samples array, if it is larger than 70,
	// therwise it will return 70. 
	int findMax(int samples[], int noOfSamples);
	// Prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max);
	// Prints a graph comparing the sample values visually 
	void printGraph(int samples[], int noOfSamples, const char* label);

}
#endif