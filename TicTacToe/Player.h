#pragma once
#include "Board.h"

class Player
{
public:
	virtual void play(Board& board) = 0;
};

class HumanPlayer : public Player
{
public:
	void play(Board& board) override;
};

class AiPlayer : public Player
{

public:
	void play(Board& board) override;

};