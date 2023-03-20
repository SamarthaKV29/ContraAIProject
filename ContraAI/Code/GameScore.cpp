#include "GameScore.h"

GameScore gamescore;

String GameScore::scoreAsText(){
		ostringstream strscor;
		strscor << score;
        return strscor.str().c_str();
	}

int GameScore::getScore(){
		return score;
	}
void GameScore::setScore(int s){
		score = s;
	}

void GameScore::updateScore(int s){
	score += s;
}