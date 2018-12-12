#pragma once

#include <glut.h>
#include "RGBA.h"
#include "cage.h"
//#include "TrapBirds.h"

class Medium
{
public:
	Cage MedCage[5];
	TrapBirds MedBirds[10];
	void DrawMedCages();
	void LoadBirds();
	void RenderBirds();
	void AnimationCage1();
	void AnimationCage2();
	void AnimationCage3();
	void AnimationCage4();
	void AnimationCage5();
	
};

void Medium::DrawMedCages()
{
	
	MedCage[0].DrawCage(1, 1, 2, MedCage[0].openLid);
	MedCage[0].DrawLock(0,1.5,0.7);
	MedCage[1].DrawCage(3.5, 9, 1.5, MedCage[1].openLid);
	MedCage[1].DrawLock(3.9,13.5,0.5);
	MedCage[2].DrawCage(5,1.2, 2.9, MedCage[2].openLid);
	MedCage[2].DrawLock(11.5,4,0.8);
	MedCage[3].DrawCage(5, -3.8, 2, MedCage[3].openLid);
	MedCage[3].DrawLock(8,-8,0.7);
	MedCage[4].DrawCage(10, -5.5, 1.5, MedCage[4].openLid);
	MedCage[4].DrawLock(13.5, -8.2, 0.5);
}
void Medium::LoadBirds()
{
	MedBirds[0].LoadImg(0, "s1.bmp", 255, 0, 0);
	MedBirds[0].LoadImg(1, "s2.bmp", 255, 0, 0);
	MedBirds[0].SetPosition(13, 1);
	MedBirds[0].ImgID = 0;

	MedBirds[1].LoadImg(2, "bpink1.bmp", 255, 0, 0);
	MedBirds[1].LoadImg(3, "bpink2.bmp", 255, 0, 0);
	MedBirds[1].SetPosition(15, 0.2);
	MedBirds[1].ImgID = 2;

	MedBirds[2].LoadImg(4, "bgreen1.bmp", 255, 0, 0);
	MedBirds[2].LoadImg(5, "bgreen2.bmp", 255, 0, 0);
	MedBirds[2].SetPosition(13, -1);
	MedBirds[2].ImgID = 4;

	MedBirds[3].LoadImg(6, "byellow1.bmp", 255, 0, 0);
	MedBirds[3].LoadImg(7, "byellow2.bmp", 255, 0, 0);
	MedBirds[3].SetPosition(14, -10);
	MedBirds[3].ImgID = 6;

	MedBirds[4].LoadImg(8, "bred1.bmp", 0, 0, 255);
	MedBirds[4].LoadImg(9, "bred2.bmp", 0, 0, 255);
	MedBirds[4].SetPosition(4, 11);
	MedBirds[4].ImgID = 8;

	MedBirds[5].LoadImg(10, "bgreen1.bmp", 255, 0,0);
	MedBirds[5].LoadImg(11, "bgreen2.bmp", 255, 0, 0);
	MedBirds[5].SetPosition(2, 1);
	MedBirds[5].ImgID = 10;

	MedBirds[6].LoadImg(12, "bblue1.bmp", 255, 0, 0);
	MedBirds[6].LoadImg(13, "bblue2.bmp", 255, 0, 0);
	MedBirds[6].SetPosition(0, -1.5);
	MedBirds[6].ImgID = 12;


	MedBirds[7].LoadImg(14, "bpink1.bmp", 255, 0, 0);
	MedBirds[7].LoadImg(15, "bpink2.bmp", 255, 0, 0);
	MedBirds[7].SetPosition(10, -10);
	MedBirds[7].ImgID = 14;

	MedBirds[8].LoadImg(16, "bgreen1.bmp", 255, 0, 0);
	MedBirds[8].LoadImg(17, "bgreen2.bmp", 255, 0, 0);
	MedBirds[8].SetPosition(9, -9);
	MedBirds[8].ImgID = 16;
}
void Medium::RenderBirds()
{
	MedBirds[0].RenderImage(MedBirds[0].PosX, MedBirds[0].PosY, MedBirds[0].ImgID);
	MedBirds[1].RenderImage(MedBirds[1].PosX, MedBirds[1].PosY, MedBirds[1].ImgID);
	MedBirds[2].RenderImage(MedBirds[2].PosX, MedBirds[2].PosY, MedBirds[2].ImgID);
	MedBirds[3].RenderImage(MedBirds[3].PosX, MedBirds[3].PosY, MedBirds[3].ImgID);
	MedBirds[4].RenderImage(MedBirds[4].PosX, MedBirds[4].PosY, MedBirds[4].ImgID);
	MedBirds[5].RenderImage(MedBirds[5].PosX, MedBirds[5].PosY, MedBirds[5].ImgID);
	MedBirds[6].RenderImage(MedBirds[6].PosX, MedBirds[6].PosY, MedBirds[6].ImgID);
	MedBirds[7].RenderImage(MedBirds[7].PosX, MedBirds[7].PosY, MedBirds[7].ImgID);
	MedBirds[8].RenderImage(MedBirds[8].PosX, MedBirds[8].PosY, MedBirds[8].ImgID);
}
void Medium::AnimationCage3()
{
	MedCage[2].openLid = 1;

	if (MedBirds[0].IsUp == 1)
	{
		MedBirds[0].IsUp = 0;
		MedBirds[0].IsDown = 1;
		MedBirds[0].ImgID = 0;
		MedBirds[1].ImgID = 2;
		MedBirds[2].ImgID = 4;
	}

	else if (MedBirds[0].IsUp == 0)
	{

	    MedBirds[0].IsUp = 1;
		MedBirds[0].IsDown = 0;
		MedBirds[0].ImgID = 1;
		MedBirds[1].ImgID = 3;
		MedBirds[2].ImgID = 5;
	}
	MedBirds[0].PosX -= 0.3;
    MedBirds[0].PosY++;

	MedBirds[1].PosX -= 0.5;
	MedBirds[1].PosY += 0.5;

	MedBirds[2].PosX -= 0.3;
	MedBirds[2].PosY += 0.8;
}

