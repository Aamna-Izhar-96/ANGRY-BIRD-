#pragma once
#include <glut.h>
#include <vector>
//#include "Point.h"
class Cage
{
public:
	int openLid=0;
	float posX;
	float posY;
	float size;
	void DrawCage(float x, float y, float size,int open);
	std::vector<Point2> LockPts;
	std::vector<Point2> CagePts;
	void ngon(int n, float cx, float cy, float radius, float angle);
	void DrawLock( float cx,float cy,float size);
	void StoreLockPts();
	void storeCagePts();
	float cx;
	float cy;
	float radius;
	int IsVisible = 1;;

	
	
};

void Cage::DrawCage(float x, float y, float size,int open)
{
	
	this->posX = x;
	this->posY = y;
	this->openLid = open;
	this->size = size;

	if (this->IsVisible == 1)
	{

		// Vertex of Cage

		glColor3f(0.52156, 0.24705, 0.094117); // Brown color

		glLineWidth(5.0);



		glBegin(GL_LINES);

		glVertex2f((-1 + x)*size, (-1.5 + y)*size); // left wall
		glVertex2f((-1 + x)*size, (1.5 + y)*size);

		glVertex2f((1 + x)*size, (-1.5 + y)*size); // right wall
		glVertex2f((1 + x)*size, (1.5 + y)*size);

		glEnd();


		// bars
		glLineWidth(2.0);
		glBegin(GL_LINES);
		glVertex2f((-0.7 + x)*size, (-1.5 + y)*size);
		glVertex2f((-0.7 + x)*size, (1.5 + y)*size);

		glVertex2f((-0.2 + x)*size, (-1.5 + y)*size);
		glVertex2f((-0.2 + x)*size, (1.5 + y)*size);

		glVertex2f((0.2 + x)*size, (-1.5 + y)*size);
		glVertex2f((0.2 + x)*size, (1.5 + y)*size);


		glVertex2f((0.7 + x)*size, (-1.5 + y)*size);
		glVertex2f((0.7 + x)*size, (1.5 + y)*size);
		glEnd();




		glColor3f(0.52156, 0.24705, 0.094117);
		glLineWidth(7.0);
		glBegin(GL_LINES);
		glVertex2f((-1.3 + x)*size, (-1.5 + y)*size); // bottom  wall
		glVertex2f((1.3 + x)*size, (-1.5 + y)*size);
		glEnd();





		glLineWidth(7.0);
		glBegin(GL_LINES);
		if (open == 0) // to open roof
		{
			glVertex2f((-1.3 + x)*size, (1.5 + y)*size);
			glVertex2f((1.3 + x)*size, (1.5 + y)*size);

			glEnd();

		}




	}





}
void Cage::ngon(int n, float cx, float cy, float radius, float rotAngle)
{      // assumes global Canvas object, cvs 
	if (n < 3) return; // bad number of sides   
	double angle = rotAngle * 3.14159265 / 180;  // initial angle   
	double angleInc = 2 * 3.14159265 / n;         //angle increment 
	glBegin(GL_POLYGON);
	glVertex2f(radius + cx, cy);
	for (int k = 0; k <= n; k++)  // repeat n times 
	{

		angle += angleInc;
		glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);

		/*Point2 pt;
		pt.set(radius * cos(angle) + cx, radius * sin(angle) + cy);
		LockPts.push_back(pt);
*/

	}
	glEnd();
}
void Cage::DrawLock(float cx,float cy,float size)
{
	glColor3f(1, 1, 0.0667);
	this->cx = cx;
	this->cy = cy;
	this->radius = size;
	int n = 40;
	float  rotAngle = 0;
	float radius = size;
	// assumes global Canvas object, cvs 
	if (n < 3) return; // bad number of sides   
	double angle = rotAngle * 3.14159265 / 180;  // initial angle   
	double angleInc = 2 * 3.14159265 / n;         //angle increment 
	glBegin(GL_POLYGON);
	glVertex2f(radius + cx, cy);
	for (int k = 0; k <= n; k++)  // repeat n times 
	{

		angle += angleInc;
		glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);

		/*Point2 pt;
		pt.set(radius * cos(angle) + cx, radius * sin(angle) + cy);
		LockPts.push_back(pt);
		*/

	}
	glEnd();

	glColor3f(0.192, 0.192, 0);
	ngon(4,cx,cy,size/2,45);
}

void Cage::StoreLockPts()
{
	int n = 40;
	float  rotAngle = 0;
	float radius = this->radius;
	float cx = this->cx;
	float cy = this->cy;
	// assumes global Canvas object, cvs 
	if (n < 3) return; // bad number of sides   
	double angle = rotAngle * 3.14159265 / 180;  // initial angle   
	double angleInc = 2 * 3.14159265 / n;         //angle increment 

	glVertex2f(radius + cx, cy);
	for (int k = 0; k <= n; k++)  // repeat n times 
	{

		angle += angleInc;
		/*glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);
*/
		Point2 pt;
		pt.set(radius * cos(angle) + cx, radius * sin(angle) + cy);
		this->LockPts.push_back(pt);
		

	}
	
}
void Cage::storeCagePts()
{
	float x = this->posX;
	float y = this->posY;
	float size = this->size;

	Point2 p[16];
	// Vertex of Cage


	glLineWidth(5.0);



	glBegin(GL_LINES);

	 // left wall
	p[0].set((-1 + x)*size, (-1.5 + y)*size);
	p[1].set((-1 + x)*size, (1.5 + y)*size);
	
   // right wall
	p[2].set((1 + x)*size, (-1.5 + y)*size);
	p[3].set((1 + x)*size, (1.5 + y)*size);
	glEnd();


	// bars
	glLineWidth(2.0);
	glBegin(GL_LINES);
	p[4].set((-0.7 + x)*size, (-1.5 + y)*size);
	p[5].set((-0.7 + x)*size, (1.5 + y)*size);


	
	p[6].set((-0.2 + x)*size, (-1.5 + y)*size);
    p[7].set((-0.2 + x)*size, (1.5 + y)*size);


	p[8].set((0.2 + x)*size, (-1.5 + y)*size);
    p[9].set((0.2 + x)*size, (1.5 + y)*size);


	
	p[10].set((0.7 + x)*size, (-1.5 + y)*size);
	p[11].set((0.7 + x)*size, (1.5 + y)*size);
	glEnd();




	
	glLineWidth(7.0);
	glBegin(GL_LINES);
	 // bottom  wall
	p[12].set((-1.3 + x)*size, (-1.5 + y)*size);
	p[13].set((1.3 + x)*size, (-1.5 + y)*size);
	glEnd();





	glLineWidth(7.0);
	glBegin(GL_LINES);
	if (this->openLid == 0) // to open roof
	{
		p[14].set((-1.3 + x)*size, (1.5 + y)*size);
		p[15].set((1.3 + x)*size, (1.5 + y)*size);
		glEnd();

	}


	for (int i = 0; i < 16;i++)
	{
		this->CagePts.push_back(p[i]);
	}


}