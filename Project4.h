/*
 * Project4.h
 *
 *  Created on: Apr 23, 2021
 *      Author: mmarr
 */

#ifndef PROJECT4_H_
#define PROJECT4_H_
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
using namespace std;
const int LETTERS_NUM = 26;
const int GALLOW_NUM = 8;

static void my_code();
int load_words(string filename);
string create_string(string filename, int n);
bool check_word(string letter, int size, string word);
string position(string letter, int n, string word, string asterisks);
char change_gallow(int g_cnt, char array[GALLOW_NUM][GALLOW_NUM]);
void display_gallow(char array[GALLOW_NUM][GALLOW_NUM]);
char list(char empty_letters[LETTERS_NUM], string letter);
bool check_list(char empty_letters[LETTERS_NUM], string letter);
bool check_asterisks(string asterisks, int size);




#endif /* PROJECT4_H_ */
