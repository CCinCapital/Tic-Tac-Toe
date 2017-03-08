/* Game - TicTacToe
** Author - Can Chen
** Contact - canchen@me.com
** Git - https://github.com/CCinCapital
*/

#pragma once

#include <string>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

/*
** Count int blocks with in one string
** Eg. "asd12 asdasd32" -> extracted: 12 32 -> count = 2;
** Input:  string
** Return: count
*/
int countIntBlocks(string str);

class Input {
	int _int;
	char _char;
	string _string;

public:
	Input();

	int Int();
	int IntWithInRangeMinMax(int min, int max);

	string String();

	char Char();
	char FirstCharOfString();

	/*
	** Extract first two ints from string.
	** Eg. "asd12 asdasd32" -> extracted: 12 32 -> x=12, y=32
	*/
	void ExtractFirstTwoIntsFromString(int &x, int &y);
};