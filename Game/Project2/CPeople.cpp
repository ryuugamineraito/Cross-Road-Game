#include "CPeople.h"

CPeople::CPeople()
{
	mX = 22;
	mY = 34;
	mState = true;//true alive false die
}
CPeople::CPeople(int x, int y, int state)
{
	mX = x;
	mY = y;
	if (state == 1)
		mState = true;
	else
		mState = false;
}
void CPeople::rePos()
{
	mX = 22;
	mY = 34;
}
void CPeople::Up(const int& key)
{
	if (key == 87)
	{
		mX -= 1;
	}
	if (mX - 1 <= 0)
		mX = 1;
}
void CPeople::Down(const int& key)
{
	if (key == 83)
	{
		mX += 1;
	}
	if (mX > 23)
		mX = 23;
}
void CPeople::Left(const int& key)
{
	if (key == 65)
	{
		mY -= 1;
	}
	if (mY < 3)
		mY = 3;
}
void CPeople::Right(const int& key)
{
	if (key == 68)
	{
		mY += 1;
	}
	if (mY > 66)
		mY = 66;
}
bool CPeople::isDead()
{
	return !mState;
}
bool CPeople::isFinish()
{
	if(mX<4)
		return true;
	return false;
}
int CPeople::getX()
{
	return mX;
}
int CPeople::getY()
{
	return mY;
}
bool CPeople::isImpact(vector<CVehicle*> vehicles)
{
	int tmpX, tmpY;
	for (int i = 0; i < vehicles.size(); ++i)
	{
		tmpX = vehicles[i]->getX();
		tmpY = vehicles[i]->getY();
		if (vehicles[i]->getType() == 1)
		{
			if (mX == tmpX || mX == tmpX - 1||mX-1==tmpX||mX-1==tmpX-1)
				if (mY == tmpY || mY == tmpY - 1 || mY == tmpY + 1)
				{
					if (mState == true)
					{
						PlaySound(NULL, NULL, SND_ASYNC);
						PlaySound(TEXT("Car Crash 4  No Copyright Sound Effect-[AudioTrimmer.com].wav"), NULL, SND_FILENAME);
					}
					mState = false;
					
					return true;
				}
		}
		else
		{
			if (mX == tmpX || mX == tmpX - 1 || mX - 1 == tmpX || mX - 1 == tmpX - 1)// forget to check the head :))
				if (mY == tmpY || mY == tmpY - 1 || mY == tmpY + 1 || mY == tmpY + 2)
				{
					if (mState == true)
					{
						PlaySound(NULL, NULL, SND_ASYNC);
						PlaySound(TEXT("Car Crash 4  No Copyright Sound Effect-[AudioTrimmer.com].wav"), NULL, SND_FILENAME);
					}
					mState = false;
					return true;
				}
		}
	}
	return false;
}
bool CPeople::isImpact(vector<CAnimal*> animals)
{
	int tmpX, tmpY;
	for (int i = 0; i < animals.size(); ++i)
	{
		tmpX = animals[i]->getX();
		tmpY = animals[i]->getY();
		
			if (mX == tmpX || mX == tmpX - 1 || mX - 1 == tmpX || mX - 1 == tmpX - 1)// forget to check the head :))
				if (mY == tmpY || mY == tmpY - 1 || mY == tmpY + 1)
				{
					if (mState)
						animals[i]->Tell();
					mState = false;
					return true;
				}
		
	}
	return false;
}