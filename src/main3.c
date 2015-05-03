#include "../game_arkanoid.h"

void    ft_launch(t_circlePos *movement)
{
    movement->xVec = 0.001f;
    movement->yVec = 0.001f;
}

void    ft_draw_background(void)
{
    glBegin(GL_QUADS);
    glColor3f(9.f, 9.f, 9.f);
    glVertex2d(-1, 1);
    glColor3f(9.f, 0.f, 9.f);
    glVertex2d(-1, -1);
    glColor3f(9.f, 9.f, 0.f);
    glVertex2d(1, -1);
    glColor3f(0.f, 9.f, 9.f);
    glVertex2d(1, 1);
    glEnd();
}

void    ft_resize(GLFWwindow* window)
{
    float   ratio;
    int     width;
    int     height;
    
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, 0, 0, 0, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();    
}
