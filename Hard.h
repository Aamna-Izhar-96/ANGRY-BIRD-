#pragma once
#include <glut.h>
#include "RGBA.h"
#include "cage.h"


class hard
{
public:
	Cage HardCage[7];
	TrapBirds HardBirds[13];
	void DrawHardCages();
	void LoadBirds();
	void RenderBirds();
	void AnimationCage1();
	void AnimationCage2();
	void AnimationCage3();
	void AnimationCage4();
	void AnimationCage5();
	void AnimationCage6();
	void AnimationCage7();
};

void hard::DrawHardCages()
{
	HardCage[0].DrawCage(1, 0.4, 2, HardCage[0].openLid);
	HardCage[0].DrawLock(0, 0.3, 0.7);
	HardCage[1].DrawCage(4, -4.9, 1.5, HardCage[1].openLid);
	HardCage[1].DrawLock(4.5, -7.5, 0.5);
	HardCage[2].DrawCage(3.5, 9, 1.5, HardCage[2].openLid);
	HardCage[2].DrawLock(3.9, 13.5, 0.6);
	HardCage[3].DrawCage(-1.5, 6.2, 1.5, HardCage[3].openLid);
	HardCage[3].DrawLock(-3.9, 9, 0.6);
	HardCage[4].DrawCage(-7, 1.2, 1.2, HardCage[4].openLid);
	HardCage[4].DrawLock(-9.5, 1.5, 0.4);
	HardCage[5].DrawCage(-1.6, -6.2, 1.2, HardCage[5].openLid);
	HardCage[5].DrawLock(-3, -7.5, 0.4);
	HardCage[6].DrawCage(12, 12, 1.2, HardCage[6].openLid);
	HardCage[6].DrawLock(13.2, 14, 0.4);

}

