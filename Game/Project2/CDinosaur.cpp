#include "CDinosaur.h"
CDinosaur::CDinosaur(int distance)
{
	mX = 11;
	mY = 66-distance;
}
CDinosaur::CDinosaur(int x, int y)
{
	mX = x;
	mY = y;
}
void CDinosaur::Move(int lv)//implement generally, still need some arguement to speed up :))
{
	mY -= (1+lv);
	if (mY <= 3)
		mY = 66;
}
int CDinosaur::getX()
{
	return mX;
}
int CDinosaur::getY()
{
	return mY;
}
int CDinosaur::getType()
{
	return type;
}
void CDinosaur::Tell()
{
	PlaySound(NULL, NULL, SND_ASYNC);
	PlaySound(TEXT("mtrex.wav"), NULL, SND_FILENAME);
}