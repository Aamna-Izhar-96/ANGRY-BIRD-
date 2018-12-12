#include <glut.h>




class Point2
{
  public:
    Point2() { x = y = 0.0f;} // constructor 1
    Point2(float xx,float yy) { x = xx; y = yy;} // constructor 2
    void set(float xx,float yy) { x = xx; y = yy;} 
    
	void setX(float xx) { x=xx;} 
	void setY(float yy) { y=yy;} 

	float getX() { return x;}
    float getY() { return y;}
    
	void draw(void) 
    { glBegin(GL_POINTS); // draw this point
	glVertex2f((GLfloat)x, (GLfloat)y);
      glEnd();
    }// end draw
  private:
    float x, y;
}; // end class Point2
