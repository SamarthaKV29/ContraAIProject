#include "util.h"


Stack::Stack(){}

void Stack::push(DOUBLE2 val){
	indx = mylist.end();
	mylist.insert(indx, val);
}

DOUBLE2 Stack::pop(){
	if(isEmpty())
		return DOUBLE2(0,0);
	return mylist.back();
}

bool Stack::isEmpty(){
	if(mylist.empty())
		return true;
	return false;
}

double manhattanDist(DOUBLE2 p1, DOUBLE2 p2){
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

Direction::Direction(){
	UP = "U";
	DOWN = "D";
	LEFT = "L";
	RIGHT = "R";
	STOP = "S";
}