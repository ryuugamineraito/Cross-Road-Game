#include "CCar.h"
CCar::CCar(int distance)
{
	mX = 15;
	mY = 3+distance;
}
CCar::CCar(int x, int y)
{
	mX = x;
	mY = y;
}
void CCar::Move(int lv)//implement generally, still need some arguement to speed up :))
{
	mY += 1+lv;
	if (mY > 66)
		mY = 3;
}
int CCar::getX()
{
	return mX;
}
int CCar::getY()
{
	return mY;
}
int CCar::getType()
{
	return type;
}
