
#ifndef TDDFUNCS_H
#define TDDFUNCS_H

#include <string>
#include <iostream>

// Helper function that converts line number to string for printing
std::string convertLineNumber(int lineNumber);

// template requires == and << 

template<typename T> void assertEquals(T expected,
	T actual,
	std::string message,
	int lineNumber) {
	std::string line = convertLineNumber(lineNumber);
	if (expected == actual) {
		std::cout << "PASSED: " << message << line << std::endl;;
	}
	else {
		std::cout << "   FAILED: " << message << line << std::endl
			<< "     Expected: " << expected << " Actual: " << actual << std::endl;
	}
}

// specialized because char * doesn't work properly on ==
void assertEquals(const char* const expected,
	const char* const actual,
	const std::string& message,
	int lineNumber = -1);

// specialized for the same reason, and because expected is often a string literal
void assertEquals(const char* const expected,
	const std::string& actual,
	const std::string& message,
	int lineNumber = -1);

// Macros to insert file and line number to the message

#define ASSERT_EQUALS(expected,actual) \
  assertEquals(expected,actual,#actual " at " __FILE__ ,  __LINE__ )


void assertTrue(bool expression, const std::string& message = "", int lineNumber = -1);

#define ASSERT_TRUE(expression) \
  assertTrue(expression,#expression " at " __FILE__, __LINE__)

#endif // TDDFUNCS_H
