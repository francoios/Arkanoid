/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 09:49:20 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 17:59:52 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


t_coord pos;
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (key == 262 && action != GLFW_RELEASE)
    {
        if (pos.x < 0.91)
        pos.x += 0.04;
    }
    if (key == 263 && action != GLFW_RELEASE)
    {
        if (pos.x > -0.62)
        pos.x = pos.x - 0.04;
    }
    // if (key == 333 && action != GLFW_RELEASE)
    // {
    //     pos.speed -= 0.0001f;
    // }
    // if (key == 334 && action != GLFW_RELEASE)
    // {
    //     pos.speed += 0.0001f;
    // }
    printf("%d\n", key);
}


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
        x2 = x1 + sin(angle) * radius;
        y2 = y1 + cos(angle) * radius;
        glVertex2f(x2,y2);
        angle += 0.001;
    }
    glEnd();
}

t_circlePos     moveCircle(t_circlePos *movement)
{
    movement->xPos = movement->xPos + movement->xVec;
    movement->yPos = movement->yPos + movement->yVec;
    drawCircle(movement->xPos, movement->yPos);
    return (*movement);
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

void    ft_init(t_circlePos *movement)
{
    movement->xPos = 0.f;
    movement->yPos = -0.7f;
    movement->xVec = 0.0010f;
    movement->yVec = 0.0010f;
    movement->cnt = 0;
    movement->life = 3;
    pos.x = -0.1;
    pos.y = -0.8;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
}

void    ft_process(GLFWwindow* window)
{
    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);
    glfwSetKeyCallback(window, key_callback);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}

int main(void)
{
    int i;
    char **tab;
    float x1;
    float y1;
    t_circlePos    movement;


    i = 0;
    x1 = -0.04f;
    y1 = -0.5f;
    ft_init(&movement);
    tab = get_map();
    GLFWwindow* window;

    window = glfwCreateWindow(1280, 960, "game_arkanoid", NULL, NULL);

    ft_process(window);
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, 0, 0, 0, 0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
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
        aff_ship(pos);
        tab = aff_brick(tab);
        chiffre(movement.cnt);
        ft_draw_life(movement.life);
        movement = moveCircle(&movement);
        tab = check_colision_map(tab, &movement);
        if (movement.xPos > 0.92)
            calculColision(&movement, 3);
        if (movement.yPos > 0.92)
            calculColision(&movement, 2);
       if (movement.xPos < -0.92)
           calculColision(&movement, 1);
       if (movement.yPos < -1.10)
       {
            movement.xPos = 0.f;
            movement.yPos = -0.7f;
            movement.xVec = 0.0010f;
            movement.yVec = 0.0010f;
            movement.life--;
       }
       if (movement.life == 0)
            break;
       if (movement.yPos <= pos.y && movement.yPos >= pos.y -0.05f &&movement.xPos <= pos.x && movement.xPos >= pos.x -0.3f)
       {
            calculColision(&movement, 4);
       }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return (0);
}
