#ifndef GAMESCORE_H
#define GAMESCORE_H
#include "GameEngine.h"

class GameScore{
private:
	int score;
public:
	GameScore()
		:score(0)
	{}
	String scoreAsText();
	int getScore();
	void setScore(int s);
	void updateScore(int s);
};


extern GameScore gamescore;
#endif