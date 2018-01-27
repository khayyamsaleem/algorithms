/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Khayyam Saleem
 * Date        : 9/22/16 
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor
 *				 System.
 ******************************************************************************/
#include <iostream>
#include <cctype>

using namespace std;

bool is_all_lowercase(const string &s) {
    // TODO: returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.
	int i = 0;
	char c;
	while(s[i]){
		c=s[i];
		if (!islower(c) || !isalpha(c)){
			return false;
		}
		i++;
	}
	return true;
	
}

bool all_unique_letters(const string &s) {
    // TODO: returns true if all letters in string are unique, that is
    // no duplicates are found; false otherwise.
    // You may use only a single int for storage and work with bitwise
    // and bitshifting operators.
    // No credit will be given for other solutions.
	unsigned int values = 0;
    unsigned int bit = 0;
	for (unsigned int i=0; i < s.length(); i++){
		// right shift by difference and check if you've seen it already
		bit = 1 << (s[i] - 'a');
		if ((values & bit) == bit){
			return false;
		}
		// left shift 1 by difference, bitwise or with values 
		values |= bit;
	}
	return true;
	
}

int main(int argc, char * const argv[]) {
    // TODO: reads and parses command line arguments.
    // Calls other functions to produce correct output.
	if (argc != 2){
		cerr << "Usage: ./unique <string>" << endl;
		return 1;
	}

	//argument checks
//	if (!isalpha(argv[1])) {
//		cerr << "Error: String must contain only lowercase letters." << endl;
//		return 1;
//	}
	
	// case in which string contains anything other than lowercase letters
	if (!is_all_lowercase(argv[1])){
		cerr << "Error: String must contain only lowercase letters." << endl;
		return 1;
	}

	// case in which all letters are unique
	if (all_unique_letters(argv[1])){
		cout << "All letters are unique." << endl;
		return 0;
	}

	//case in which there exist duplicate characters in the string
	if (!all_unique_letters(argv[1])){
		cout << "Duplicate letters found." << endl;
		return 0;
	}
}
