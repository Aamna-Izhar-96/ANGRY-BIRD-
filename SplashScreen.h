#include <glut.h>
#include <vector>
using namespace std;
#include "Bird.h"

#define _CRT_SECURE_NO_WARNINGS
class SplashScreen
{
public:
	void DisplayScreen(bool GameOver);
	vector<Point2> ButtonList;
	int Inc = 0;
	TrapBirds Birds;
	Bird Box;
	int Plus = -10;
private:
	
	void LoadSplashImages();
	void RenderSplashImages();
	void LoadingBar();
	void RenderBitmapString(float x, float y, void *font, char *string);
	void GameTitle();
	void PlayButton();
	void DrawBirds();
    
	
};


void SplashScreen::DisplayScreen(bool GameOver)

{

	this->LoadSplashImages();
	this->RenderSplashImages();
	this->DrawBirds();

	if (GameOver)
	{
		Birds.LoadImg(15, "GameOver6.bmp", 255, 255, 255);
		Birds.RenderImage(-4, -2, 15);
	}
	else 
	this->LoadingBar();




}
void SplashScreen::PlayButton()
{
	glColor3f(0, 0, 0);
	Box.Ngon(40, 0, 2,2, 360 , ButtonList);
	glColor3f(1.0f, 0.5f, 0);
	//glColor3f(1, 0, 0);
	Box.Ngon(40, 0, 2, 1.8, 360, ButtonList);
	glColor3f(0, 0, 0);
	Box.Ngon(3, 0, 2, 1, 120,ButtonList);

}

void SplashScreen::LoadingBar()
{
	glColor3f(0, 0, 0);
	glBegin(GL_QUAD_STRIP);
	glVertex2f(-5.2, -15.3); //Left Bottom
	glVertex2f(-5.2, -12.7);  // left top
	glVertex2f(5.2, -15.3);   // right bottom
	glVertex2f(5.2, -12.7);   // right yop
	glEnd();

	glColor3f(1, 1, 0);
	glBegin(GL_QUAD_STRIP);
	glVertex2f(-5, -15);
	glVertex2f(-5, -13);
	glVertex2f(5, -15);
	glVertex2f(5, -13);
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_QUAD_STRIP);
	glVertex2f(-5, -15);
	glVertex2f(-5, -13);
	glVertex2f(-5 + Inc, -15);
	glVertex2f(-5 + Inc, -13);
	glEnd();


	glColor3f(0, 0, 0);
	char buf[100] = { 0 };

	if (Plus <90)
	{
		sprintf(buf, "Loading. . . ");
		RenderBitmapString(-5, -12, GLUT_BITMAP_HELVETICA_18, buf);
		sprintf(buf, "%d", Plus + 10);
		RenderBitmapString(-0.6, -14.3, GLUT_BITMAP_HELVETICA_18, buf);
		Plus += 10;
		sprintf(buf, "%c", '%');
		RenderBitmapString(0, -14.3, GLUT_BITMAP_HELVETICA_18, buf);
		
		
	}
	else
	{
		sprintf(buf, "Loading Completed! ");
		RenderBitmapString(-5, -12, GLUT_BITMAP_HELVETICA_18, buf);
		sprintf(buf, "%d", Plus + 10);
		RenderBitmapString(-0.6, -14.3, GLUT_BITMAP_HELVETICA_18, buf);
		Plus = 90;
		sprintf(buf, "%c", '%');
		RenderBitmapString(0.2, -14.3, GLUT_BITMAP_HELVETICA_18, buf);
		this->PlayButton();
	}



}

void SplashScreen::LoadSplashImages()
{
	Birds.LoadImg(0, "SplashBg.bmp", 1, 1, 1);
	Birds.LoadImg(1, "bblue1.bmp", 255, 0, 0);
	Birds.LoadImg(2, "bblue2.bmp", 255, 0, 0);
	Birds.LoadImg(3, "bgreenRefelected1.bmp", 255, 0, 0);
	Birds.LoadImg(4, "bgreenReflected2.bmp", 255, 0, 0);
	Birds.LoadImg(5, "bpink1.bmp", 255, 0, 0);
	Birds.LoadImg(6, "bpink2.bmp", 255, 0, 0);
	Birds.LoadImg(7, "byellowReflected1.bmp", 255, 0, 0);
	Birds.LoadImg(8, "byellowReflected2.bmp", 255, 0, 0);
	Birds.LoadImg(9, "s1.bmp", 255, 0, 0);
	Birds.LoadImg(10, "s2.bmp", 255, 0, 0);
	Birds.LoadImg(11, "bredReflected1.bmp", 0, 0, 255);
	Birds.LoadImg(12, "bredReflected2.bmp", 0, 0, 255);
	Birds.LoadImg(13, "GameTitle2.bmp", 255, 255, 255);
}
void SplashScreen::RenderSplashImages()
{
	Birds.RenderImage(-20, -20, 0);
	Birds.RenderImage(-10, 5, 13);
	if (Birds.IsUp == 0)
	{

		Birds.RenderImage(3 + Birds.PosX, 11 + Birds.PosY, 1);
		Birds.RenderImage(-6 + Birds.PosX, 3 + Birds.PosY, 3);
		Birds.RenderImage(10 + Birds.PosX, 6 + Birds.PosY, 5);
		Birds.RenderImage(-12 + Birds.PosX, -2 + Birds.PosY, 7);
		Birds.RenderImage(13 + Birds.PosX, -5 + Birds.PosY, 9);
		Birds.RenderImage(-10 + Birds.PosX, 12 + Birds.PosY, 11);
	}
	else if (Birds.IsUp == 1)
	{

		Birds.RenderImage(3 + Birds.PosX, 11 + Birds.PosY, 2);
		Birds.RenderImage(-6 + Birds.PosX, 3 + Birds.PosY, 4);
		Birds.RenderImage(10 + Birds.PosX, 6 + Birds.PosY, 6);
		Birds.RenderImage(-12 + Birds.PosX, -2 + Birds.PosY, 8);
		Birds.RenderImage(13 + Birds.PosX, -5 + Birds.PosY, 10);
		Birds.RenderImage(-10 + Birds.PosX, 12 + Birds.PosY, 12);
	}



}

void SplashScreen::RenderBitmapString(float x, float y, void *font, char *string)
{
	char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

void SplashScreen::DrawBirds()
{
	glPushMatrix();
	glScalef(2.5, 2.5, 2.5);
	Box.DrawChuck(-0.5, -2.5);
	Box.DrawJack(40, -2 , -1.5 , 1.775 / 1.5, 90);
	
	Box.DrawMatlida(20, 1, -1.5, 0, 0.68, 1.85);
	glPopMatrix();

}