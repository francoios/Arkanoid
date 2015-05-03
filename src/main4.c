#include "../game_arkanoid.h"

void  drawCircle(float x1, float y1)
{
    float x2,y2;
    float angle;
    double radius = 0.015;

    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1,y1);
    angle = 0.0f;
    while (angle < 2 * 3.14159)
    {
        x2 = x1 + ft_sin(angle) * radius;
        y2 = y1 + ft_cos(angle) * radius;
        glVertex2f(x2,y2);
        angle += 0.001;
    }
    glEnd();
}

void    moveCircle(t_circlePos *movement)
{
    movement->xPos = movement->xPos + movement->xVec;
    movement->yPos = movement->yPos + movement->yVec;
    drawCircle(movement->xPos, movement->yPos);
}

t_circlePos     calculColision(t_circlePos *movement, int direction)
{
    if (direction == 1)
    {
        movement->xVec = movement->xVec * -1;
    }
    if (direction == 2)
    {
        movement->yVec = movement->yVec * -1;
    }
    if (direction == 3)
    {
        movement->xVec = movement->xVec * -1;
    }
    if (direction == 4)
    {
        movement->yVec = movement->yVec * -1;
    }
    return (*movement);
}

t_circlePos     calculColision2(t_circlePos **movement, int direction)
{
    if (direction == 1)
    {
        (*movement)->xVec = (*movement)->xVec * -1;
    }
    if (direction == 2)
    {
        (*movement)->yVec = (*movement)->yVec * -1;
    }
    if (direction == 3)
    {
        (*movement)->xVec = (*movement)->xVec * -1;
    }
    if (direction == 4)
    {
        (*movement)->yVec = (*movement)->yVec * -1;
    }
    return (**movement);
}



