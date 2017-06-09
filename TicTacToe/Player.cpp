#include "Player.h"
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

void HumanPlayer::play(Board& board)
{
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


	board.markBoard(pos, Board::HUMAN_PLAYER);
	//board.printBoard();

}


void AiPlayer::play(Board& board)
{

	//AiPlayer needs a simulation board
	Board simBoard(board);
	AiPlayer simHumanOpponent; //simulate the opponent
	int scores[9];

	for (int i = 0; i < 9; i++) 
	{
		if (board.mark(i) == Board::NONE) 
		{
			scores[i] = 0;
		}
		else {
			scores[i] = INT_MIN; // don't go where marks already are
		}
	}

	const int WIN_SCORE = 1;
	const int LOSE_SCORE = -10;
	const int TIE_SCORE = 0;
	const int NUM_SIMULATIONS = 5;

	for (int i = 0; i < NUM_SIMULATIONS; i++)
	{

		ofstream myfile;
		if (i == 0)
		{
			myfile.open("mine.txt");
		}
		else
		{
			myfile.open("mine.txt", ios::app);
		}
		myfile << "Sim count: " << i << endl;
		myfile.close();

		//reset simulation board
		simBoard = board;

		int firstMove = simBoard.getRandomMove();
		simBoard.markBoard(firstMove, Board::AI_PLAYER);
		simBoard.printBoard();
		
		Board::player currentPlayer = Board::HUMAN_PLAYER;
		int winner;

		while (true)
		{
			int move = simBoard.getRandomMove();
			simBoard.markBoard(move, currentPlayer);
			simBoard.printBoard();
			winner = simBoard.getWinner();
			if (winner != Board::NONE)
			{
				break;
			}
			currentPlayer = (currentPlayer == Board::HUMAN_PLAYER ? Board::AI_PLAYER : Board::HUMAN_PLAYER);
		}

		if (winner == Board::AI_PLAYER)
		{
			scores[firstMove] += WIN_SCORE;
		}
		else if (winner == Board::HUMAN_PLAYER)
		{
			scores[firstMove] += LOSE_SCORE;
		}
		else if (winner == Board::TIE)
		{
			scores[firstMove] += TIE_SCORE;
		}
		else
		{
			assert(false, "Unexpected winner");
		}
	}

	//pick winner with highest score
	int maxScore = scores[0];
	for (int i = 1; i < 9; i++)
	{
		if (scores[i] > maxScore)
		{
			maxScore = scores[i];
		}
	}

	int winnerIndices[9];
	int numWinners = 0;

	for (int i = 0; i < 9; i++)
	{
		if (scores[i] == maxScore)
		{
			winnerIndices[numWinners++] = i;
		}
	}

	cout << "[";
	for (int i = 0; i < 9; i++)
	{
		if (scores[i] != INT_MIN)
		{
			cout << " "<<scores[i];
		}
		else
		{
			cout << " --";
		}
	}
	cout << "]" << endl;

	cout << "Best AI moves: [";
	for (int i = 0; i < numWinners; i++)
	{
		cout << winnerIndices[i] << " ";
	}
	cout << "]" << endl;

	int aimove = rand() % numWinners;
	printf("Ai selects %d \n", winnerIndices[aimove]);

	int markingPosition = winnerIndices[aimove];
	board.markBoard(markingPosition, Board::AI_PLAYER);

}