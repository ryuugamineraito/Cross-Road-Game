#ifndef _CVEHICLE_H_
#define _CVHICLE_H_
#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <time.h>
class CVehicle
{
protected:
	int mX,mY;

public:
	//CVehicle();
	virtual void Move(int lv)=0;
	virtual int getX()=0;
	virtual int getY() = 0;
	virtual int getType() = 0;
};
class CTrafficLight
{
private:
	bool color;
public:
	CTrafficLight();
	//void DrawTrafficLight();
	void SetColor(bool color);
	bool Color();
};
#endif // !_CVEHICLE_H_

