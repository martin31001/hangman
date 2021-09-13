/*
 * word_file_functions.cpp
 *
 *  Created on: Apr 28, 2021
 *      Author: mmarr
 */

#include "Project4.h"

int load_words(string filename) {
	ifstream inFile; //file opener
	int n = 0; //counter set to 0
	string temp; //temp string to count
	inFile.open(filename.c_str()); //opens that file as a string
	if (inFile.good()) { // checks if works
		while (!inFile.eof()) { //reads till end
			inFile >> temp; //inputs string from file into temp string
			n++; //adds to the counter
		}
	}
	inFile.close();
	return n;
}

string create_string(string filename, int n) {
	ifstream inFile; //file opener
	string *words;
	string word;
	inFile.open(filename.c_str()); //opens that file as a string
	if (inFile.fail()) {
		cout << "The file has failed to open" << endl;
		exit(1);
	}
	inFile.clear(); //clears input
	inFile.seekg(0, ios::beg); //goes back to the start of the file
	words = new string[n]; //sets point to the beg of this new dynamically allocated string
	for (int i = 0; i < n; i++) {
		inFile >> words[i];
	}
	inFile.close();
	srand(time(NULL));
	word = words[rand() % n]; //selects word for guessing from string of words from file
	delete[] words;
	return word;

}


