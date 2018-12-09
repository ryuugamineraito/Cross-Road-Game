#ifndef _CANIMAL_H_
#define _CANIMAL_H_
#include <iostream>
#include <Windows.h>
class CAnimal
{
protected:
	int mX, mY;

public:
	virtual void Tell() = 0;
	virtual void Move(int lv) = 0;
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getType() = 0;
};
#endif // !_CANIMAL_H_

