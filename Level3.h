#include <glut.h>
#include "Hard.h"

class Level3
{
public:
	hard HardLevel;
	void StartLevel();
	TrapBirds Image;
	Projectile HardObject;
	void  BuildHardObjectList();
	void SetScale(Point2 Point);
	float ScaleX = 15, ScaleY = -3, Cx = 0, Cy = 11;
};

void Level3::StartLevel()
{

	HardLevel.LoadBirds();
	Image.LoadImg(20, "bg2.bmp", 255, 255, 255);
	Image.RenderImage(-20, -20, 20);
	HardLevel.RenderBirds();
	HardLevel.DrawHardCages();
}


void Level3::BuildHardObjectList()
{
	HardObject.SetVelocity(20);
	HardObject.SetTimeOfFLight();
	HardObject.SetScaleX(ScaleX);
	HardObject.SetScaleY(ScaleY);
	float Time = 0, PointsRange = 100;
	float TimeInc = HardObject.GetTimeOfFlight() / PointsRange;
	for (int i = 0; i < 100; i++)
	{
		HardObject.SetDistance(Time);
		Time += TimeInc;

	}
}

void Level3::SetScale(Point2 Point)
{
	ScaleX = Point.getX();
	ScaleY = Point.getY();
}
