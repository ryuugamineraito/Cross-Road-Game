#include "CBird.h"
CBird::CBird(int distance)
{
	mX = 6;
	mY = 3+distance;
}
CBird::CBird(int x, int y)
{
	mX = x;
	mY = y;
}
void CBird::Move(int lv)//implement generally, still need some arguement to speed up :))
{
	mY += 1+lv;
	if (mY > 66)
		mY = 3;
}
int CBird::getX()
{
	return mX;
}
int CBird::getY()
{
	return mY;
}
int CBird::getType()
{
	return type;
}
void CBird::Tell()
{
	PlaySound(NULL, NULL, SND_ASYNC);
	PlaySound(TEXT("Hawk-sound.wav"), NULL, SND_FILENAME);
}