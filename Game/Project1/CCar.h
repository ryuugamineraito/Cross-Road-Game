#ifndef _CCAR_H_
#define _CCAR_H_
#include "CTruck.h"
class CCar :public CVehicle
{
public:
	CCar(sf::RenderWindow *window);
	void update();
	//void draw();
private:
	char* image = "D:\\CS202\\Game\\Debug\\Media\\car.png";
};
#endif // !_CCAR_H_

