#include "stdafx.h"
#include "CppUnitTest.h"
#include "../EX03_1/readint.h"
#include <stdexcept>
#include <fstream>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTester
{		
	TEST_CLASS(READINT_TEST)
	{
	public:
		
		TEST_METHOD(TestCase1) // Test case 1: invalid input
		{
			// crate a string stream object with the desired input
			istringstream ss("Hello\n0");

			// Replace the cin read buffer with the read buffer from the string stream 
			streambuf *orig_cin = cin.rdbuf(ss.rdbuf());

			// Perform the read_int() test.
			// cin will now read contents from your stringstream and not from the keyboard.
			// We expect the correct value returned is 0, ignoring the Hello string.

			Assert::AreEqual(read_int("Please enter a number within the range: ", -3, 3), 0);
			// Restore cin to the way it was before
			cin.rdbuf(orig_cin);

			// Close the file stream
			//ss.close();
		}


		TEST_METHOD(TestCase2) // Test case 2: invalid input (high < low )
		{
			// define a C++11 Lambda function to be called by your test
			auto func = []() {
				read_int("Please enter a number within the range: ", 5, 1);
			};

			Assert::ExpectException<std::invalid_argument>(func);
		}


		TEST_METHOD(TestCase3) // Test case 3: invalid input 
		{
			istringstream ss3("-3\n5\n10\n-2\n3");
			streambuf *orig_cin = std::cin.rdbuf(ss3.rdbuf());
			Assert::AreEqual(read_int("Please enter a number within the range: ", 0, 4), 3);
			cin.rdbuf(orig_cin);
		}


		TEST_METHOD(TestCase4) // Test case 4: invalid input (high  = low )
		{
			// define a C++11 Lambda function to be called by your test
			auto func = []() {
				read_int("Please enter a number within the range: ", 0, 0);
			};

			Assert::ExpectException<invalid_argument>(func);
		}

	};
}