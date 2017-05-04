#include "Board.h"
#include <iostream>
#include <string>

using namespace std;

Board::Board()
{
	for (int i = 0; i < 9; i++)
	{
		board_[i] = NONE;
	}
}

void Board::markBoard(char position, player sym)
{
	board_[position] = sym;
}

Board::player Board::getWinner()
{
	/* board layout
	 0 1 2
	 3 4 5
	 6 7 8
	 We have a winner if any row, column or diagonal have the same symbol
	 */
	//rows
	if ((board_[0] == board_[1]) && (board_[1] == board_[2]) && (board_[0]!= NONE))
	{
		return board_[0];
	}
	else if ((board_[3] == board_[4]) && (board_[4] == board_[5]) && (board_[0] != NONE))
	{
		return board_[3];
	}
	else if ((board_[6] == board_[7]) && (board_[7] == board_[8]) && (board_[0] != NONE))
	{
		return board_[6];
	}
	//columns
	else if ((board_[0] == board_[3]) && (board_[3] == board_[6]) && (board_[0] != NONE))
	{
		return board_[0];
	}
	else if ((board_[1] == board_[4]) && (board_[4] == board_[7]) && (board_[1] != NONE))
	{
		return board_[1];
	}
	else if ((board_[2] == board_[5]) && (board_[5] == board_[8]) && (board_[2] != NONE))
	{
		return board_[2];
	}
	//diagonals
	else if ((board_[0] == board_[4]) && (board_[4] == board_[8]) && (board_[0] != NONE))
	{
		return board_[0];
	}
	else if ((board_[2] == board_[4]) && (board_[4] == board_[6]) && (board_[2] != NONE))
	{
		return board_[2];
	}
	else if ((board_[0] != NONE) && (board_[1] != NONE) && (board_[2] != NONE) &&
		(board_[3] != NONE) && (board_[4] != NONE) && (board_[5] != NONE) &&
		(board_[6] != NONE) && (board_[7] != NONE) && (board_[8] != NONE))
	{
		return TIE;
	}
	else
	{
		return NONE;
	}
}

void Board::printBoard()
{
	const char separator = '|';

	std::cout << "-------   -------" << endl;
	std::cout << separator << static_cast<char>(board_[0]) << separator << static_cast<char>(board_[1]) << separator << static_cast<char>(board_[2]) << separator << "   |0|1|2|"<< std::endl; //create a method to print these lines. Avoid code duplication
	//std::cout << "-------   -------" << endl;
	std::cout << separator << static_cast<char>(board_[3]) << separator << static_cast<char>(board_[4]) << separator << static_cast<char>(board_[5]) << separator << "   |3|4|5|" << std::endl;
	//std::cout << "-------   -------" << endl;
	std::cout << separator << static_cast<char>(board_[6]) << separator << static_cast<char>(board_[7]) << separator << static_cast<char>(board_[8]) << separator << "   |6|7|8|" << std::endl;
	std::cout << "-------   -------" << endl;
}