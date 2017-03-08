#include "Player.h"

Player::Player(string name, char symbol) {
	_name = name;
	_symbol = symbol;
}

string Player::getName() {
	return _name;
}

char Player::getSymbol() {
	return _symbol;
}