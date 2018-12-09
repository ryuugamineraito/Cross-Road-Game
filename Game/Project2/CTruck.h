#ifndef _CTRUCK_H_
#define _CTRUCK_H_
#include <string>
#include "CVehicle.h"
class CTruck :public CVehicle
{
	int type = 1;
public:
	int getType();
	CTruck(int distance);
	CTruck(int x, int y);
	void Move(int lv);
	int getX();
	int getY();
};
#endif // !_CTRUCK_H_

