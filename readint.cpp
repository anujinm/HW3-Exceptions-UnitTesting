#include "readint.h"
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <ctype.h>
using namespace std;

int read_int(const string &prompt, int low, int high)
{
	cin.exceptions(ios_base::failbit);
	int num = 0;
	try {
		if (low >= high || high - low == 1) {
			throw range_error("Exception- The range is invalid!\n");
		}
		while (true) { // Loop until valid input
			try {
				cout << prompt;
				cin >> num;
				while (num <= low || num >= high) {
					cout << "Value is outside the range. Please try again, ";
					cin >> num;
				}
				return num;
			}
			catch (ios_base::failure& ex) {
				cout << "Bad numeric string -- try again\n";
				// Reset the error flag
				cin.clear();
				// Skip current input line
				cin.ignore(numeric_limits<int>::max(), '\n');

			}
		}
	}
	catch (exception &test) {
		cerr << " caught: " << test.what() << endl;
	};

}