#ifndef DOG_H
#define DOG_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "ellipse.hpp"
#include "line.hpp"
#include "circle.hpp"
class Dog
{
private:
    Ellipse ellipse;
    Line line;
    void body(void)
    {
        ellipse.setColor(0.69, 0.5, 0.39);
        ellipse.draw(600, 1000, 400, 200, 5, false, 0, 360, 2);
    }
    void legs(void)
    {
        line.setColor(0, 0, 0);
        line.draw(300, 880, 350, 200, 1, 2);
        ellipse.setColor(0.69, 0.5, 0.39);
        ellipse.draw(420, 200, 70, 30, 1, false, 0, 360);
        line.draw(470, 800, 530, 300, 1, 2);
        ellipse.setColor(0.69, 0.5, 0.39);
        ellipse.draw(600, 300, 70, 30, 1, false, 0, 360);
        //2nd leg
        line.draw(750, 820, 830, 200, 1, 2);
        ellipse.setColor(0.69, 0.5, 0.39);
        ellipse.draw(890, 200, 70, 30, 1, false, 0, 360);
        line.draw(890, 860, 980, 330, 1, 2);
        ellipse.setColor(0.69, 0.5, 0.39);
        ellipse.draw(1045, 305, 70, 30, 1, false, 0, 360);
    }
    void tail(void)
    {
        ellipse.draw(200, 1150, 150, 150, 1, true, 135, 270, 2);
    }
    void face(void)
    {
        ellipse.setColor(0.69, 0.5, 0.39);
        ellipse.draw(1040, 1300, 120, 350, 4, false, 0, 360, 2);
    }
    void ears(void)
    {
        glPushMatrix();
        glRotatef(350, 0, 0, 1);
        ellipse.setColor(0.59, 0.42, 0.29);
        ellipse.draw(640, 1450, 80, 250, 3, false, 0, 360, 2);
        glPopMatrix();
        glPushMatrix();
        glRotatef(10, 0, 0, 1);
        ellipse.setColor(0.59, 0.42, 0.29);
        ellipse.draw(1420, 1100, 80, 250, 3, false, 0, 360, 2);
        glPopMatrix();
    }

    void nose(void)
    {
        ellipse.setColor(0, 0, 0);
        ellipse.draw(1040, 1100, 45, 35, 3, false, 0, 360, 2);
    }

    void eyes(void)
    {
        ellipse.setColor(0, 0, 0);
        ellipse.draw(1020, 1400, 10, 40, 3, false, 0, 360, 2);
        ellipse.setColor(0, 0, 0);
        ellipse.draw(1090, 1400, 10, 40, 3, false, 0, 360, 2);
    }

    void tongue(void)
    {
        ellipse.setColor(0.9, 0.5, 0.5);
        ellipse.draw(1040, 930, 40, 60, 3, false, 150, 390, 2);
        line.setColor(0, 0, 0);
        line.draw(1040, 950, 1040, 900, 2, 2);
        ;
    }
    void drawtext(float x, float y, char *s)
    {
        glColor3f(0, 0, 0);
        glRasterPos2f(x, y);
        for (int i = 0; s[i] != '\0'; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
    }
    void drawtext(float x, float y, char *s, char *Black)
    {
        glColor3f(1, 1, 1);
        glRasterPos2f(x, y);
        for (int i = 0; s[i] != '\0'; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
    }

public:
    void
    draw(int xpos, int ypos)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        body();
        legs();
        tail();
        face();
        ears();
        nose();
        eyes();
        tongue();
        glPopMatrix();
    }
    void cloud(int xpos, int ypos, char *line1, char *line2)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        Circle circle;
        circle.setColor(1, 1, 1);
        circle.draw(80, 80, 80, 1, false);
        circle.draw(120, 270, 200, 1, false);
        Ellipse ellipse;
        ellipse.setColor(1, 1, 1);
        ellipse.draw(680, 400, 300, 200, 1, false, 0, 360);
        drawtext(450, 420, line1);
        drawtext(450, 330, line2);
        glPopMatrix();
    }
    void cloud(int xpos, int ypos, char *line1, char *line2, char *Black)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        Circle circle;
        circle.setColor(0, 0, 0);
        circle.draw(80, 80, 80, 1, false);
        circle.draw(120, 270, 200, 1, false);
        Ellipse ellipse;
        ellipse.setColor(0, 0, 0);
        ellipse.draw(680, 400, 300, 200, 1, false, 0, 360);
        drawtext(450, 420, line1, "black");
        drawtext(450, 330, line2, "black");
        glPopMatrix();
    }
};

#endif /* LINE_H */