//============================================================================
// Name        : Project3.cpp
// Author      : Martin Marraccino
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
using namespace std;
#include "Project4.h"

int main() {
	bool game = true;
	while(game){
	string choice;
	my_code();
	cout << "Would you like to play again Y|N?" << endl;
	getline(cin, choice);
	if(choice[0] == 'Y' || choice[0] == 'y'){
		game = true;
	}
	if(choice[0] == 'N' || choice[0] == 'n'){
		game = false;
	}
	}
	return 0;
}

static void my_code(){
	int n;
		string filename;
		ifstream inFile; //file opener
		ofstream outFile;
		string word;
		string letter;
		char gallows[GALLOW_NUM][GALLOW_NUM];
		int g_cnt = 0;
		int guess = 0;
		cout << "Enter the filename" << endl;
		//filename = "word_3.txt"; //testing
		getline(cin, filename); //type file name
		n = load_words(filename);
		word = create_string(filename, n);
		//cout << "Word is " << word << endl; // testing
		//cout << "N is " << n << endl; //testing
		string asterisks(word);
		for (int i = 0; i < n; i++) {
			asterisks[i] = '*';
		}
		for (int row = 0; row < GALLOW_NUM; row++) {
			for (int col = 0; col < GALLOW_NUM; col++) {
				gallows[row][col] = ' ';
			}
		}
		outFile.open("results.txt");
		if (outFile.fail()) {
			cout << "Outfile Failed: Need the results text in source file" << endl;
		}
		outFile << "The chosen word is " << word << "\n" << endl; //output text to file
		int size = word.length();
		char empty_letters[LETTERS_NUM];
		for (int i = 0; i < LETTERS_NUM; i++) {
			empty_letters[i] = ' ';
		}
		while (1) {
			gallows[GALLOW_NUM][GALLOW_NUM] = change_gallow(g_cnt, gallows);
			display_gallow(gallows); //display gallows
			cout << asterisks << endl; //display asterisks words
			//check if asterisks are filled
			if (check_asterisks(asterisks, size)) {
				cout << "Congratulations! You've found the word" << endl;
				outFile << "The user successfully found the word." << endl;
				break;
			}
			cout << "Enter a letter" << endl;		//ask for letter guess
			getline(cin, letter);
			//check if letter was played
			if (check_list(empty_letters, letter)) {
				cout << "Letter already guessed" << endl;
				continue;
			}
			guess++;

			if (check_word(letter, size, word)) {
				cout << "Correct" << endl;	//bool check word for letter function
				asterisks = position(letter, n, word, asterisks); //same code as bool but return new asterik
				outFile << "The character " << letter << " was found!" << endl;
			} else {
				cout << "Incorrect" << endl;
				g_cnt++;
				outFile << "The character " << letter << " was not found! The error count is " << g_cnt << endl;
			}
			//put letter in array
			empty_letters[LETTERS_NUM] = list(empty_letters, letter);
			//checking gallow counter
			if(g_cnt == 8){
				gallows[GALLOW_NUM][GALLOW_NUM] = change_gallow(g_cnt, gallows);
				display_gallow(gallows); //display gallows
				cout << "Game Over: the chosen word was " << word << endl;
				outFile << "\nThe user failed to find the word." << endl;
				break;
			}
		}

		outFile.close();
}

