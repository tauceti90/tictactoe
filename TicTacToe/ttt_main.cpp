#include <iostream>
#include <cassert>
#include "Board.h"
#include "Player.h"

using namespace std;

int main()
{
	Board brd;
	Player *p_humanPlayer = new HumanPlayer();
	Player *p_aiPlayer = new AiPlayer();
	Board::player p = Board::NONE;
	
	brd.printBoard();

	while (true)
	{
		p_humanPlayer->play(brd);
		p = brd.getWinner();
		brd.printBoard();
		if (p != Board::NONE)
		{
			break;
		}
		p_aiPlayer->play(brd);
		if (p != Board::NONE)
		{
			break;
		} //change the pointer type instead of having this twice.. currentplayer = (currentplayer == p_aiplayer? humanplayer : aiplayer)
		p = brd.getWinner();
		brd.printBoard();
	}

	if (p == Board::TIE)
	{
		cout << "No one won" << endl;
	}
	else if (p == Board::AI_PLAYER)
	{
		cout << "o wins" << endl;
	}
	else if (p == Board::HUMAN_PLAYER)
	{
		cout << "x wins" << endl;
	}
	else
	{
		assert(false, "Unexpected winner");
	}
}