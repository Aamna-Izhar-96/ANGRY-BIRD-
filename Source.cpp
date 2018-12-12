#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include<Math.h>
#include <fstream>
#include <string>
#include <glut.h>
#include <windows.h>
#include <vector>
#include "TrapBirds.h"
#include "SplashScreen.h"
#include "Projectile.h"
#include "BoundinCircle.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
//#include "wav.h"    if we include wav.h we got an error thats why removed sound from project

using namespace std;

const int ScreenWidth = 1366;  
const int ScreenHeight = 768;
float WL = -20, WR = 20, WB = -20, WT = 20;
int Level = 0; bool GameOver = false;
float StretchX = -15, StretchY = -8;
float BirdX = -15, BirdY = -8;
int LineCenterX = -15, LineCenterY = -13; int IsStretch = 0; int Fire = 0;
int ScaleX = 15, ScaleY = 7;
int ToProjectBall = 0;
int Time0 = 0; 
int Time1 = 1; float Cx = 0, Cy = 0; int CollideCage = 0; int ToCollide = 0;

int CountInc = 0;
float CountDec = 0;
SplashScreen Screen;
BoundingCircle BC;
Level1 Lev1;
Level2 Lev2;
Projectile Object;
Bird bird;
void Initialize(){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_EQUAL, 1.0);


	glViewport(-20, 20, -20, 20);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(-20, 20, -20, 20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Screen.Birds.IsUp = 1;
	
}



