// WordCount.cpp
#include <string>
#include <utility>
#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(const std::string& word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int iCount = 0;
	for (int i = 0; i < 100; i++) {
		for (auto a : table[i]) {
			if (a.second > 0) {

				iCount += a.second;
			}
			/*
		for (int y = 0; y < table[i].size(); y++) {
			if (table[i][y].second != 0)
				iCount += table[i][y].second;*/
		}
	}
	// STUB.
	return iCount;
}

int WordCount::getNumUniqueWords() const {
	int iCount = 0;
	for (int i = 0; i < 100; i++) {
		for (size_t y = 0; y < table[i].size(); y++) {
			if (table[i][y].second != 0)
				iCount++;
		}
	}
	// STUB.
	return iCount;
}

int WordCount::getWordCount(const std::string& word) const {
	// STUB
	string sValid = makeValidWord(word);
	size_t hashed = hash(sValid);
	for (auto i : table[hashed]) {
		if (i.first == sValid) {					//if it's a repeat of same hash AND same word

			//or if ++ gives an issue 
			//i.second= i.second+1;
			return i.second;
		}
	}
	return 0;
}





int WordCount::incrWordCount(const std::string& word) {
	// STUB
	if (word == "")
		return 0;
	string sValid = makeValidWord(word);
	if (sValid == "")
		return 0;
	size_t hashed = hash(sValid);

	for (size_t x = 0; x < table[hashed].size(); x++) {
		if (table[hashed].at(x).first == sValid) {
			table[hashed].at(x).second++;
			return table[hashed].at(x).second;
		}
	}
	/*
	for (auto i : table[hashed]) {
		if (i.first == sValid) {					//if it's a repeat of same hash AND same word
			//i.second++;
			//or if ++ gives an issue
			std::cout << i.second;
			i.second*=(i.second*+1);
			return i.second;
		}
	}
	*/
	std::pair<std::string, size_t> pLatestCollision;		//if it has the same hash BUT is a new word - thrown onto the end.
	pLatestCollision.first = sValid;
	pLatestCollision.second = 1;
	table[hashed].push_back(pLatestCollision);
	return 1;
}




int WordCount::decrWordCount(const std::string& word) {
	// STUB
	string sValid = makeValidWord(word);
	size_t hashed = hash(sValid);
	int x = 0;


	for (auto i : table[hashed]) {

		if (i.first == sValid) {
			if (i.second == 1) {									//if it's a repeat of same hash AND same word  AND second is 1 RETURN 0 and remove from HT
				//table[hashed].erase(i); //not sure why wont work
				table[hashed].erase(table[hashed].begin() + x);		// now use integer x to delete it
				return 0;
			}
			else {
				//i.second--;											//*********WONT KEEP NEW VALUE**********************************
				table[hashed][x].second--;
				i.second--;

				return i.second;
			}
		}
		x++;
	}

	return -1;		//it isn't in the vector then, nothing to subtract RETURN -1

}












bool WordCount::isWordChar(char c) {
	// STUB
	string sAcceptedChars = "abcdefghijklmnopqrstuvwxyz-'";
	for (size_t y = 0; y < sAcceptedChars.length(); y++) {
		if (tolower(c) == sAcceptedChars[y])
			return true;
	}

	return false;
}

std::string WordCount::makeValidWord(const std::string& word) {
	// STUB`
//	if (isalpha(word))
	if (word == "")
		return"";
	string sNewWord = "";
	string sAcceptedChars = "abcdefghijklmnopqrstuvwxyz-'";
	for (size_t x = 0; x < word.size(); x++) {
		for (size_t y = 0; y < sAcceptedChars.length(); y++) {
			if (tolower(word[x])) {
				if (tolower(word[x]) == sAcceptedChars[y]) {
					sNewWord += (sAcceptedChars[y]);
				}
			}
		}
	}
	while ((sNewWord[0] == '\'' || sNewWord[0] == '-') && sNewWord != "") {
		sNewWord.erase(0, 1);
	}
	if (sNewWord == "")
		return"";
	while ((sNewWord.back() == '\'' || sNewWord.back() == '-') && sNewWord != "") {
		sNewWord.pop_back();
	}

	return sNewWord;
}
/*
for (int x = 0; x < sAcceptedChars.length(); x++) {
	if (sNewWord[x] == '\'' || sNewWord[x] == '\-') {
		sNewWord.erase(0, 1);
	}
	else break;
}
for (int x = sAcceptedChars.length()-1; x >=0 ; x--) {
	if (sNewWord[x] == '\'' || sNewWord[x] == '\-') {
		sNewWord.erase(0, 1);
	}
	else break;
	*/
