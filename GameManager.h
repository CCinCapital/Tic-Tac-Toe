/* Game - TicTacToe
** Author - Can Chen
** Contact - canchen@me.com
** Git - https://github.com/CCinCapital
*/

#pragma once

#include <iostream>
#include <stdio.h>
#include <string>

#include "Board.h"
#include "Input.h"
#include "Player.h"
#include "Message.h"

using namespace std;

class GameManager {
	/*
	**	Game Pre-set Parameters
	*/
	static const int _minPlayers = 2;
	static const int _maxPlayers = 9;
	static const int _minBoardSize = 3;
	static const int _maxBoardSize = 15;
	static const int _minMarkersToWin = 3;
				 int _maxMarkersToWin = 5;		//	Will Change corresponding to board size (3xN or 4xN)

	bool _gameOver = false;
	bool _anotherGame = true;

	/*
	**	User Defined Parameters
	*/
	int _totalPlayers = _minPlayers;
	int _boardCol = _minBoardSize;
	int _boardRow = _minBoardSize;
	int _markerToWin = _minMarkersToWin;
	int _col = 0;								//	X-Y to place next marker on game board
	int _row = 0;								//	X-Y to place next marker on game board

	string _name[_maxPlayers] = {};				//	Player _name   - Will only use _name[0]~_name[_totalPlayers]
	char _symbol[_maxPlayers] = {};				//	Player _symbol - defined by the each player

public:
	GameManager();
	void Start();
};