void myTimer(int t)
{
	CountInc += 1;
	CountDec--;;
	
	
	//if (Count % 2 ==0)
	if (Screen.Birds.IsUp == 1)
	{
		Screen.Birds.IsUp = 0;
		Screen.Birds.PosX -= 0.1;

	}
	else if (Screen.Birds.IsUp == 0)
	{
		Screen.Birds.IsUp = 1;
		Screen.Birds.PosX += 0.1;

	}
	if (CountInc <= 10)
		Screen.Inc = CountInc;
	glutPostRedisplay();
	glutTimerFunc(500, myTimer, t);

}
void AnimationTimer(int t)
{
	Time0++;
	if (Level == 1 && ToCollide == 1)
	{
		if (CollideCage == 0)
		{
			Lev1.EasyLevel.AnimationCage1();
			printf("\n time is %d", Time0);
			if (Time0 == 60)
			{
				Lev1.EasyLevel.EasyCage[CollideCage].IsVisible = 0;
			}
		}
		if (CollideCage == 1)
		{
			Lev1.EasyLevel.AnimationCage2();
			if (Time0 == 60)
			{
				Lev1.EasyLevel.EasyCage[CollideCage].IsVisible = 0;
			}
		}
		if (CollideCage == 2)
		{
			Lev1.EasyLevel.AnimationCage3();
			if (Time0 == 60)
			{
				Lev1.EasyLevel.EasyCage[CollideCage].IsVisible = 0;
			}
		}

	} // end of Level 1
	/*
	if (Level == 2 && ToCollide == 1)
	{

		if (CollideCage == 0)
		{
			LevelMed.AnimationCage1();
			if (time == 60)
			{
				LevelMed.MedCage[CollideCage].IsVisible = 0;
			}
		}
		if (CollideCage == 1)
		{
			LevelMed.AnimationCage2();
			if (time == 60)
			{
				LevelMed.MedCage[CollideCage].IsVisible = 0;
			}
		}
		if (CollideCage == 2)
		{
			LevelMed.AnimationCage3();
			if (time == 60)
			{
				LevelMed.MedCage[CollideCage].IsVisible = 0;
			}
		}
		if (CollideCage == 3)
		{
			LevelMed.AnimationCage4();
			if (time == 60)
			{
				LevelMed.MedCage[CollideCage].IsVisible = 0;
			}

		}
		if (CollideCage == 4)
		{
			LevelMed.AnimationCage5();
			if (time == 60)
			{
				LevelMed.MedCage[CollideCage].IsVisible = 0;
			}

		}

	}//end of Level 1

	if (Level == 3 && ToCollide == 1)
	{
		if (CollideCage == 0)
		{
			LevelHard.AnimationCage1();
			if (time == 60)
			{
				LevelHard.HardCage[CollideCage].IsVisible = 0;
			}
		}
		if (CollideCage == 1)
		{
			LevelHard.AnimationCage2();
			if (time == 60)
			{
				LevelHard.HardCage[CollideCage].IsVisible = 0;
			}
		}
		if (CollideCage == 2)
		{
			LevelHard.AnimationCage3();
			if (time == 60)
			{
				LevelHard.HardCage[CollideCage].IsVisible = 0;
			}
		}
		if (CollideCage == 3)
		{
			LevelHard.AnimationCage4();
			if (time == 60)
			{
				LevelHard.HardCage[CollideCage].IsVisible = 0;
			}
		}
		if (CollideCage == 4)
		{
			LevelHard.AnimationCage5();
			if (time == 60)
			{
				LevelHard.HardCage[CollideCage].IsVisible = 0;
			}
		}
		if (CollideCage == 5)
		{
			LevelHard.AnimationCage6();
			if (time == 60)
			{
				LevelHard.HardCage[CollideCage].IsVisible = 0;
			}
		}
		if (CollideCage == 6)
		{
			LevelHard.AnimationCage7();
			if (time == 60)
			{
				LevelHard.HardCage[CollideCage].IsVisible = 0;
			}
		}

	}//end of Level 3 
	*/
	glutPostRedisplay();
	glutTimerFunc(100, AnimationTimer, t);

}
void myTimer1(int n)
{
	Time1++;
	bool bool1 = BC.IsBoundryCollide(bird.JackVerticesList);
	if (bool1 == true)
	{
		BirdX -= 0.5;//=Object.VerticesList[ToProjectBall--].deltaX();
		BirdY -= 1;
		glutPostRedisplay();
		glutTimerFunc(20, myTimer1, 1);
		
	}
	if (ToCollide == 0 && bool1 == false)
	{
		if (ToProjectBall >= 100)
		{
			ToProjectBall = 0;
		}
		else
		{
			ToProjectBall++;
		}
		BirdX = Object.VerticesList[ToProjectBall].deltaX();
		BirdY = Object.VerticesList[ToProjectBall].deltaY();
		glutPostRedisplay();
		glutTimerFunc(20, myTimer1, 1);
	}
	else
	if (ToCollide == 1)
	{
		//BirdX-=0.5;
		//BirdY-=0.3;	
		glutPostRedisplay();
		glutTimerFunc(100, myTimer1, 1);
	}

	//glutPostRedisplay();
	//glutTimerFunc(20, myTimer1, 1);
}
void InitializeScreen()
{
	Screen.Inc = 0;
	CountInc = 0;
	Screen.Plus = 0;
}
void Draw()
{
	glPointSize(5);
	glColor3f(0, 0, 1);
	glBegin(GL_POINTS);
	for (int i = 0; i < 80; i++)
	{

		glVertex2f(Cx + Object.VerticesList[i].deltaX(), Cy + Object.VerticesList[i].deltaY());
	}
	glEnd();
}
void Display(){
	glClear(GL_COLOR_BUFFER_BIT);

	
	if (Level == 0 )
	{
		
		Screen.DisplayScreen(GameOver);

		
	}
	if (GameOver)
	{
		Screen.DisplayScreen(GameOver);
	}

	if (Level == 1){

		bird.JackVerticesList.clear();
		Lev1.StartLevel();
		ScaleX = Lev1.ScaleX; ScaleY = Lev1.ScaleY;
		Cx = Lev1.Cx; Cy = Lev1.Cy;
		bird.DrawJack(40, 0 + BirdX, 4 +BirdY, 1.775 / 1.5, 90);
		bird.DrawSlingShot(Cx, Cy,StretchX, StretchY);
		if (ToCollide == 1)
		{
			Lev1.EasyLevel.EasyCage[CollideCage].IsVisible = 0;
		
		}

		for (int i = 0; i<3; i++)
		{
			Lev1.EasyLevel.EasyCage[i].StoreLockPts();
		}
		if (ToCollide == 0)
		{
			bird.DrawJack(40, Cx + BirdX, Cy + BirdY, 1.775 / 1.5, 0);
		}
		else if (ToCollide == 1)
		{
			//InitializeParameters();
			bird.JackVerticesList.clear();
			Cx = 0, Cy = 4;
			ScaleX = Lev1.ScaleX; ScaleY = Lev1.ScaleY;
			
			bird.DrawJack(40, Cx + BirdX, Cy + BirdY, 1.775 / 1.5, 0);

			//bird.DrawSlingShot(Cx, Cy, StrectX, StrectY1);

		}
		for (int i = 0; i<3; i++)
		{
			if (BC.IsCollide(bird.JackVerticesList, Lev1.EasyLevel.EasyCage[i].LockPts) == true)
			{
				CollideCage = i;
				ToCollide = 1;
				glutTimerFunc(200, AnimationTimer, 0);
				break;
			}
		}
	}

	Object.SetVelocity(20);
	Object.SetTimeOfFLight();
	Object.SetScaleX(Cx + ScaleX);
	Object.SetScaleY(Cy + ScaleY);
	float Time = 0, PointsRange = 80;
	float TimeInc = Object.GetTimeOfFlight() / PointsRange;
	for (int i = 0; i < 100; i++)
	{
		Object.SetDistance(Time);
		Time += TimeInc;
	}
	Draw();
	glFlush();
}


