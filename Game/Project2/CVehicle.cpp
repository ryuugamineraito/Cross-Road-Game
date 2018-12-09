#include "CVehicle.h"
CTrafficLight::CTrafficLight()
{
	color = true;//true green,false red
}
void CTrafficLight::SetColor(bool t)
{
	color = t;
}
bool CTrafficLight::Color()
{
	return color;
}