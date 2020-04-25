#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define STB_IMAGE_IMPLEMENTATION
#define SPACEBAR 32
#include <iostream>
#include "stb_image.h"
#include "dog.hpp"
#include "bone.hpp"
unsigned int bg1, bg2, bg3, bg4, bg5;
int xpos = 0;
int scene = 0;
void displayMoral(void);
int bxpos = 3000, bypos = 1000;
bool thinkCloud = true, spaceDetect = false, backgroundBone = true, boneDropped = false, enableClick = false;
char *line1 = "There is another";
char *line2 = "Dog!!";
char *line = "Click anywhere to proceed";
int drawx = 500;
int drawy = 4000;

void moveDog(void);

void drawtext(float x, float y, char *s)
{
    glColor3f(0, 0, 0);
    glRasterPos2f(x, y);
    for (int i = 0; s[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
}

void displayScene1(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawtext(drawx, drawy, line);
    glDisable(GL_TEXTURE_2D);
    Dog dog;
    dog.draw(xpos, 700, 1);
    if (thinkCloud)
        dog.cloud(1300, 2000, "Oh!! I finally found", "a bone!!");
    Bone bone;
    bone.draw(bxpos, bypos);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, bg1);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void key(unsigned char key, int x, int y)
{
    if (scene == 0)
    {
        if (key == SPACEBAR)
        {
            scene = 1;
            glutDisplayFunc(displayScene1);
            glutPostRedisplay();
        }
    }
    else if (scene == 1)
    {
        if (spaceDetect)
        {
            if (key == SPACEBAR)
            {
                line = "";
                glutIdleFunc(moveDog);
            }
        }
    }
    else if (scene == 2)
    {
        if (boneDropped)
            if (key == SPACEBAR)
            {
                scene++;
                glutDisplayFunc(displayMoral);
                glutPostRedisplay();
            }
    }
    else if (scene == 3)
    {
        if (key == 27)
        {
            exit(0);
        }
    }
}

void displayIntro(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, bg5);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void changeLine(int value)
{
    line1 = "I need that";
    line2 = "Bone also";
    enableClick = true;
    glutPostRedisplay();
}

void displayScene2(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawtext(drawx, drawy, line);
    glDisable(GL_TEXTURE_2D);
    Dog dog;
    dog.draw(1600, 1500, 0.8);
    dog.cloud(2550, 2800, line1, line2);
    Bone bone;
    bone.draw(2250, bypos);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    if (backgroundBone)
        glBindTexture(GL_TEXTURE_2D, bg2);
    else
        glBindTexture(GL_TEXTURE_2D, bg3);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}
void displayMoral(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, bg4);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void idle(void)
{
    if (xpos <= 1900)
    {
        xpos += 30;
        glutPostRedisplay();
    }
    else
    {
        line = "Press Space Bar to continue";
        bxpos = 2750;
        bypos = 1600;
        spaceDetect = true;
        glutPostRedisplay();
        glutIdleFunc(NULL);
    }
}
void vanishBone(int value)
{
    bypos = 6000;
    glutPostRedisplay();
}
void dropBone()
{
    if (!boneDropped)
    {
        if (bypos >= 500)
        {
            bypos -= 30;
            glutPostRedisplay();
        }
        else
        {
            backgroundBone = false;
            line1 = "OH NOOOO!!";
            line2 = "";
            boneDropped = true;
            glutTimerFunc(1000, vanishBone, 0);
            glutIdleFunc(NULL);
        }
    }
}
void mouse(int btn, int state, int x, int y)
{
    if (scene == 1)
    {
        if (btn == GLUT_LEFT && state == GLUT_DOWN)
        {
            thinkCloud = false;
            line = "";
            drawx = 3000;
            drawy = 500;
            glutIdleFunc(idle);
        }
    }
    else if (scene == 2)
    {
        if (enableClick && !boneDropped)
            if (btn == GLUT_LEFT && state == GLUT_DOWN)
            {
                line1 = "Woff Woff!!";
                line2 = "";
                line = "Press Space Bar to proceed to Moral Scene";
                glutPostRedisplay();
                glutIdleFunc(dropBone);
            }
    }
}
void moveDog(void)
{
    if (xpos <= 6000 && bxpos <= 6000)
    {
        xpos += 30;
        bxpos += 30;
        glutPostRedisplay();
    }
    else
    {
        scene++;
        bypos = 2200;
        drawx = 2500;
        drawy = 4000;
        line = "Click anywhere to proceed";
        glutDisplayFunc(displayScene2);
        glutTimerFunc(3000, changeLine, 0);
        glutPostRedisplay();
        glutIdleFunc(NULL);
    }
}

void loadIntro(void)
{
    glGenTextures(1, &bg5);
    glBindTexture(GL_TEXTURE_2D, bg5);
    // set the bg1 wrapping/filtering options (on the currently bound bg1 object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the bg5
    int width, height, nrChannels;
    unsigned char *data = stbi_load("bg5.psd", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load bg1" << std::endl;
    }
    stbi_image_free(data);
}

void loadBackground(void)
{
    glGenTextures(1, &bg1);
    glBindTexture(GL_TEXTURE_2D, bg1);
    // set the bg1 wrapping/filtering options (on the currently bound bg1 object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the bg1
    int width, height, nrChannels;
    unsigned char *data = stbi_load("bg1.psd", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load bg1" << std::endl;
    }
    stbi_image_free(data);
}

void loadBackground2(void)
{
    glGenTextures(1, &bg2);
    glBindTexture(GL_TEXTURE_2D, bg2);
    // set the bg1 wrapping/filtering options (on the currently bound bg1 object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the bg1
    int width, height, nrChannels;
    unsigned char *data = stbi_load("bg2.psd", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load bg2" << std::endl;
    }
    stbi_image_free(data);
}
void loadBackground3(void)
{
    glGenTextures(1, &bg3);
    glBindTexture(GL_TEXTURE_2D, bg3);
    // set the bg1 wrapping/filtering options (on the currently bound bg1 object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the bg3
    int width, height, nrChannels;
    unsigned char *data = stbi_load("bg3.psd", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load bg1" << std::endl;
    }
    stbi_image_free(data);
}

void loadMoral(void)
{
    glGenTextures(1, &bg4);
    glBindTexture(GL_TEXTURE_2D, bg4);
    // set the bg1 wrapping/filtering options (on the currently bound bg1 object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the bg3
    int width, height, nrChannels;
    unsigned char *data = stbi_load("bg4.psd", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load bg1" << std::endl;
    }
    stbi_image_free(data);
}

void init(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 5000, 0, 5000, 0, -500);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1, 1, 1, 1);
}

