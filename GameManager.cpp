/* Game - TicTacToe
** Author - Can Chen
** Contact - canchen@me.com
** Git - https://github.com/CCinCapital
*/

#include "GameManager.h"

/*
** Default Constructor, 
*/
GameManager::GameManager() {
	// Do Nothing
}


/*
** Controls the flow fo game
*/
void GameManager::Start() {
	Message print;	// Output stream manager (Game Instructions)
	Input input;	// Input stream manager (Player Inputs)

	/*
	** Display welcome message, then ask user to define game parameters 
	*/
	print.WelcomeMessage();

	print.AskForBoardWidth(_minBoardSize, _maxBoardSize);
	_boardCol = input.IntWithInRangeMinMax(_minBoardSize, _maxBoardSize);

	print.AskForBoardHeight(_minBoardSize, _maxBoardSize);
	_boardRow = input.IntWithInRangeMinMax(_minBoardSize, _maxBoardSize);

	print.AskForTotalPlayers(_minPlayers, _maxPlayers);
	_totalPlayers = input.IntWithInRangeMinMax(_minPlayers, _maxPlayers);

	// if default winning condition (_maxMarkersToWin) exceeds the user defined board size (_boardCol and _boardRow)
	// lower the winning condition to match board size (smaller one between _boardCol and _boardRow)
	if (_boardRow < _maxMarkersToWin | _boardRow < _maxMarkersToWin) {
		_maxMarkersToWin = _boardCol < _boardRow ? _boardCol : _boardRow;
	}

	print.AskForWinCondition(_minMarkersToWin, _maxMarkersToWin);
	_markerToWin = input.IntWithInRangeMinMax(_minMarkersToWin, _maxMarkersToWin);

	/*
	** Let each player to choose their _name and _symbol
	*/
	for (int i = 0; i < _totalPlayers; i++) {

		print.AskForNthPlayerName(i);
		_name[i] = input.String();

		print.HelloPlayer(_name[i]);

		print.AskForPlayerSymbol();
		_symbol[i] = input.FirstCharOfString();

	}


	/* Keep running until player stop to play more games
	** - Stops when _anotherGame = false;
	*/
	do {
		// Create new playground instance
		Board board(_boardRow, _boardCol, _markerToWin);
		board.Draw();

		/* 
		** Keeps running for the duration of ONE game
		**
		** -				 Stops : _gameOver = true;
		** - _gameOver = true when : 1. One player has won the game. 
		**							 2. The board is fully filled
		*/
		_gameOver = false;
		// New round of current game
		while (_gameOver == false) {

			// Each player's turn
			for (int i = 0; i < _totalPlayers; i++) {

				print.NewTurn(_name[i]);
				print.AskForCoordinateToPlaceNewMarker();

				// Get user's input as a string, then extract first two Ints as coordinates (_row , _col)
				// Repeat until a valid input
				do {
					input.ExtractFirstTwoIntsFromString(_row, _col);
					if ((_col < 0) | (_col > _boardCol) | (_row < 0) | (_row > _boardRow) | (board.IsCellNotEmpty(_row, _col))) {
						print.InvalidInput();
					}
				} while ((_col < 0) | (_col > _boardCol) | (_row < 0) | (_row > _boardRow) | (board.IsCellNotEmpty(_row, _col)));

				// Put marker onto board
				board.SetCell(_row, _col, _symbol[i]);
				board.Draw();

				// Test if this player has won the game
				if (board.IsHorizontalConsecutive() | board.IsVerticalConsecutive() | board.IsDiagonalConsecutive() | board.IsFullyFilled()) {

					// Print message based on winning state
					if (board.IsFullyFilled()) {
						print.GameFinishedWithTie();
					}
					else {
						print.HasWonTheGame(_name[i]);
					}

					// End of current game instance
					_gameOver = true;	

					// Ask player to response
					print.AskForAnotherGame();					
					char inputChar = input.FirstCharOfString();		// Fetch player's response
					if (inputChar == 'N' | inputChar == 'n') {
						_anotherGame = false;						// Player decided not to play more games
					}

					break; // No more players may move during this round
				} 
				// This player has not won 
			} 
			// Player has not won the game, go to next player
		} 
		// No one won during current round, go to next round
	} while (_anotherGame == true);
}


