/* Game - TicTacToe
** Author - Can Chen
** Contact - canchen@me.com
** Git - https://github.com/CCinCapital
*/

#include "Board.h"

/*
** Default Constructor,
*/
Board::Board() {

}

/*
** Initiates Board's parameters
*/
Board::Board(int row, int col, int markerToWin) {
	_row = row;
	_col = col;
	_markerToWin = markerToWin;
	_totalSquares = row * col;
	_occupiedSuqares = 0;
}

/*
** - Put marker in the cell
** - Increments the _occupiedSuqares
*/
void Board::SetCell(int row, int col, char symbol) {
	board[row - 1][col - 1] = symbol;
	_occupiedSuqares += 1;
}

/*
** Draw the Board
*/
void Board::Draw(){
	cout << endl;

	// First row of the board (column index)	"    | 01 | 02 | 03 | ...."
	cout << "   ";
	for (int i = 1; i <= _row; i++) {
		cout << " | ";
		if (i < 10) {
			cout << "0";
		}
		cout << i;
	}
	cout << endl;

	// Rest rows of board
	for (int i = 0; i < _row; i++) {
		// Horizontal line						"---------------------...."
		for (int j = 0; j < _col; j++) {
			cout << "-----";
		}
		cout << "----";
		cout << endl;

		// Row index							" 01 "
		cout << " ";
		if (i < 9) {
			cout << "0";
		} 
		cout << i + 1;

		// Vertical Spacers	and cell content	" 01 |  # |    |  @ | ...." 
		for (int j = 0; j < _col; j++) {
			cout << " |  ";
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

bool Board::IsCellEmpty(int row, int col) {
	return board[row - 1][col - 1] == NULL;
}

bool Board::IsCellNotEmpty(int row, int col) {
	return board[row - 1][col - 1] != NULL;
}

bool Board::IsFullyFilled() {
	return _occupiedSuqares >= _totalSquares;
}


/*
**	Read from the left most element of each row
**  Count consecutive markers
**  Returns true : _consecutive markers >= total consecutive _markerToWin
**  Returns false: _consecutive markers < total consecutive _markerToWin
*/
bool Board::IsHorizontalConsecutive() {
	for (int i = 0; i < _row; i++) {										// test each row, starts from row 0
		_consecutive = 0;													// Count the _consecutive markers
		_previous = board[i][0];											// Store the first element of row i
		for (int j = 0; j < _col; j++) {									// iterate through each element on that row, starts at the first element
			if ((board[i][j] == _previous) && (_previous != NULL)) {		// Is this element same as previous one? 
				_consecutive += 1;											//	  If the element is a Marker, increment the counter
			}
			else {
				_consecutive = 1;											// If not, reset the counter
			}

			if (_consecutive >= _markerToWin) {								// If _markerToWin units of _consecutive markers are found
				return true;												//    Return the result
			}

			_previous = board[i][j];										// Store this element for next iteration
		}																	// Back to top for next element in column
	}																		// Back to top for next row

																			// If _markerToWin units of _consecutive markers are NOT found
	return false;															//    Return the result
}


/*
**	Read from the left most element of each column
**  Count consecutive markers
**  Returns true : _consecutive markers >= total consecutive _markerToWin
**  Returns false: _consecutive markers < total consecutive _markerToWin
*/
bool Board::IsVerticalConsecutive() {
	for (int j = 0; j < _col; j++) {										// test each row, starts from column 0
		_consecutive = 0;													// Count the _consecutive markers
		_previous = board[0][j];											// Store the first element of column i
		for (int i = 0; i < _row; i++) {									// iterate through each element on that column, starts at the first element
			if ((board[i][j] == _previous) && (_previous != NULL)) {		// Is this element same as previous one? 
				_consecutive += 1;											//	  If the element is a Marker, increment the counter
			}
			else {
				_consecutive = 1;											// If not, reset the counter
			}

			if (_consecutive >= _markerToWin) {								// If _markerToWin units of _consecutive markers are found
				return true;												//    Return the result
			}

			_previous = board[i][j];										// Store this element for next iteration
		}																	// Back to top for next element in row
	}																		// Back to top for next column

																			// If _markerToWin units of _consecutive markers are NOT found
	return false;															//    Return the result
}


/*
**	Iterate through the '/' and '\' diagonal elements on board
**  Count consecutive markers
**  Returns true : _consecutive markers >= total consecutive _markerToWin
**  Returns false: _consecutive markers < total consecutive _markerToWin
*/
bool Board::IsDiagonalConsecutive() {
	// temp 
	int row;
	int col;

	// Iterate through the '/' diagonal elements of board
	for (int i = _markerToWin - 1; i < (_col + _row - _markerToWin); i++) {	// Test each diagonal, starts from column (_markerToWin - 1)
																			//	  as it's impossible to win during this test on top-left and bottom-right corners
		_consecutive = 0;													// Count the _consecutive markers

		if (i < _col) {														// Define the starting element
			row = 0;														// o o x o o o o      o o o o x o o      o o o o o o x      o o o o o o o 
			col = i;														// o x o o o o o      o o o x o o o      o o o o o x o      o o o o o o o 
		}																	// x o o o o o o  ->  o o x o o o o  ->  o o o o x o o  ->  o o o o o o x
		else {																// o o o o o o o      o x o o o o o      o o o x o o o      o o o o o x o 
			row = i - _col + 1;												// o o o o o o o      x o o o o o o      o o x o o o o      o o o o x o o 
			col = _col - 1;													// o o o o o o o      o o o o o o o      o x o o o o o      o o o x o o o 
		}

		_previous = board[row][col];										// Store the first element of column to test
		while (row < _row && col >= 0) {									// Within the test range
			if ((board[row][col] == _previous) && (_previous != NULL)) {	// Compare each elements to the _previous one
				_consecutive += 1;											//	 If match -> increment the counter
			}
			else {	
				_consecutive = 1;											//	 Otherwise -> reset the counter
			}

			if (_consecutive >= _markerToWin) {								// If _markerToWin units of _consecutive markers are found 
				return true;												//     Return the result
			}
																			// Otherwise
			_previous = board[row][col];									// Store the current element for next iteration
			row += 1;														// Calculate the next element's position in board
			col -= 1;												
		}																	// Back to top for next element in '/' diagonal
	}																		// Back to top for next column


	// Iterate through the '\' diagonal elements of board
	for (int i = (_col + _row - _markerToWin); i > _markerToWin - 1; i--) {	// Test each diagonal, starts from column (_col + _row - _markerToWin)
																			//	  as it's impossible to win during this test on top-right and bottom-left corners
		_consecutive = 0;													// Count the _consecutive markers

		if (i > _col) {														// Define the starting element
			row = i - _col;													// o o o o o o o      o o o o o o o      x o o o o o o      o o o o x o o 
			col = 0;														// o o o o o o o      x o o o o o o      o x o o o o o      o o o o o x o 
		}																	// o o o o o o o  ->  o x o o o o o  ->  o o x o o o o  ->  o o o o o o x
		else {																// x o o o o o o      o o x o o o o      o o o x o o o      o o o o o o o
			row = 0;														// o x o o o o o      o o o x o o o      o o o o x o o      o o o o o o o 
			col = abs(i - _col);											// o o x o o o o      o o o o x o o      o o o o o x o      o o o o o o o 
		}

		_previous = board[row][col];										// Store the first element of column to test
		while (row < _row && col < _col) {									// Within the test range
			if ((board[row][col] == _previous) && (_previous != NULL)) {	// Compare each elements to the _previous one
				_consecutive += 1;											//	 If match -> increment the counter
			}
			else {
				_consecutive = 1;											//	 Otherwise -> reset the counter
			}

			if (_consecutive >= _markerToWin) {								// If _markerToWin units of _consecutive markers are found 
				return true;												//     Return the result
			}
																			// Otherwise
			_previous = board[row][col];									// Store the current element for next iteration
			row += 1;														// Calculate the next element's position in board
			col += 1;
		}																	// Back to top for next element in '/' diagonal
	}																		// Back to top for next column

																			// If _markerToWin units of _consecutive markers are NOT found
	return false;															//    Return the result
}