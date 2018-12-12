#include <glut.h>
#include <vector>
#include "RGBA.h"

class Bird
{
public:
	void DrawSlingShot(float Cx, float Cy, float StretchX, float StretchY);
	void Ngon(int NumOfSides, float Cx, float Cy, float Radius, float RotAngle, vector<Point2> &List);
	void Oval(int NumOfSides, float Cx, float Cy, float RotAngle, float RadX, float RadY, vector<Point2> &List);
	void DrawJack(int n, float Cx, float Cy, float Radius, float RotAngle);   //Red Bird
	void DrawMatlida(int n, float Cx, float Cy, float RotAngle, float RadX, float RadY);  // White Bird
	void DrawChuck(float Cx, float Cy);   // Yellow Bird
	std::vector<Point2> MatlidaVerticesList, JackVerticesList, ChuckVerticesList;


};

void Bird::Ngon(int NumOfSides, float Cx, float Cy, float Radius, float RotAngle, vector<Point2> &List)
{

	if (NumOfSides < 3) return;
	double angle = RotAngle * 3.14159265 / 180;
	double angleInc = 2 * 3.14159265 / NumOfSides;
	glBegin(GL_POLYGON);

	List.push_back(Point2(Radius + Cx, Cy));
	glVertex2f(Radius + Cx, Cy);
	for (int k = 0; k <= NumOfSides; k++)
	{

		angle += angleInc;
		List.push_back(Point2(Radius * cos(angle) + Cx, Radius * sin(angle) + Cy));
		glVertex2f(Radius * cos(angle) + Cx, Radius * sin(angle) + Cy);
	}
	glEnd();
}

void Bird::Oval(int NumOfSides, float Cx, float Cy, float RotAngle, float RadX, float RadY, vector<Point2> &List)
{
	if (NumOfSides < 3) return;
	double angle = RotAngle * 3.14159265 / 180;
	double angleInc = 2 * 3.14159265 / NumOfSides;
	glBegin(GL_POLYGON);
	for (int k = 0; k <= NumOfSides + 1; k++)
	{
		angle += angleInc;
		List.push_back(Point2(RadX * cos(angle) + Cx, RadY * sin(angle) + Cy));
		glVertex2f(RadX * cos(angle) + Cx, RadY * sin(angle) + Cy);
	}
	glEnd();
}

void Bird::DrawSlingShot(float Cx, float Cy, float StretchX, float StretchY)
{


	glColor3f(0.5f, 0.1f, 0.0f);
	glLineWidth(10.0);
	glBegin(GL_LINES);
	glVertex2f(Cx - 15, Cy - 17);
	glVertex2f(Cx - 15, Cy - 13);
	glEnd();

	
	glBegin(GL_LINES);
	glVertex2f(Cx - 15, Cy - 13);
	glVertex2f(Cx - 13.5, Cy - 11);
	glEnd();

	glLineWidth(7.0);
	glBegin(GL_LINES);
	glVertex2f(Cx - 13.5, Cy - 7);
	glVertex2f(Cx - 13.5, Cy - 11);
	glEnd();

	//left V
	glBegin(GL_LINES);
	glVertex2f(Cx - 15, Cy - 13);
	glVertex2f(Cx - 16.5, Cy - 11);
	glEnd();


	glLineWidth(7.0);
	glBegin(GL_LINES);
	glVertex2f(Cx - 16.5, Cy - 7);
	glVertex2f(Cx - 16.5, Cy - 11);
	glEnd();
	//strect
	glColor3f(0, 0, 0);

	glLineWidth(4.0);
	glBegin(GL_LINES);
	glVertex2f(Cx - 16.5, Cy - 9);
	glVertex2f(Cx + StretchX, Cy + StretchY);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(Cx - 13.5, Cy - 9);
	glVertex2f(Cx + StretchX, Cy + StretchY);
	glEnd();


	glPointSize(15);
	glBegin(GL_POINTS);
	glVertex2f(Cx - 16.5, Cy - 9);
	glVertex2f(Cx - 13.5, Cy - 9);
	glEnd();
}



