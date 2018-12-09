#ifndef _CDINOSAUR_H_
#define _CDINOSAUR_H_
#include "CAnimal.h"
class CDinosaur :public CAnimal
{
	int type = 1;
public:
	int getType();
	void Tell();
	CDinosaur(int x, int y);
	CDinosaur(int distance);
	void Move(int lv);
	int getX();
	int getY();
};
#endif // !_CDINOSAUR_H_

