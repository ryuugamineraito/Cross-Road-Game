#include "CTruck.h"
CTruck::CTruck(int distance)
{
	mX = 19;
	mY = 66-distance;
}
CTruck::CTruck(int x, int y)
{
	mX = x;
	mY = y;
}
void CTruck::Move(int lv)//implement generally, still need some arguement to speed up :))
{
	mY -= (1+lv);
	if (mY <= 3)
		mY = 66;
}
int CTruck::getX()
{
	return mX;
}
int CTruck::getY()
{
	return mY;
}
int CTruck::getType()
{
	return type;
}