void timer(int value)
{
    glutPostRedisplay();
}

void processMenu(int option)
{
    switch (option)
    {
    case 1:
        xpos = 0;
        scene = 0;
        bxpos = 3000;
        bypos = 1000;
        thinkCloud = true;
        spaceDetect = false;
        backgroundBone = true;
        boneDropped = false;
        enableClick = false;
        line1 = "There is another";
        line2 = "Dog!!";
        line = "Click anywhere to proceed";
        drawx = 500;
        drawy = 4000;
        glutDisplayFunc(displayIntro);
        glutPostRedisplay();
        break;
    case 2:
        exit(0);
        break;
    }
}

void menu(void)
{

    int menu;

    // create the menu and
    // tell glut that "processMenuEvents" will
    // handle the events
    menu = glutCreateMenu(processMenu);

    //add entries to our menu
    glutAddMenuEntry("Reset", 1);
    glutAddMenuEntry("Exit", 2);

    // attach the menu to the right button
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 700);
    glutCreateWindow("A Greedy Dog");
    glutDisplayFunc(displayIntro);
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);
    loadIntro();
    loadBackground();
    loadBackground2();
    loadBackground3();
    loadMoral();
    menu();
    glEnable(GL_DEPTH_TEST);
    glutTimerFunc(1000, timer, 0);
    init();
    glutMainLoop();
}
