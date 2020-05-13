#ifndef BONE_H
#define BONE_H
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include "ellipse.hpp"
#include "line.hpp"

class Bone
{
private:
    Ellipse ellipse;
    Line line;

public:
    void draw(int xpos, int ypos)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        ellipse.setColor(0.6, 0.6, 0.6);
        ellipse.draw(50, 90, 50, 30, 2, false, 0, 360, 2);
        ellipse.draw(50, 30, 50, 30, 2, false, 0, 360, 2);
        ellipse.setColor(0.6, 0.6, 0.6);
        ellipse.draw(350, 90, 50, 30, 2, false, 0, 360, 2);
        ellipse.draw(350, 30, 50, 30, 2, false, 0, 360, 2);
        glColor3f(0.6, 0.6, 0.6);
        glBegin(GL_POLYGON);
        glVertex3f(50, 90, 0);
        glVertex3f(50, 30, 0);
        glVertex3f(350, 30, 0);
        glVertex3f(350, 90, 0);
        glEnd();
        glPopMatrix();
    }
};

#endif /*BONE_H*/