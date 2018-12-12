#include <glut.h>
#include "Easy.h"
class Level1
{
public:
	Easy EasyLevel;
	Bird Bird;
	TrapBirds Image;
	void StartLevel();
	Projectile EasyObject;
	void  BuildEasyObjectList();
	void SetScale(Point2 Point);
	float ScaleX = 15, ScaleY = 4 , Cx = 0 , Cy = 4;
private:
	
};

void Level1::StartLevel()
{

	EasyLevel.LoadBirds();
	Image.LoadImg(20, "bg2.bmp", 255, 255, 255);
	Image.RenderImage(-20, -20, 20);
	EasyLevel.RenderBirds();
	EasyLevel.DrawEasyCages();
	
	
}


void Level1::BuildEasyObjectList()
{
	EasyObject.SetVelocity(20);
	EasyObject.SetTimeOfFLight();
	EasyObject.SetScaleX(ScaleX);
	EasyObject.SetScaleY(ScaleY);
	float Time = 0, PointsRange = 100;
	float TimeInc = EasyObject.GetTimeOfFlight() / PointsRange;
	for (int i = 0; i < 100; i++)
	{
		EasyObject.SetDistance(Time);
		Time += TimeInc;

	}
}

void Level1::SetScale(Point2 Point)
{
	ScaleX = Point.getX();
	ScaleY = Point.getY();
}
