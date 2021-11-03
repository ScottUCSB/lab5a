#include <iostream>
#include <sstream>
#include <time.h>
#include <string> 
#include <stdlib.h>
#include "tddFuncs.h"
#include "WordCount.h"

using namespace std;

int main() {
	const int iNumberOfTestStrings = 10;
	std::string saTestStringArray[iNumberOfTestStrings] = { "12mOnkEYs - $","Pa55ive", "can't", "good-hearted",  "----12mOnkEYs ---- $","123","'''---","123s'''---",".@45#t",""};
	std::string saTestStringArray2[iNumberOfTestStrings] = { "12mOnkEYs","12mOnkEYs","12mOnkEYs","12mOnkEYs","12mOnkEYs","12mOnkEYs","12mOnkEYs","12mOnkEYs","12mOnkEYs","12mOnkEYs" };

	std::string saAnswersStringArray[iNumberOfTestStrings] = { "monkeys", "paive", "can't",  "good-hearted","monkeys","","","s","t",""}; //3 repeated
	std::string sAcceptableChars = "abcdefghijklmnopqrstuvwxyz-'";
	WordCount* objWordCount = new WordCount();
	
	std::string sHashRepeatedTesters[iNumberOfTestStrings]= { "12mOnkEYs - $","t", "t", "-t",  "----t ---- $","123","'''---","123s'''---",".@45#t","" }; //10 repeats 
//	size_t stExpectedNumberTimesRepeated
	//vector<std::pair<std::string, size_t>> hashTable(100);	//this damn stuff is in the private of wordCount 
	




	

	
	ASSERT_EQUALS(true,objWordCount->isWordChar('a'));
	ASSERT_EQUALS((objWordCount->isWordChar('\'')), true);
	ASSERT_EQUALS((objWordCount->isWordChar('-')), true);
	ASSERT_EQUALS((objWordCount->isWordChar('3')), false);
	ASSERT_EQUALS((objWordCount->isWordChar('%')), false);
	ASSERT_EQUALS((objWordCount->isWordChar(' ')), false);
	ASSERT_EQUALS((objWordCount->isWordChar('+')), false);

	for (int x = 0; x < iNumberOfTestStrings; x++) {
		ASSERT_EQUALS(objWordCount->makeValidWord(saTestStringArray[x]), saAnswersStringArray[x]);	
	}

	//std::cout << "___TEST on VecTOR___\n";
	for (int x = 0; x < iNumberOfTestStrings; x++) {
		objWordCount->incrWordCount(saTestStringArray[x]);
	}
	ASSERT_EQUALS((objWordCount->getTotalWords()), 10);
	ASSERT_EQUALS((objWordCount->getNumUniqueWords()), 7);
	objWordCount->incrWordCount("monkeys");
	ASSERT_EQUALS((objWordCount->getWordCount("monkeys")), 3); 
	ASSERT_EQUALS((objWordCount->decrWordCount("monkeys")), 2);
	

	for (int x = 0; x < iNumberOfTestStrings; x++) {
		objWordCount->incrWordCount(sHashRepeatedTesters[x]);
	}
	

	ASSERT_EQUALS((objWordCount->getTotalWords()), 21);
	ASSERT_EQUALS((objWordCount->getNumUniqueWords()), 7);
	objWordCount->incrWordCount("t");
	ASSERT_EQUALS((objWordCount->getWordCount("t")), 7);
	ASSERT_EQUALS((objWordCount->decrWordCount("t")), 6);
	
	
	



	

	//std::cout<<"\nget total words should be 10: "<<objWordCount->getTotalWords();
	//std::cout << "\n getnum unique words should be 7:" << objWordCount->getNumUniqueWords();
	//std::cout << "\n get word count for monkeys should be 2 : " << objWordCount->getWordCount("monkeys");
	//std::cout << "\n decrement monkeys x1 should be 1 : " << objWordCount->decrWordCount("monkeys");

	

	//test string 2 10x monkeys
	//std::cout<<"\nget total words should be 10: "<<objWordCount->getTotalWords();
	//std::cout << "\n getnum unique words should be 1:" << objWordCount->getNumUniqueWords();
	//std::cout << "\n get word count for monkeys should be 10 : " << objWordCount->getWordCount("monkeys");
	//assertTrue((objWordCount->getTotalWords() == 10)," FIRST getTotalWords TEST");
	


/*
	for (int x =iNumberOfTestStrings; x >0; x--) {
		objWordCount->decrWordCount(sHashRepeatedTesters[x]);
		objWordCount->decrWordCount(saTestStringArray[x]);

	}
    */


	//ASSERT_EQUALS(std::cout << objWordCount->getTotalWords(), 7); //7 unique words in the first wave

			
	return 0;

}












	//Do we need to make a test fo risWordChar???????????????? since its a helper

	/*for (int x = 0; x < iNumberOfTestStrings; x++) {
		for (int y = 0; y < saTestStringArray[x].length(); y++) {
			assertTrue(objWordCount->isWordChar(saTestStringArray[x][y]),)
		}
	}


	
	std::cout << "--------makeValidWord TESTS--------\n";
	for (int x = 0; x < iNumberOfTestStrings; x++) {
		if (saAnswersStringArray[x] == objWordCount->makeValidWord(saTestStringArray[x]))
			std::cout << "test at index " << x << ": passed \n";
		else {
			std::cout << "test at index " << x << ": failed \n";
			std::cout << "tested " << saTestStringArray[x] << "\n" << "resulted " << objWordCount->makeValidWord(saTestStringArray[x]) << "\nExpected " << saAnswersStringArray[x] << "/n";

		}
	}

	std::cout << "--------isWordChar TESTS--------\n";
	bool bIsWordCharTest = true;
	for (int x = 0; x < iNumberOfTestStrings; x++) {
std::cout << "new word "<<saTestStringArray[x]<<"\n";
		for (int y = 0; y < saTestStringArray[x].length(); y++) {
			if ((isalpha(saTestStringArray[x][y]) || saTestStringArray[x][y] == '\'' || saTestStringArray[x][y] == '\-' )&& objWordCount->isWordChar(saTestStringArray[x][y])) {
				bIsWordCharTest=true;
			}
			else if(!objWordCount->isWordChar(saTestStringArray[x][y])) {
				bIsWordCharTest = true;
			}
			else {
				std::cout << " test " << saTestStringArray[x] << " failed \n";
				bIsWordCharTest = false;
				break;
			}
		}
		std::cout<<"test "<<saTestStringArray[x]<<" succedded\n";

	}*/



	/*
	////////// //FROM LAB 4.////////////////////
	cout << "Testing class Roster..." << endl;

	std::string testRosterSource = std::string("") +
		"perm,lname,fname\n" +
		"1234567,Smith,Malory Logan\n" +
		"5555555,Perez,Juana\n" +
		"2222222,Conrad,Phillip Todd\n" +
		"8888888,Preble,Ethan Awesome\n" +
		"1111111,Laux,Hunter\n";

	// Roster r;

	// ASSERT_EQUALS(0, r.getNumStudents());

	// Allows me to test reading from a stream
	//  without relying anything external to the test code
	//  i.e. another file on the file system.
	// That is one of the principles of "unit testing".

	std::istringstream iss(testRosterSource);
	r.addStudentsFromStream(iss);

	ASSERT_EQUALS(5, r.getNumStudents());

	ASSERT_EQUALS(1234567, r.getStudentAt(0).getPerm());
	ASSERT_EQUALS("Perez", r.getStudentAt(1).getLastName());
	ASSERT_EQUALS("Phillip Todd", r.getStudentAt(2).getFirstAndMiddleNames());

	std::string expectedToStringResult = std::string("") +
		"{\n" +
		"[1234567,Smith,Malory Logan],\n" +
		"[5555555,Perez,Juana],\n" +
		"[2222222,Conrad,Phillip Todd],\n" +
		"[8888888,Preble,Ethan Awesome],\n" +
		"[1111111,Laux,Hunter]\n" +
		"}\n";

	ASSERT_EQUALS(expectedToStringResult, r.toString());
	*/
