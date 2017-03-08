/* Game - TicTacToe
** Author - Can Chen
** Contact - canchen@me.com
** Git - https://github.com/CCinCapital
*/

#include "Input.h"

Input::Input() {
	// Do Nothing
}

int Input::Int() {
	while (true) {
		if (cin >> _int) break;
		cout << "Invalid Input, try again." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return _int;
}

int Input::IntWithInRangeMinMax(int min, int max) {
	while (true) {
		if ((cin >> _int) && (_int >= min) && (_int <= max)) break;
		cout << "Invalid Input, try again." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return _int;
}

string Input::String() {
	while (true) {
		if (cin >> _string) break;
	}
	return _string;
}

char Input::FirstCharOfString() {
	while (true) {
		if (cin >> _string) break;
	}
	cin.ignore();
	return _string.at(0);
}

char Input::Char() {
	while (true) {
		if (cin >> _char) break;
	}
	return _char;
}

/*
** Extract first two ints from string.
** Eg. "asd12 asdasd32" -> extracted: 12 32 -> x=12, y=32
*/
void Input::ExtractFirstTwoIntsFromString(int &x, int &y) {
	// Read Input Stream to _string
	getline(cin, _string);

	// If stream _string does not contain enough int blocks
	// Read again.
	while (countIntBlocks(_string) <= 1) {
		cout << "Invalid Input, try again." << endl;
		getline(cin, _string);
	}

															// <- _string guareenteed to contain at least two int blocks
	unsigned int n = 0;										// Set starting position of iteration at the beginning of _string
	string tempX;
	for (unsigned int i = n; i < _string.size(); i++) {		// Iterate through each character of _string
		if (isdigit(_string[i])) {							// If the char is a digit -> found a int block
			n = i;											//	  Record this position
			while (isdigit(_string[n])) {					// Read all the ints of this int block
				tempX += _string[n];						// Add digits to the tempX string
				n += 1;										// Update the position
			}
			break;											// Finish to read the FIRST int block
		}
	}

	string tempY;
	for (unsigned int i = n; i < _string.size(); i++) {		// Set starting position of iteration to the end point of last int block
															// Iterate through each character of _string
		if (isdigit(_string[i])) {							// If the char is a digit -> found a int block
			n = i;											//	  Record this position
			while (isdigit(_string[n])) {					// Read all the ints of this int block
				tempY += _string[n];						// Add digits to the tempX string
				n += 1;										// Update the position
			}
			break;											// Finish to read the SECOND int block
		}
	}
	x = stoi(tempX);										// Convert tempX from string to int and store it as x
	y = stoi(tempY);										// Convert tempY from string to int and store it as y
}


/*
** Count int blocks with in one string
** Eg. "asd12 asdasd32" -> extracted: 12 32 -> count = 2;
** Input:  string
** Return: count
*/
int countIntBlocks(string str) {
	int count = 0;
	bool lastCharWasDigit = false;
	for (unsigned int i = 0; i < str.size(); i++) {			// Iterate through each char of the string
		if (isdigit(str[i])) {								// If the current char is digit
			if (lastCharWasDigit == false) {				//	  If the last char was not digit
				count += 1;									// Found a int block
				lastCharWasDigit = true;					// Update the lastCharWasDigit flag to true
			}
		}
		else {												// If the current char is not digit
			lastCharWasDigit = false;						// Update the lastCharWasDigit flag to false
		}
	}														// Back to top to test next char
	return count;											// Return the int block counter
}