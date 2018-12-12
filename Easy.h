#pragma once
#include <glut.h>
#include "RGBA.h"
#include "Cage.h"
//#include  "TrapBirds.h"

class Easy
{
public:
	Cage EasyCage[3];
	TrapBirds EasyBirds[10];
	void DrawEasyCages();
	void LoadBirds();
	void RenderBirds();
	void AnimationCage1();
	void AnimationCage2();
	void AnimationCage3();
};

void Easy::DrawEasyCages()
{
	EasyCage[0].DrawCage(3, 1,1.5, EasyCage[0].openLid); // Cages
	EasyCage[0].DrawLock(3,2,0.7);

	EasyCage[1].DrawCage(7.5, 4, 2, EasyCage[1].openLid);
	EasyCage[1].DrawLock(13, 8,0.7);

	EasyCage[2].DrawCage(6, -5, 2, EasyCage[2].openLid);
	EasyCage[2].DrawLock(10, -10, 0.7);
}
void Easy::LoadBirds()
{
	EasyBirds[0].LoadImg(0, "s1.bmp", 255, 0, 0);
	EasyBirds[0].LoadImg(1, "s2.bmp", 255, 0, 0);
	EasyBirds[0].SetPosition(3, -0.9);
	EasyBirds[0].ImgID = 0;


	EasyBirds[1].LoadImg(2, "bred1.bmp", 0, 0, 255);
	EasyBirds[1].LoadImg(3, "bred2.bmp", 0, 0, 255);
	EasyBirds[1].SetPosition(14, 5);
	EasyBirds[1].ImgID = 2;


	EasyBirds[2].LoadImg(4, "bgreen1.bmp", 255, 0, 0);
	EasyBirds[2].LoadImg(5, "bgreen2.bmp", 255, 0, 0);
	EasyBirds[2].SetPosition(14, 7);
	EasyBirds[2].ImgID = 4;

	EasyBirds[3].LoadImg(6, "byellow1.bmp", 255, 0, 0);
	EasyBirds[3].LoadImg(7, "byellow2.bmp", 255, 0, 0);
	EasyBirds[3].SetPosition(12, -12);
	EasyBirds[3].ImgID = 6;

	EasyBirds[4].LoadImg(8, "bpink1.bmp", 255, 0, 0);
	EasyBirds[4].LoadImg(9, "bpink2.bmp", 255, 0, 0);
	EasyBirds[4].SetPosition(11, -11);
	EasyBirds[4].ImgID = 8;
}
void Easy::RenderBirds()
{
	EasyBirds[0].RenderImage(EasyBirds[0].PosX, EasyBirds[0].PosY, EasyBirds[0].ImgID); // birdies rendering
	EasyBirds[1].RenderImage(EasyBirds[1].PosX, EasyBirds[1].PosY, EasyBirds[1].ImgID);
	EasyBirds[2].RenderImage(EasyBirds[2].PosX, EasyBirds[2].PosY, EasyBirds[2].ImgID);
	EasyBirds[3].RenderImage(EasyBirds[3].PosX, EasyBirds[3].PosY, EasyBirds[3].ImgID);
	EasyBirds[4].RenderImage(EasyBirds[4].PosX, EasyBirds[4].PosY, EasyBirds[4].ImgID);
}

void Easy::AnimationCage1()
{
	EasyCage[0].openLid = 1;

	if (EasyBirds[0].IsUp == 1)
	{
		EasyBirds[0].IsUp = 0;
		EasyBirds[0].IsDown = 1;
		EasyBirds[0].ImgID = 0;
	}

	else if (EasyBirds[0].IsUp == 0)
	{
		EasyBirds[0].IsUp = 1;
		EasyBirds[0].IsDown = 0;
		EasyBirds[0].ImgID = 1;
	}
	EasyBirds[0].PosY++;
	EasyBirds[0].PosX -= 0.2;
}

void Easy::AnimationCage2()
{
	EasyCage[1].openLid = 1;

	if (EasyBirds[1].IsUp == 1)
	{
		EasyBirds[1].IsUp = 0;
		EasyBirds[1].IsDown = 1;
		EasyBirds[1].ImgID = 2;
		EasyBirds[2].ImgID = 4;
	}

	else if (EasyBirds[1].IsUp == 0)
	{
		EasyBirds[1].IsUp = 1;
		EasyBirds[1].IsDown = 0;
		EasyBirds[1].ImgID = 3;
		EasyBirds[2].ImgID = 5;
	}
	EasyBirds[1].PosY++;
	EasyBirds[1].PosX -= 0.3;
	EasyBirds[2].PosY += 0.8;
	EasyBirds[2].PosX -= 0.2;

}

void Easy::AnimationCage3()
{
	EasyCage[2].openLid = 1;

	if (EasyBirds[3].IsUp == 1)
	{
		EasyBirds[3].IsUp = 0;
		EasyBirds[3].IsDown = 1;
		EasyBirds[3].ImgID = 6;
		EasyBirds[4].ImgID = 8;
	}

	else if (EasyBirds[3].IsUp == 0)
	{
		EasyBirds[3].IsUp = 1;
		EasyBirds[3].IsDown = 0;
		EasyBirds[3].ImgID = 7;
		EasyBirds[4].ImgID = 9;
	}
	EasyBirds[3].PosY++;
	EasyBirds[3].PosX -= 0.3;
	EasyBirds[4].PosY += 0.7;
	EasyBirds[4].PosX -= 0.2;

}