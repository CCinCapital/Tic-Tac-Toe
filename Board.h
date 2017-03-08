/* Game - TicTacToe
** Author - Can Chen
** Contact - canchen@me.com
** Git - https://github.com/CCinCapital
*/

#pragma once

#include <iostream>

using namespace std;

class Board {
private:
	static const int _maxRow = 15;
	static const int _maxCol = 15;
	int _row;
	int _col;
	int _markerToWin;
	int _consecutive;
	char _previous;
	int _totalSquares;
	int _occupiedSuqares;

	char board[_maxRow][_maxCol] = {};

	Board();

public:
	Board(int row, int col, int markerToWin);

	void SetCell(int row, int col, char symbol);
	void Draw();

	bool IsCellEmpty(int row, int col);
	bool IsCellNotEmpty(int row, int col);

	// Test game over condition
	bool IsFullyFilled();

	// Tests winning condition (_consecutive markers)
	bool IsHorizontalConsecutive();
	bool IsVerticalConsecutive();
	bool IsDiagonalConsecutive();
};