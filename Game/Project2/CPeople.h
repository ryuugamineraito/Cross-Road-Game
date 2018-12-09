#ifndef _CPEOPLE_H_
#define _CPEOPLE_H_
#include <iostream>
#include <vector>
#include "CBird.h"
#include "CCar.h"
using namespace std;
class CPeople
{
public:
	CPeople();
	CPeople(int x, int y, int state);
	void Up(const int& key);
	void Left(const int& key);
	void Right(const int& key);
	void Down(const int& key);
	int getX();
	int getY();
	bool isImpact(vector<CVehicle*> vehicles);
	bool isImpact(vector<CAnimal*> animals);
	bool isFinish();
	bool isDead();
	void rePos();
private:
	int mX, mY;
	bool mState;
};
#endif // !_CPEOPLE_H_

