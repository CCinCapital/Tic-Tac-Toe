/* Game - TicTacToe
** Author - Can Chen
** Contact - canchen@me.com
** Git - https://github.com/CCinCapital
*/

#include "Message.h"

Message::Message() {
	// Do Nothing
}

void Message::WelcomeMessage() {
	cout << "Welcome to Tic Tac Toe !" << endl;
}

void Message::AskForBoardWidth(int minBoardSize, int maxBoardSize) {
	cout << endl;
	cout << "How wide would like the board to be? ( Min:" << minBoardSize << " Max:" << maxBoardSize << " )" << endl;
}

void Message::AskForBoardHeight(int minBoardSize, int maxBoardSize) {
	cout << endl;
	cout << "How high would like the board to be? ( Min:" << minBoardSize << " Max:" << maxBoardSize << " )" << endl;
}

void Message::AskForWinCondition(int minMarkersToWin, int maxMarkersToWin) {
	cout << endl;
	cout << "How Many Markers Horizontal, Vertical, or Diagonal should needed to win? ( Min:" << minMarkersToWin << " Max:" << maxMarkersToWin << " )" << endl;
}


void Message::AskForTotalPlayers(int minPlayers, int maxPlayers) {
	cout << endl;
	cout << "How many players would be playing this game? ( Min:" << minPlayers << " Max: " << maxPlayers << " )" << endl;
}

void Message::AskForNthPlayerName(int i) {
	cout << endl;
	cout << "The ";
	switch (number(i)) {
		case first: cout << "first";		break;
		case second: cout << "second";		break;
		case third: cout << "third";		break;
		case fouth: cout << "fouth";		break;
		case fifth: cout << "fifth";		break;
		case sixth: cout << "sixth";		break;
		case seventh: cout << "seventh";	break;
		case eighth: cout << "eighth";		break;
		case ninth: cout << "ninth";		break;
	}
	cout << " player should enter their name:" << endl;
}

void Message::HelloPlayer(string name) {
	cout << "Hello " << name << endl;
}

void Message::AskForPlayerSymbol() {
	cout << "What would you like your symbol to be?" << endl;
}

void Message::AskForCoordinateToPlaceNewMarker() {
	cout << endl;
	cout << "Enter the X,Y coordinate where you wish to place your marker:" << endl;
}

void Message::NewTurn(string name) {
	cout << endl;
	cout << name << "'s turn!" << endl;
}

void Message::InvalidInput() {
	cout << "Invalid Input, try again." << endl;
}

void Message::HasWonTheGame(string name) {
	cout << name << " has Won the game!" << endl;
}

void Message::GameFinishedWithTie() {
	cout << "Tie! No more moves possible." << endl;
}

void Message::AskForAnotherGame() {
	cout << "Would you like to have another game? (Y/N)" << endl;
}

