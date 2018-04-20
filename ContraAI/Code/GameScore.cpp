#include "GameScore.h"

GameScore gamescore;

String GameScore::scoreAsText(){
		ostringstream oOStrStream;
		oOStrStream << score;
		string res = oOStrStream.str();
		String res_ = "";
		for(int i = 0; i < res.length(); i++){
			String t = String(res.at(i));
			res_ += t;
		}	
		return res_;
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