#include <glut.h>
#include <vector>


using namespace std;
#ifndef __VECTOR_H_INCLUDED__  
#define __VECTOR_H_INCLUDED__




class BoundingCircle
{
public:
	bool IsCollide(vector<Point2> &ListA, vector<Point2> &ListB);
	bool IsMouseCollide(vector<Point2> &List, Point2 Mouse);
	bool IsBoundryCollide(vector<Point2> &List);
	
private: 
	float Bounding(vector<vector2> &List);
	float Bounding(vector<Point2> &List , int Index);
	float MinX, MinY, MaxX, MaxY, RadiusA , RadiusB, Distance;
	float GetDistance(float Value1, float Value2);
	Point2 Center[2];
};

float BoundingCircle::GetDistance(float Value1, float Value2)
{
	return sqrt(Value1*Value1 + Value2* Value2);
	
}


float BoundingCircle::Bounding(vector<Point2> &List  , int Index)
{
	MinX = MaxX = List[0].getX();
	MinY = MaxY = List[0].getY();
	for (int i = 0; i < List.size(); i++)
	{
		if (List[i].getX() < MinX) MinX = List[i].getX();
		if (List[i].getX() > MaxX) MaxX = List[i].getX();
		if (List[i].getY() < MinY) MinY = List[i].getY();
		if (List[i].getY() > MaxY) MaxY = List[i].getY();

	}
	float CenterX = (MaxX + MinX) / 2;
	float CenterY = (MaxY + MinY) / 2;
	this->Center[Index] = Point2(CenterX, CenterY);
	return this->GetDistance(CenterX - MaxX, CenterY - MaxY);


}
bool BoundingCircle::IsCollide(vector<Point2> &ListA , vector<Point2> &ListB)
{
	RadiusA = Bounding(ListA , 0);
	RadiusB = Bounding(ListB , 1);
	Distance = GetDistance(this->Center[1].getX() - this->Center[0].getX(), this->Center[1].getY() - this->Center[0].getY());
	if (Distance < RadiusA + RadiusB)
	{
		return true;
	}
	else
		return false;



}

bool BoundingCircle::IsMouseCollide(vector<Point2> &List, Point2 Mouse)
{
	MinX = MaxX = List[0].getX();
	MinY = MaxY = List[0].getY();
	for (int i = 0; i < List.size(); i++)
	{
		if (List[i].getX() < MinX) MinX = List[i].getX();
		if (List[i].getX() > MaxX) MaxX = List[i].getX();
		if (List[i].getY() < MinY) MinY = List[i].getY();
		if (List[i].getY() > MaxY) MaxY = List[i].getY();
	}

	if ((Mouse.getX()<MaxX && Mouse.getX()> MinX) && (Mouse.getY()<MaxY && Mouse.getY() > MinY))
		return true;
	else
		return false;
}

bool   BoundingCircle::IsBoundryCollide(vector<Point2> &List)
{

	for (int i = 0; i<List.size(); i++)
	{
		if (List[i].getX() >= 20 || List[i].getX() <= -20 || List[i].getY() <= -20 || List[i].getY() >= 20)
		{
			return true;
		}
	}
	return false;

}

#endif


