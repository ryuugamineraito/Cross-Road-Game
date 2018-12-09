#ifndef _CCAR_H_
#define _CCAR_H_
#include "CTruck.h"
class CCar :public CVehicle
{
	int type = 2;
public:
	int getType();
	CCar(int distance);
	CCar(int x, int y);
	void Move(int lv);
	int getX();
	int getY();
};
#endif // !_CCAR_H_

