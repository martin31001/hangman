#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
using namespace std;
#include "Project4.h"



bool check_list(char empty_letters[LETTERS_NUM], string letter) {
	char letter_char;
	letter_char = letter[0];
	letter_char = tolower(letter_char);
	for (int i = 0; i < 26; i++) {
		if (empty_letters[i] == letter_char) { //checks letter array for previously played letter
			return true;
		}
	}
	return false;
}

char list(char empty_letters[LETTERS_NUM], string letter) {
	static int cnt = 0;
	char letter_char;
	letter_char = letter[0];
	letter_char = tolower(letter_char);
	empty_letters[cnt] = letter_char; //puts guessed letter in array of guessed letters
	cnt++;
	return empty_letters[LETTERS_NUM];
}


bool check_word(string letter, int size, string word) {
	char temp;
	char letter_char;
	letter_char = letter[0];
	letter_char = tolower(letter_char);
	for (int i = 0; i < size; i++) {
		temp = word[i];
		temp = tolower(temp);
		if (temp == letter_char) { //checks if guessed letter is in the word
			return true;
		}
	}
	return false;
}




