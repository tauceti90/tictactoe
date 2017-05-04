#include "Player.h"
#include <iostream>

using namespace std;

void HumanPlayer::play(Board& board)
{
	board.printBoard();
	int pos;
	while (true)
	{
		cout << "Enter position: ";
		cin >> pos;
		if (pos > 8 || pos < 0)
		{
			cout << "Position should be 0-8" << endl;
		}
		else
		{
			break;
		}
	}
	board.printBoard();

}


void AiPlayer::play(Board& board)
{

}