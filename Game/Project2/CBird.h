#ifndef _CBIRD_H_
#define _CBIRD_H_
#include "CDinosaur.h"
class CBird :public CAnimal
{
	int type = 2;
public:
	int getType();
	void Tell();
	CBird(int distance);
	CBird(int x, int y);
	void Move(int lv);
	int getX();
	int getY();
};
#endif // !_CBIRD_H_

