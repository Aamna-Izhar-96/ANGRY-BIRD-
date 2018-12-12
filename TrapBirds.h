
#include <glut.h>
#include "RGBA.h"
RGBApixmap pix[100];
class TrapBirds
{
public:
	float PosX;
	float PosY;
	void RenderImage(float x, float y, int ImgID);
	void LoadImg(int ImgID, char* Name, int r, int g, int b);
	void SetPosition(float x, float y);
	int IsUp=1;
	int IsDown=0;
	int ImgID;
	
};

void TrapBirds::SetPosition(float x, float y)
{
	this->PosX = x;
	this->PosY = y;
}
void TrapBirds::RenderImage(float x, float y, int ImgID)
{
	
	glRasterPos2f(x, y);
	pix[ImgID].mDraw();
}
void TrapBirds::LoadImg(int ImgID,char* name,int r,int g,int b)
{
	
	
	pix[ImgID].readBMPFile(name, 1);
	pix[ImgID].setChromaKey(r, g, b);
}