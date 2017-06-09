#pragma once


/**
Class representing Tic-Tac-Toe 'board'
*/
class Board
{
	
public:
	
	Board();

	enum player : char
	{
		HUMAN_PLAYER = 'x',
		AI_PLAYER = 'o',
		NONE = ' ', //no winner yet, the game is still in progress
		TIE, // its a tie, game ended.
	};

	void markBoard(char position, player sym);
	player mark(char position);
	int getRandomMove();
	void printBoard();
	player getWinner();

private:
	
	player board_[9]; // I can't think of a tic-tac-toe game that's not 3 x 3
	                  // instead of char enum change board to a bit mask.
};