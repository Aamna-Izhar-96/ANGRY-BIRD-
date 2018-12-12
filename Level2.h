#include <glut.h>
#include "Medium.h"

class Level2
{
public :
	Medium MediumLevel;
	void StartLevel();
	TrapBirds Image;
	Projectile MediumObject;
	void  BuildMediumObjectList();
	void SetScale(Point2 Point);
	float ScaleX = 15, ScaleY = 4, Cx = 0, Cy = 4;
};

void Level2::StartLevel()
{

	MediumLevel.LoadBirds();
	Image.LoadImg(20, "bg2.bmp", 255, 255, 255);
	Image.RenderImage(-20, -20, 20);
	MediumLevel.RenderBirds();
	MediumLevel.DrawMedCages();
}


void Level2::BuildMediumObjectList()
{
	MediumObject.SetVelocity(20);
	MediumObject.SetTimeOfFLight();
	MediumObject.SetScaleX(ScaleX);
	MediumObject.SetScaleY(ScaleY);
	float Time = 0, PointsRange = 100;
	float TimeInc = MediumObject.GetTimeOfFlight() / PointsRange;
	for (int i = 0; i < 100; i++)
	{
		MediumObject.SetDistance(Time);
		Time += TimeInc;

	}
}

void Level2::SetScale(Point2 Point)
{
	ScaleX = Point.getX();
	ScaleY = Point.getY();
}