void Bird::DrawJack(int n, float Cx, float Cy, float Radius, float RotAngle)
{
	if (n < 3) return;
	double angle = RotAngle * 3.14159265 / 180;
	double angleInc = 2 * 3.14159265 / n;
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(Radius + Cx, Cy);
	JackVerticesList.push_back(Point2(Radius + Cx, Cy));
	for (int k = 0; k <= n; k++)  // repeat n times 
	{

		angle += angleInc;
		JackVerticesList.push_back(Point2(Radius * cos(angle) + Cx, Radius * sin(angle) + Cy));
		glVertex2f(Radius * cos(angle) + Cx, Radius * sin(angle) + Cy);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	//JackVerticesList.push_back(Point2(Cx - 3, Cy - 1));
	glVertex2f(Cx - 1.5 / 1.5, Cy - 0.5 / 1.5);
	//JackVerticesList.push_back(Point2(Cx - 4, Cy + 0));
	glVertex2f(Cx - 2 / 1.5, Cy + 0 / 1.5);
	//JackVerticesList.push_back(Point2(Cx - 4.5, Cy - 0.5));
	glVertex2f(Cx - 2.25 / 1.5, Cy - 0.25 / 1.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	//JackVerticesList.push_back(Point2(Cx - 2, Cy - 1));
	glVertex2f(Cx - 1 / 1.5, Cy - 0.5 / 1.5);
	//JackVerticesList.push_back(Point2(Cx - 4.8, Cy - 0.8));
	glVertex2f(Cx - 2.4 / 1.5, Cy - 0.4 / 1.5);
	//JackVerticesList.push_back(Point2(Cx - 4.8, Cy - 1.3));
	glVertex2f(Cx - 2.4 / 1.5, Cy - 0.65 / 1.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	//JackVerticesList.push_back(Point2(Cx - 3, Cy - 1));
	glVertex2f(Cx - 1.5 / 1.5, Cy - 0.5 / 1.5);
	//JackVerticesList.push_back(Point2(Cx - 4.5, Cy - 1.6));
	glVertex2f(Cx - 2.25 / 1.5, Cy - 0.8 / 1.5);
	//JackVerticesList.push_back(Point2(Cx - 4, Cy - 2));
	glVertex2f(Cx - 2 / 1.5, Cy - 1 / 1.5);
	glEnd();

	glColor3f(1, 0, 0);
	Ngon(15, Cx + 0 / 1.5, Cy + 0 / 1.5, 1.75 / 1.5, 1, JackVerticesList); //red circle

	glColor3f(0.658824, 0.658824, 0.658824);
	//glColor3f(0.560784, 0.560784, 0.737255);
	//glColor3f(0.90, 0.91, 0.98);
	Oval(20, Cx + 0 / 1.5, Cy - 1.35 / 1.5, 0, 0.95 / 1.5, 0.35 / 1.5, JackVerticesList);

	glColor3f(0, 0, 0);
	Ngon(20, Cx + 0.25 / 1.5, Cy - 0.25 / 1.5, 0.4 / 1.5, 1, JackVerticesList); //black outline eyes
	glColor3f(0, 0, 0);
	Ngon(20, Cx + 1 / 1.5, Cy - 0.25 / 1.5, 0.4 / 1.5, 1, JackVerticesList);
	glColor3f(1, 1, 1);
	Ngon(20, Cx + 0.25 / 1.5, Cy - 0.25 / 1.5, 0.35 / 1.5, 1, JackVerticesList); //white eyes
	glColor3f(1, 1, 1);
	Ngon(20, Cx + 1 / 1.5, Cy - 0.25 / 1.5, 0.35 / 1.5, 1, JackVerticesList);
	glColor3f(0, 0, 0);
	Ngon(20, Cx + 0.425 / 1.5, Cy - 0.15 / 1.5, 0.1 / 1.5, 1, JackVerticesList); //black inner eyes
	glColor3f(0, 0, 0);
	Ngon(20, Cx + 0.85 / 1.5, Cy - 0.15 / 1.5, 0.1 / 1.5, 1, JackVerticesList);
	glColor3f(1, 1, 0);
	Ngon(3, Cx + 0.75 / 1.5, Cy - 0.75 / 1.5, 0.45 / 1.5, 0, JackVerticesList); //nose

	glColor3f(1, 0, 0); //  hairs
	Ngon(3, Cx - 0.5 / 1.5, Cy + 1.625 / 1.5, 0.425 / 1.5, 1, JackVerticesList);
	glColor3f(1, 0, 0);
	Ngon(3, Cx - 1 / 1.5, Cy + 1.625 / 1.5, 0.425 / 1.5, 1, JackVerticesList);

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	/*glVertex2f(-1, 2.1);
	glVertex2f(3.5, 0.8);*/

	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON); //eyebrows
	//JackVerticesList.push_back(Point2(Cx - 0.5, Cy - 0.2));
	glVertex2f(Cx - 0.25 / 1.5, Cy - 0.1 / 1.5);
	//JackVerticesList.push_back(Point2(Cx + 3, Cy - 0.2));
	glVertex2f(Cx + 1.5 / 1.5, Cy - 0.1 / 1.5);
	//JackVerticesList.push_back(Point2(Cx + 3, Cy + 0.9));
	glVertex2f(Cx + 1.5 / 1.5, Cy + 0.45 / 1.5);
	//JackVerticesList.push_back(Point2(Cx + 1.75, Cy + 0.3));
	glVertex2f(Cx + 0.875 / 1.5, Cy + 0.15 / 1.5);
	//JackVerticesList.push_back(Point2(Cx - 0.5, Cy + 0.9));
	glVertex2f(Cx - 0.25 / 1.5, Cy + 0.45 / 1.5);
	glEnd();

}


void Bird::DrawChuck(float Cx, float Cy)
{
	glColor3f(0, 0, 0); //outer triangle black
	glBegin(GL_TRIANGLES);
	ChuckVerticesList.push_back(Point2(Cx - 4.05, Cy - 4.05));
	glVertex2f(Cx - 1.35, Cy - 1.35);
	ChuckVerticesList.push_back(Point2(Cx + 4.05, Cy - 4.05));
	glVertex2f(Cx + 1.35, Cy - 1.35);
	ChuckVerticesList.push_back(Point2(Cx + 0, Cy + 4.1));
	glVertex2f(Cx + 0, Cy + 1.37);

	glEnd();

	glBegin(GL_TRIANGLES);
	//ChuckVerticesList.push_back(Point2(Cx - 2, Cy - 1));
	glVertex2f(Cx - 1 / 1.5, Cy - 0.5 / 1.5);
	//ChuckVerticesList.push_back(Point2(Cx - 3, Cy + 0));
	glVertex2f(Cx - 1.5 / 1.5, Cy + 0 / 1.5);
	//ChuckVerticesList.push_back(Point2(Cx - 3.5, Cy - 0.5));
	glVertex2f(Cx - 1.75 / 1.5, Cy - 0.25 / 1.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	//ChuckVerticesList.push_back(Point2(Cx - 1, Cy - 1));
	glVertex2f(Cx - 0.5 / 1.5, Cy - 0.5 / 1.5);
	//ChuckVerticesList.push_back(Point2(Cx - 3.8, Cy - 0.8));
	glVertex2f(Cx - 1.9 / 1.5, Cy - 0.4 / 1.5);
	//ChuckVerticesList.push_back(Point2(Cx - 3.8, Cy - 1.3));
	glVertex2f(Cx - 1.9 / 1.5, Cy - 0.65 / 1.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	//ChuckVerticesList.push_back(Point2(Cx - 2, Cy - 1));
	glVertex2f(Cx - 1 / 1.5, Cy - 0.5 / 1.5);
	//ChuckVerticesList.push_back(Point2(Cx - 3.5, Cy - 1.6));
	glVertex2f(Cx - 1.75 / 1.5, Cy - 0.8 / 1.5);
	//ChuckVerticesList.push_back(Point2(Cx - 3, Cy - 2));
	glVertex2f(Cx - 1.5 / 1.5, Cy - 1 / 1.5);
	glEnd();


	glColor3f(0, 0, 0); // hairs
	Ngon(3, Cx + 0 / 3, Cy + 3.5 / 3, 0.5 / 3, 0, ChuckVerticesList);
	Ngon(3, Cx - 0.2 / 3, Cy + 3.75 / 3, 0.6 / 3, 50, ChuckVerticesList);
	Ngon(3, Cx - 0.1 / 3, Cy + 3.6 / 3, 0.8 / 3, 0, ChuckVerticesList);

	glColor3f(1, 1, 0); //yellow tri
	glBegin(GL_TRIANGLES);
	//ChuckVerticesList.push_back(Point2(Cx - 4, Cy - 4));
	glVertex2f(Cx - 1.34, Cy - 1.34);
	//ChuckVerticesList.push_back(Point2(Cx + 4, Cy - 4));
	glVertex2f(Cx + 1.34, Cy - 1.34);
	//ChuckVerticesList.push_back(Point2(Cx + 0, Cy + 4));
	glVertex2f(Cx + 0, Cy + 1.33);
	glEnd();

	glColor3f(0, 0, 0);
	Ngon(20, Cx + 0 / 3, Cy - 1 / 3, 0.6 / 3, 1, ChuckVerticesList); //black outline eyes
	Ngon(20, Cx + 1.5 / 3, Cy - 1 / 3, 0.6 / 3, 1, ChuckVerticesList);
	glColor3f(1, 1, 1);
	Ngon(20, Cx + 0 / 3, Cy - 1 / 3, 0.55 / 3, 1, ChuckVerticesList); //white eyes
	Ngon(20, Cx + 1.5 / 3, Cy - 1 / 3, 0.55 / 3, 1, ChuckVerticesList);
	glColor3f(0, 0, 0);
	Ngon(20, Cx + 0.2 / 3, Cy - 1 / 3, 0.2 / 3, 1, ChuckVerticesList); //black inner eyes
	Ngon(20, Cx + 1.65 / 3, Cy - 1 / 3, 0.2 / 3, 1, ChuckVerticesList);
	glColor3f(1, 1, 1);
	Ngon(20, Cx + 0.225 / 3, Cy - 1 / 3, 0.05 / 3, 1, ChuckVerticesList); //white inner eyes
	Ngon(20, Cx + 1.675 / 3, Cy - 1 / 3, 0.05 / 3, 1, ChuckVerticesList);

	glColor4f(1.0f, 0.5f, 0.0f, 0.0f); //eyebrows
	glBegin(GL_QUADS);
	//ChuckVerticesList.push_back(Point2(Cx - 1, Cy - 0.4));
	glVertex2f(Cx - 1 / 3, Cy + 0.6 / 3);
	//ChuckVerticesList.push_back(Point2(Cx + 0.65, Cy - 0.75));
	glVertex2f(Cx + 0.65 / 3, Cy + 0.25 / 3);
	//ChuckVerticesList.push_back(Point2(Cx + 0.65, Cy - 0.35));
	glVertex2f(Cx + 0.65 / 3, Cy + 0.65 / 3);
	//ChuckVerticesList.push_back(Point2(Cx - 0.9, Cy + 0.2));
	glVertex2f(Cx - 0.9 / 3, Cy + 1.2 / 3);
	glEnd();
	glBegin(GL_QUADS);
	//ChuckVerticesList.push_back(Point2(Cx + 0.8, Cy - 0.85));
	glVertex2f(Cx + 0.8 / 3, Cy + 0.15 / 3);
	//ChuckVerticesList.push_back(Point2(Cx + 2.75, Cy - 0.4));
	glVertex2f(Cx + 2.75 / 3, Cy + 0.6 / 3);
	//ChuckVerticesList.push_back(Point2(Cx + 2.55, Cy + 0.25));
	glVertex2f(Cx + 2.55 / 3, Cy + 1.25 / 3);
	//ChuckVerticesList.push_back(Point2(Cx + 0.8, Cy - 0.35));
	glVertex2f(Cx + 0.8 / 3, Cy + 0.65 / 3);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_QUADS); //peak
	//ChuckVerticesList.push_back(Point2(Cx - 0.05, Cy - 2.3));
	glVertex2f(Cx - 0.05 / 3, Cy - 2.3 / 3);
	//ChuckVerticesList.push_back(Point2(Cx + 0.7, Cy - 2.05));
	glVertex2f(Cx + 0.7 / 3, Cy - 2.05 / 3);
	//ChuckVerticesList.push_back(Point2(Cx + 2.95, Cy - 2.55));
	glVertex2f(Cx + 2.95 / 3, Cy - 2.55 / 3);
	//ChuckVerticesList.push_back(Point2(Cx + 0.7, Cy - 1.3));
	glVertex2f(Cx + 0.7 / 3, Cy - 1.3 / 3);

	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glBegin(GL_QUADS); //peak
	//ChuckVerticesList.push_back(Point2(Cx + 0, Cy - 2.25));
	glVertex2f(Cx + 0 / 3, Cy - 2.15 / 3);
	//ChuckVerticesList.push_back(Point2(Cx + 0.75, Cy - 2));
	glVertex2f(Cx + 0.75 / 3, Cy - 1.9 / 3);
	//ChuckVerticesList.push_back(Point2(Cx + 3, Cy - 2.5));
	glVertex2f(Cx + 3 / 3, Cy - 2.4 / 3);
	//ChuckVerticesList.push_back(Point2(Cx + 0.75, Cy - 1.25));
	glVertex2f(Cx + 0.75 / 3, Cy - 1.15 / 3);
	glEnd();
}

void Bird::DrawMatlida(int n, float Cx, float Cy, float RotAngle, float radX, float radY)
{
	if (n < 3) return; // bad number of sides   
	double angle = RotAngle * 3.14159265 / 180;  // initial angle   
	double angleInc = 2 * 3.14159265 / n;         //angle increment 
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	//glVertex2f(Radius + Cx, Cy);
	for (int k = 0; k <= n + 1; k++)  // repeat n times 
	{

		angle += angleInc;
		MatlidaVerticesList.push_back(Point2(radX * cos(angle) + Cx, radY * sin(angle) + Cy));
		glVertex2f(radX * cos(angle) + Cx, radY * sin(angle) + Cy);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	//MatlidaVerticesList.push_back(Point2(Cx - 1.5, Cy - 2));
	glVertex2f(Cx - 0.5 / 1.5, Cy - 1.2 / 1.5);
	//MatlidaVerticesList.push_back(Point2(Cx - 2.5, Cy - 1));
	glVertex2f(Cx - 1 / 1.5, Cy - 0.7 / 1.5);
	//MatlidaVerticesList.push_back(Point2(Cx - 3, Cy - 1.5));
	glVertex2f(Cx - 1.25 / 1.5, Cy - 0.95 / 1.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	//MatlidaVerticesList.push_back(Point2(Cx - 0.5, Cy - 2));
	glVertex2f(Cx - 0 / 1.5, Cy - 1.2 / 1.5);
	//MatlidaVerticesList.push_back(Point2(Cx - 3.3, Cy - 1.8));
	glVertex2f(Cx - 1.4 / 1.5, Cy - 1.1 / 1.5);
	//MatlidaVerticesList.push_back(Point2(Cx - 3.3, Cy - 2.3));
	glVertex2f(Cx - 1.4 / 1.5, Cy - 1.35 / 1.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	//MatlidaVerticesList.push_back(Point2(Cx - 1.5, Cy - 2));
	glVertex2f(Cx - 0.5 / 1.5, Cy - 1.2 / 1.5);
	//MatlidaVerticesList.push_back(Point2(Cx - 3, Cy - 2.6));
	glVertex2f(Cx - 1.25 / 1.5, Cy - 1.5 / 1.5);
	//MatlidaVerticesList.push_back(Point2(Cx - 2.5, Cy - 3));
	glVertex2f(Cx - 1 / 1.5, Cy - 1.7 / 1.5);
	glEnd();

	glColor3f(0, 0, 0); //  hairs
	Ngon(3, Cx - 0.5 / 3, Cy + 5.5 / 3, 0.85 / 3, 1, MatlidaVerticesList);
	Ngon(3, Cx - 0 / 3, Cy + 5.65 / 3, 0.85 / 3, 90, MatlidaVerticesList);
	Ngon(3, Cx - 1 / 3, Cy + 5 / 3, 0.8 / 3, 50, MatlidaVerticesList);

	glColor3f(0.0f, 0.5f, 1.0f);
	Oval(17, Cx + 0 / 3, Cy + 0 / 3, 0, 0.67, 1.84, MatlidaVerticesList);

	//glColor3f(0.658824, 0.658824, 0.658824);
	//glColor3f(0.90, 0.91, 0.98);
	//glColor3f(0.5,0,0);
	glColor3f(0.560784, 0.560784, 0.737255);
	Oval(12, Cx - 0.3, Cy + 0 / 3, 0, 0.25, 0.83, MatlidaVerticesList);
	Oval(12, Cx + 0.3, Cy - 1 / 3, 0, 0.25, 0.83, MatlidaVerticesList);

	glColor3f(0, 0, 0); //outer black eye
	glBegin(GL_POLYGON);
	//MatlidaVerticesList.push_back(Point2(Cx - 0.4, Cy + 2.25));
	glVertex2f(Cx - 0.4 / 3, Cy + 2.25 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx - 0.25, Cy + 1));
	glVertex2f(Cx - 0.25 / 3, Cy + 1 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx - 0.4, Cy + 0.75));
	glVertex2f(Cx - 0.4 / 3, Cy + 0.75 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx - 1.15, Cy + 1));
	glVertex2f(Cx - 1.15 / 3, Cy + 1 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx - 1.75, Cy + 0.75));
	glVertex2f(Cx - 1.75 / 3, Cy + 0.75 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx - 1.9, Cy + 1));
	glVertex2f(Cx - 1.9 / 3, Cy + 1 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx - 1.75, Cy + 2.25));
	glVertex2f(Cx - 1.75 / 3, Cy + 2.25 / 3);
	glEnd();

	glBegin(GL_POLYGON);
	//MatlidaVerticesList.push_back(Point2(Cx + 1.75, Cy + 2.25));
	glVertex2f(Cx + 1.75 / 3, Cy + 2.25 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx + 1.9, Cy + 1));
	glVertex2f(Cx + 1.9 / 3, Cy + 1 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx + 1.75, Cy + 0.75));
	glVertex2f(Cx + 1.75 / 3, Cy + 0.75 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx + 1, Cy + 1));
	glVertex2f(Cx + 1 / 3, Cy + 1 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx + 0.75, Cy + 0.75));
	glVertex2f(Cx + 0.75 / 3, Cy + 0.75 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx + 0.6, Cy + 1));
	glVertex2f(Cx + 0.6 / 3, Cy + 1 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx + 0.75, Cy + 2.25));
	glVertex2f(Cx + 0.75 / 3, Cy + 2.25 / 3);
	glEnd();

	glColor3f(1, 1, 1); //white eye
	glBegin(GL_POLYGON);
	//MatlidaVerticesList.push_back(Point2(Cx - 0.45, Cy + 2.2));
	glVertex2f(Cx - 0.45 / 3, Cy + 2.2 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx - 0.3, Cy + 0.95));
	glVertex2f(Cx - 0.3 / 3, Cy + 0.95 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx - 0.4, Cy + 0.8));
	glVertex2f(Cx - 0.4 / 3, Cy + 0.8 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx - 1.2, Cy + 1.05));
	glVertex2f(Cx - 1.2 / 3, Cy + 1.05 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx - 1.75, Cy + 0.8));
	glVertex2f(Cx - 1.75 / 3, Cy + 0.8 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx - 1.65, Cy + 0.95));
	glVertex2f(Cx - 1.65 / 3, Cy + 0.95 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx - 1.8, Cy + 2.2));
	glVertex2f(Cx - 1.8 / 3, Cy + 2.2 / 3);
	glEnd();

	glBegin(GL_POLYGON);
	//MatlidaVerticesList.push_back(Point2(Cx + 1.7, Cy + 2.2));
	glVertex2f(Cx + 1.7 / 3, Cy + 2.2 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx + 1.85, Cy + 0.95));
	glVertex2f(Cx + 1.85 / 3, Cy + 0.95 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx + 1.75, Cy + 0.8));
	glVertex2f(Cx + 1.75 / 3, Cy + 0.8 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx + 1, Cy + 1.05));
	glVertex2f(Cx + 1 / 3, Cy + 1.05 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx + 0.75, Cy + 0.8));
	glVertex2f(Cx + 0.75 / 3, Cy + 0.8 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx + 0.65, Cy + 0.95));
	glVertex2f(Cx + 0.65 / 3, Cy + 0.95 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx + 0.8, Cy + 2.2));
	glVertex2f(Cx + 0.8 / 3, Cy + 2.2 / 3);
	glEnd();

	glColor3f(0, 0, 0);
	Ngon(15, Cx - 0.9 / 3, Cy + 1.5 / 3, 0.2 / 3, 1, MatlidaVerticesList); //black inner eyes
	Ngon(15, Cx + 1.55 / 3, Cy + 1.5 / 3, 0.2 / 3, 1, MatlidaVerticesList);

	glColor3f(0, 0, 0); //eyebrows
	glBegin(GL_QUADS);
	//MatlidaVerticesList.push_back(Point2(Cx - 2, Cy + 2.4));
	glVertex2f(Cx - 2 / 3, Cy + 2.4 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx - 0.35, Cy + 1.75));
	glVertex2f(Cx - 0.35 / 3, Cy + 1.75 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx - 0.35, Cy + 2.35));
	glVertex2f(Cx - 0.35 / 3, Cy + 2.35 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx - 1.8, Cy + 2.7));
	glVertex2f(Cx - 1.8 / 3, Cy + 2.7 / 3);
	glEnd();
	glBegin(GL_QUADS);
	//MatlidaVerticesList.push_back(Point2(Cx + 0.3, Cy + 1.85));
	glVertex2f(Cx + 0.3 / 3, Cy + 1.85 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx + 2.25, Cy + 2.4));
	glVertex2f(Cx + 2.25 / 3, Cy + 2.4 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx + 2.05, Cy + 2.75));
	glVertex2f(Cx + 2.05 / 3, Cy + 2.75 / 3);
	//MatlidaVerticesList.push_back(Point2(Cx + 0.3, Cy + 2.35));
	glVertex2f(Cx + 0.3 / 3, Cy + 2.35 / 3); //Token Error
	glEnd();

	glColor3f(0, 0, 0); //peak
	Ngon(3, Cx + 0.4 / 3, Cy - 0 / 3, 1.3 / 3, 95, MatlidaVerticesList);
	glColor3f(1.0f, 0.5f, 0.0f);
	Ngon(3, Cx + 0.4 / 3, Cy - 0 / 3, 1.25 / 3, 95, MatlidaVerticesList);
	glColor3f(0, 0, 0);
	Oval(10, Cx + 0.6 / 3, Cy - 0.6 / 3, 0, 1.2 / 3, 0.75 / 3, MatlidaVerticesList);
	glColor3f(1.0f, 0.5f, 0.0f);
	Oval(10, Cx + 0.6 / 3, Cy - 0.65 / 3, 0, 1.15 / 3, 0.7 / 3, MatlidaVerticesList);


}