void hard::LoadBirds()
{
	// cage 0 birds
	HardBirds[0].LoadImg(0, "s1.bmp", 255, 0, 0);
	HardBirds[0].LoadImg(1, "s2.bmp", 255, 0, 0);
	HardBirds[0].SetPosition(-0.2, -2.2);
	HardBirds[0].ImgID = 0;

	HardBirds[1].LoadImg(2, "bgreen1a.bmp", 255, 0, 0);
	HardBirds[1].LoadImg(3, "bgreen2a.bmp", 255, 0, 0);
	HardBirds[1].SetPosition(1.8, -2.1);
	HardBirds[1].ImgID = 2;

	HardBirds[2].LoadImg(4, "bpink1.bmp", 255, 0, 0);
	HardBirds[2].LoadImg(5, "bpink2.bmp", 255, 0, 0);
	HardBirds[2].SetPosition(0.3, 1.2);
	HardBirds[2].ImgID = 4;

	HardBirds[3].LoadImg(6, "byellow1a.bmp", 255, 0, 0);
	HardBirds[3].LoadImg(7, "byellow2a.bmp", 255, 0, 0);
	HardBirds[3].SetPosition(1.8, 0);
	HardBirds[3].ImgID = 6;

	// cage 1 birds
	HardBirds[4].LoadImg(8, "bpink1a.bmp", 255, 0, 0);
	HardBirds[4].LoadImg(9, "bpink2a.bmp", 255, 0, 0);
	HardBirds[4].SetPosition(5, -10);
	HardBirds[4].ImgID = 8;

	HardBirds[5].LoadImg(10, "bblue1a.bmp", 255, 0, 0);
	HardBirds[5].LoadImg(11, "bblue2a.bmp", 255, 0, 0);
	HardBirds[5].SetPosition(4.5, -9);
	HardBirds[5].ImgID = 10;

	// cage 2

	HardBirds[6].LoadImg(12, "bpink1.bmp", 255, 0, 0);
	HardBirds[6].LoadImg(13, "bpink2.bmp", 255, 0, 0);
	HardBirds[6].SetPosition(4, 11);
	HardBirds[6].ImgID = 12;

	HardBirds[7].LoadImg(14, "bgreen1a.bmp", 255, 0, 0);
	HardBirds[7].LoadImg(15, "bgreen2a.bmp", 255, 0, 0);
	HardBirds[7].SetPosition(4.7, 12);
	HardBirds[7].ImgID = 14;

	// cage 3

	HardBirds[8].LoadImg(16, "byellow1.bmp", 255, 0, 0);
	HardBirds[8].LoadImg(17, "byellow2.bmp", 255, 0, 0);
	HardBirds[8].SetPosition(-2.5, 8.2);
	HardBirds[8].ImgID = 16;

	HardBirds[9].LoadImg(18, "bred1.bmp", 0, 0, 255);
	HardBirds[9].LoadImg(19, "bred2.bmp", 0, 0, 255);
	HardBirds[9].SetPosition(-4, 7);
	HardBirds[9].ImgID = 18;

	// cage 4

	HardBirds[10].LoadImg(20, "bblue1a.bmp", 255, 0, 0);
	HardBirds[10].LoadImg(21, "bblue2a.bmp", 255, 0, 0);
	HardBirds[10].SetPosition(-9.8, -1);
	HardBirds[10].ImgID = 20;

	// cage 5
	HardBirds[11].LoadImg(22, "byellow1.bmp", 255, 0, 0);
	HardBirds[11].LoadImg(23, "byellow2.bmp", 255, 0, 0);
	HardBirds[11].SetPosition(-3, -9.2);
	HardBirds[11].ImgID = 22;

	// cage 6

	HardBirds[12].LoadImg(24, "bpink1.bmp", 255, 0, 0);
	HardBirds[12].LoadImg(25, "bpink2.bmp", 255, 0, 0);
	HardBirds[12].SetPosition(13.5, 12.5);
	HardBirds[12].ImgID = 24;



}
void hard::RenderBirds()
{
	HardBirds[0].RenderImage(HardBirds[0].PosX, HardBirds[0].PosY, HardBirds[0].ImgID);
	HardBirds[1].RenderImage(HardBirds[1].PosX, HardBirds[1].PosY, HardBirds[1].ImgID);
	HardBirds[2].RenderImage(HardBirds[2].PosX, HardBirds[2].PosY, HardBirds[2].ImgID);
	HardBirds[3].RenderImage(HardBirds[3].PosX, HardBirds[3].PosY, HardBirds[3].ImgID);
	HardBirds[4].RenderImage(HardBirds[4].PosX, HardBirds[4].PosY, HardBirds[4].ImgID);
	HardBirds[5].RenderImage(HardBirds[5].PosX, HardBirds[5].PosY, HardBirds[5].ImgID);
	HardBirds[6].RenderImage(HardBirds[6].PosX, HardBirds[6].PosY, HardBirds[6].ImgID);
	HardBirds[7].RenderImage(HardBirds[7].PosX, HardBirds[7].PosY, HardBirds[7].ImgID);
	HardBirds[8].RenderImage(HardBirds[8].PosX, HardBirds[8].PosY, HardBirds[8].ImgID);
	HardBirds[9].RenderImage(HardBirds[9].PosX, HardBirds[9].PosY, HardBirds[9].ImgID);
	HardBirds[10].RenderImage(HardBirds[10].PosX, HardBirds[10].PosY, HardBirds[10].ImgID);
	HardBirds[11].RenderImage(HardBirds[11].PosX, HardBirds[11].PosY, HardBirds[11].ImgID);
	HardBirds[12].RenderImage(HardBirds[12].PosX, HardBirds[12].PosY, HardBirds[12].ImgID);
}
void hard::AnimationCage1()
{
	HardCage[0].openLid = 1;

	if (HardBirds[0].IsUp == 1)
	{
		HardBirds[0].IsUp = 0;
		HardBirds[0].ImgID = 0;
		HardBirds[1].ImgID = 2;
		HardBirds[2].ImgID = 4;
		HardBirds[3].ImgID = 6;

	}

	else if (HardBirds[0].IsUp == 0)
	{
		HardBirds[0].IsUp = 1;
		HardBirds[0].ImgID = 1;
		HardBirds[1].ImgID = 3;
		HardBirds[2].ImgID = 5;
		HardBirds[3].ImgID = 7;

	}

	HardBirds[0].PosX -= 0.2;
	HardBirds[0].PosY += 2;

	HardBirds[1].PosX += 0.1;
	HardBirds[1].PosY += 0.7;

	HardBirds[2].PosX -= 0.1;
	HardBirds[2].PosY += 0.9;

	HardBirds[3].PosX += 0.4;
	HardBirds[3].PosY++;
}
void hard::AnimationCage2()
{
	HardCage[1].openLid = 1;

	if (HardBirds[4].IsUp == 1)
	{
		HardBirds[4].IsUp = 0;
		HardBirds[4].ImgID = 8;
		HardBirds[5].ImgID = 10;


	}

	else if (HardBirds[4].IsUp == 0)
	{
		HardBirds[4].IsUp = 1;
		HardBirds[4].ImgID = 9;
		HardBirds[5].ImgID = 11;

	}

	HardBirds[4].PosX += 0.3;
	HardBirds[4].PosY += 2;

	HardBirds[5].PosX += 0.2;
	HardBirds[5].PosY += 0.7;

}
void hard::AnimationCage3()
{
	HardCage[2].openLid = 1;

	if (HardBirds[6].IsUp == 1)
	{
		HardBirds[6].IsUp = 0;
		HardBirds[6].ImgID = 12;
		HardBirds[7].ImgID = 14;


	}

	else if (HardBirds[6].IsUp == 0)
	{
		HardBirds[6].IsUp = 1;
		HardBirds[6].ImgID = 13;
		HardBirds[7].ImgID = 15;

	}

	HardBirds[6].PosX -= 0.3;
	HardBirds[6].PosY += 0.5;

	HardBirds[7].PosX += 0.2;
	HardBirds[7].PosY += 0.5;
}
void hard::AnimationCage4()
{
	HardCage[3].openLid = 1;

	if (HardBirds[8].IsUp == 1)
	{
		HardBirds[8].IsUp = 0;
		HardBirds[8].ImgID = 16;
		HardBirds[9].ImgID = 18;


	}

	else if (HardBirds[8].IsUp == 0)
	{
		HardBirds[8].IsUp = 1;
		HardBirds[8].ImgID = 17;
		HardBirds[9].ImgID = 19;

	}

	HardBirds[8].PosX -= 0.3;
	HardBirds[8].PosY += 0.5;

	HardBirds[9].PosX -= 0.2;
	HardBirds[9].PosY += 0.5;
}
void hard::AnimationCage5()
{
	HardCage[4].openLid = 1;

	if (HardBirds[10].IsUp == 1)
	{
		HardBirds[10].IsUp = 0;
		HardBirds[10].ImgID = 20;


	}

	else if (HardBirds[10].IsUp == 0)
	{
		HardBirds[10].IsUp = 1;
		HardBirds[10].ImgID = 21;


	}

	HardBirds[10].PosX += 0.2;
	HardBirds[10].PosY += 2;

}

void hard::AnimationCage6()
{
	HardCage[5].openLid = 1;

	if (HardBirds[11].IsUp == 1)
	{
		HardBirds[11].IsUp = 0;
		HardBirds[11].ImgID = 22;


	}

	else if (HardBirds[11].IsUp == 0)
	{
		HardBirds[11].IsUp = 1;
		HardBirds[11].ImgID = 23;


	}

	HardBirds[11].PosX -= 0.2;
	HardBirds[11].PosY += 2;


}
void hard::AnimationCage7()
{
	HardCage[6].openLid = 1;

	if (HardBirds[12].IsUp == 1)
	{
		HardBirds[12].IsUp = 0;
		HardBirds[12].ImgID = 24;


	}

	else if (HardBirds[12].IsUp == 0)
	{
		HardBirds[12].IsUp = 1;
		HardBirds[12].ImgID = 25;


	}

	HardBirds[12].PosX -= 0.2;
	HardBirds[12].PosY += 0.7;


}