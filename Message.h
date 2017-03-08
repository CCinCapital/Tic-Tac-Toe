/* Game - TicTacToe
** Author - Can Chen
** Contact - canchen@me.com
** Git - https://github.com/CCinCapital
*/

#pragma once

#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

class Message {
	enum number {
		first = 0,
		second,
		third,
		fouth,
		fifth,
		sixth,
		seventh,
		eighth,
		ninth
	};

public:
	Message();

	void WelcomeMessage();
	void AskForBoardWidth(int minBoardSize, int maxBoardSize);
	void AskForBoardHeight(int minBoardSize, int maxBoardSize);
	void AskForWinCondition(int minMarkersToWin, int maxMarkersToWin);
	void AskForTotalPlayers(int minPlayers, int maxPlayers);
	void AskForNthPlayerName(int i);
	void HelloPlayer(string name);
	void AskForPlayerSymbol();
	void AskForCoordinateToPlaceNewMarker();
	void NewTurn(string name);
	void InvalidInput();
	void HasWonTheGame(string name);
	void AskForAnotherGame();
	void GameFinishedWithTie();
};
