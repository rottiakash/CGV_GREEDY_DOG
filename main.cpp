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
unsigned int bg1;
int xpos = 0;
int bxpos = 3000, bypos = 1000;
bool thinkCloud = true, spaceDetect = false;

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
        glutIdleFunc(NULL);
    }
}

void key(unsigned char key, int x, int y)
{
    if (key == 'q')
    {
        exit(0);
    }
    if (spaceDetect)
    {
        if (key == SPACEBAR)
        {
            glutIdleFunc(moveDog);
        }
    }
}

void displayScene1(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);
    Dog dog;
    dog.draw(xpos, 700);
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

void idle(void)
{
    if (xpos <= 1900)
    {
        xpos += 30;
        glutPostRedisplay();
    }
    else
    {
        bxpos = 2750;
        bypos = 1600;
        spaceDetect = true;
        glutPostRedisplay();
        glutIdleFunc(NULL);
    }
}
void mouse(int btn, int state, int x, int y)
{
    if (btn == GLUT_LEFT && state == GLUT_DOWN)
    {
        thinkCloud = false;
        glutIdleFunc(idle);
    }
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

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 700);
    glutCreateWindow("A Greedy Dog");
    glutDisplayFunc(displayScene1);
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);
    loadBackground();
    glEnable(GL_DEPTH_TEST);
    glutTimerFunc(1000, timer, 0);
    init();
    glutMainLoop();
}
