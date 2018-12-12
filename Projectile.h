#include <windows.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <glut.h>
#include <stdio.h>
#include <vector>
#include "vector.h"
#define Pi 3.141592654
#define Gravity 9.8

class Projectile
{
public:
	std::vector <vector2> VerticesList;
	void SetVelocity(float V);
	void SetAngle(float Angle);
	void SetTimeOfFLight();
	void SetDistance(float TimeInc);
	void SetScaleX(int sx);
	void SetScaleY(int sy);
	float GetAngle();
	float GetVelocity();
	float GetTimeOfFlight();
	vector2 GetDistance();

private:
	float vO;
	float Angle;
	float TimeOfFlight;
	vector2 Distance;
	int ScaleX, ScaleY;

};

void Projectile::SetScaleX(int Sx)
{
	this->ScaleX = Sx;
}
void Projectile::SetScaleY(int Sy)
{
	this->ScaleY = Sy;
}
void Projectile::SetAngle(float Angle)
{
	this->Angle = Angle;
}
void Projectile::SetVelocity(float V)
{
	this->vO = V;
}
void Projectile::SetTimeOfFLight()
{
	this->TimeOfFlight = (2 * vO*sin(Angle)) / Gravity;
}
void Projectile::SetDistance(float Time)
{
	float vxO = (vO*cos(Angle)*Time) - ScaleX;
	float vyO = ((vO*sin(Angle)*Time) - ((Gravity*Time*Time) / 2)) - ScaleY;
	this->Distance.set(vxO, vyO);
	VerticesList.push_back(Distance);

}
float Projectile::GetAngle()
{
	return this->Angle;

}
vector2 Projectile::GetDistance()
{
	return this->Distance;
}
float Projectile::GetTimeOfFlight()
{
	return this->TimeOfFlight;
}
float Projectile::GetVelocity()
{
	return this->vO;
}