void Medium::AnimationCage1()
{
	MedCage[0].openLid = 1;

	if (MedBirds[5].IsUp == 1)
	{
		MedBirds[5].IsUp = 0;
		MedBirds[5].IsDown = 1;
		MedBirds[5].ImgID = 10;
		MedBirds[6].ImgID = 12;
	}

	else if (MedBirds[5].IsUp == 0)
	{

		MedBirds[5].IsUp = 1;
		MedBirds[5].IsDown = 0;
		MedBirds[5].ImgID = 11;
		MedBirds[6].ImgID = 13;
	}
	MedBirds[5].PosX -= 0.1;
	MedBirds[5].PosY+=1.5;

	MedBirds[6].PosX -= 0.2;
	MedBirds[6].PosY += 1.5;

}

void Medium::AnimationCage4()
{
	MedCage[3].openLid = 1;

	if (MedBirds[7].IsUp == 1)
	{
		MedBirds[7].IsUp = 0;
		MedBirds[7].IsDown = 1;
		MedBirds[7].ImgID = 14;
		MedBirds[8].ImgID = 16;
	}

	else if (MedBirds[7].IsUp == 0)
	{

		MedBirds[7].IsUp = 1;
		MedBirds[7].IsDown = 0;
		MedBirds[7].ImgID = 15;
		MedBirds[8].ImgID = 17;
	}
	MedBirds[7].PosX -= 0.2;
	MedBirds[7].PosY += 1;

	MedBirds[8].PosX -= 0.1;
	MedBirds[8].PosY += 1.5;
}
void Medium::AnimationCage2()
{
	MedCage[1].openLid = 1;

	if (MedBirds[4].IsUp == 1)
	{
		MedBirds[4].IsUp = 0;
		MedBirds[4].IsDown = 1;
		MedBirds[4].ImgID = 8;
		
	}

	else if (MedBirds[4].IsUp == 0)
	{

		MedBirds[4].IsUp = 1;
		MedBirds[4].IsDown = 0;
		MedBirds[4].ImgID = 9;
		
	}
	MedBirds[4].PosX -= 0.2;
	MedBirds[4].PosY += 1;

	
}
void Medium::AnimationCage5()
{

	MedCage[4].openLid = 1;

	if (MedBirds[3].IsUp == 1)
	{
		MedBirds[3].IsUp = 0;
		MedBirds[3].IsDown = 1;
		MedBirds[3].ImgID = 6;

	}

	else if (MedBirds[3].IsUp == 0)
	{

		MedBirds[3].IsUp = 1;
		MedBirds[3].IsDown = 0;
		MedBirds[3].ImgID = 7;

	}
	MedBirds[3].PosX -= 0.5;
	MedBirds[3].PosY += 2;


}