#include "GameEngine.h"
#include <vector>


class Stack{
private:
	vector<DOUBLE2> mylist;
	vector<DOUBLE2>::iterator indx;
public:
	Stack();
	void push(DOUBLE2 val);
	DOUBLE2 pop();
	bool isEmpty();
};

int manhattanDist(DOUBLE2 p1, DOUBLE2 p2);

class Direction{
public:
	String UP;
	String DOWN;
	String LEFT;
	String RIGHT;
	String STOP;
	Direction();
};