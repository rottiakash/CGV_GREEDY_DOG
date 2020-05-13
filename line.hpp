#ifndef LINE_H
#define LINE_H
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
class Line
{
private:
    float color[3];

public:
    void setColor(float r, float g, float b)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }
    void draw(int x1, int y1, int x2, int y2, int depthIndex)
    {
        glColor3fv(color);
        glLineWidth(5);
        glBegin(GL_LINES);
        glVertex3f(x1, y1, depthIndex);
        glVertex3f(x2, y2, depthIndex);
        glEnd();
    }
    void draw(int x1, int y1, int x2, int y2, int depthIndex, int lw)
    {
        glColor3fv(color);
        glLineWidth(lw);
        glBegin(GL_LINES);
        glVertex3f(x1, y1, depthIndex);
        glVertex3f(x2, y2, depthIndex);
        glEnd();
    }
};
#endif /* LINE_H */