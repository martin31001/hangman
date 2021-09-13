/*
 * gallow_functions.cpp
 *
 *  Created on: Apr 28, 2021
 *      Author: mmarr
 */

#include "Project4.h"

void display_gallow(char array[GALLOW_NUM][GALLOW_NUM]) {
	for (int row = 0; row < GALLOW_NUM; row++) {
		for (int col = 0; col < GALLOW_NUM; col++) {
			cout << array[row][col]; //display char array
		}
		cout << endl;
	}
}

char change_gallow(int g_cnt, char array[GALLOW_NUM][GALLOW_NUM]) {
	//Original
	if (g_cnt == 0) {
		array[0][0] = '+';
		for (int row = 1; row < 7; row++) {
			array[row][0] = '|';
		}
		array[7][0] = '+';
		for (int col = 1; col < 7; col++) {
			array[7][col] = '-';
		}
	}
	//First
	if (g_cnt == 1) {
		for (int col = 1; col < 5; col++) {
			array[0][col] = '-';
		}
		array[0][5] = '+';
	}
	//Second
	if (g_cnt == 2) {
		array[1][5] = '|';
	}
	//Third
	if (g_cnt == 3) {
		array[2][5] = 'O';
	}
	//Fourth
	if (g_cnt == 4) {
		array[3][5] = '|';
		array[4][5] = '|';
	}
	//Fifth
	if (g_cnt == 5){
		array[3][4] = '\\';
	}
	//Sixth
	if (g_cnt == 7){
		array[5][4] = '/';
		}
	//Seventh
	if (g_cnt == 6){
		array[3][6] = '/';
	}
	//Eighth
	if (g_cnt == 8){
		array[5][6] = '\\';
	}
	return array[GALLOW_NUM][GALLOW_NUM];
}