void MyMouse(int Mouse, int State, int x, int y) {

	if (Mouse == GLUT_LEFT_BUTTON && State== GLUT_DOWN && Level ==0)
	{
		float Sx = (x*(WR - WL) / ScreenWidth) + WL;
		float Sy = (y*(WB - WT) / ScreenHeight) + WT;

		if (BC.IsMouseCollide(Screen.ButtonList, Point2(Sx, Sy)))
		{
			printf("aliza");
			Level = 1;
			InitializeScreen();
			glutPostRedisplay();
		}

	}
}

void SpecialInput(int key, int x, int y)
{
	switch (key)
	{
		// if (Fire == 0)
		{

	case GLUT_KEY_UP:

		if (StretchY != -5)
		{
			IsStretch = 1;
			ScaleY--;
			printf("\nScaleY is %f", ScaleY);
			StretchY += 1;
			if (StretchX > LineCenterX)
			{
				Object.SetAngle(-60);
			}
			else
			{
	
				Object.SetAngle(60);
			}
			BirdY += 1;
		}


		break;
	case GLUT_KEY_DOWN:


		if (StretchY != -13)
		{
			IsStretch = 1;
			ScaleY++;
			printf("\nScaleY is %f", ScaleY);
			StretchY -= 1;
			if (StretchX > LineCenterX)
			{

	
				Object.SetAngle(-45);
			}
			else
			{
				
				Object.SetAngle(45);
			}
			BirdY -= 1;
		}


		break;
	case GLUT_KEY_LEFT:


		if (StretchX != -18)
		{
			IsStretch = 1;
			ScaleX++;
			printf("\nScaleX is %f", ScaleX);
			StretchX -= 1;
			if (StretchX > LineCenterX)
			{

		
				Object.SetAngle(40);
			}
			else
			{
			
				Object.SetAngle(70);
			}
			BirdX -= 1;
		}


		break;

	case GLUT_KEY_RIGHT:


		if (StretchX != -12)
		{
			IsStretch = 1;
			ScaleX--;
			printf("\nScaleX is %f", ScaleX);
			StretchX += 1;
			if (StretchX > LineCenterX)
			{
				
				Object.SetAngle(40);
			}
			else
			{
			
				Object.SetAngle(-40);
			}
			BirdX += 1;
		}


		break;
		}
	case GLUT_KEY_F1:
		if (IsStretch == 0)
		{
			
			Object.SetAngle(45);
		}
		Fire = 1;
		glutTimerFunc(20, myTimer1, 1);
		break;
	}
	Object.VerticesList.clear();
	glutPostRedisplay();

}
int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(ScreenWidth, ScreenHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Program");

	Initialize();
	glutSpecialFunc(SpecialInput);
	glutDisplayFunc(Display);
	glutMouseFunc(MyMouse);
	glutTimerFunc(500, myTimer, 5);

	glutMainLoop();

	return 0;
}