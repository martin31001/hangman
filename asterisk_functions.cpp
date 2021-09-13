/*
 * asterisk_functions.cpp
 *
 *  Created on: Apr 28, 2021
 *      Author: mmarr
 */
#include "Project4.h"

bool check_asterisks(string asterisks, int size) { //checks if asterisk is gone to see if player wins
	for (int i = 0; i < size; i++) {
		if (asterisks[i] == '*') {
			return false;
		}
	}
	return true;
}

string position(string letter, int n, string word, string asterisks) { //changes asterisk if letter is guessed
	char temp;
	char letter_char;
	letter_char = letter[0];
	letter_char = tolower(letter_char);
	for (int i = 0; i < n; i++) {
		temp = word[i];
		temp = tolower(temp);
		if (temp == letter_char) {
			asterisks[i] = word[i];
		}
	}
	return asterisks;
}

