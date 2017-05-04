#include <iostream>
#include "Board.h"
#include "Player.h"

using namespace std;

int main()
{
	Board brd;
	Player *p_humanPlayer = new HumanPlayer();
	p_humanPlayer->play(brd);
	
}