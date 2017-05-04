#pragma once


/**
Class representing Tic-Tac-Toe 'board'
*/
class Board
{
private:

	enum player : char
	{
		HUMAN_PLAYER = 'x',
		AI_PLAYER = 'o',
		NONE = ' ', //no winner yet, the game is still in progress
		TIE, // its a tie, game ended.
	};
	player board_[9]; // I can't think of a tic-tac-toe game that's not 3 x 3
	
public:
	
	Board();

	void markBoard(char position, player sym);
	void printBoard();
	player getWinner();
};