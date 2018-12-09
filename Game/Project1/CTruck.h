#ifndef _CTRUCK_H_
#define _CTRUCK_H_
#include <string>
#include "CVehicle.h"
class CTruck :public CVehicle
{
public:
	CTruck(sf::RenderWindow *window);
	void update();
	//void draw();
private:
	char* image = "D:\\CS202\\Game\\Debug\\Media\\truck.png";
};
#endif // !_CTRUCK_H_

