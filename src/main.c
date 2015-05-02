/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 09:49:20 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/02 19:41:57 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"
#include <stdlib.h>
#include <stdio.h>

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
        pos.x += 0.02;
    }
    if (key == 263 && action != GLFW_RELEASE)
    {
        if (pos.x > -0.62)
        pos.x = pos.x - 0.02;
    }
}

int main(void)
{
    int i;
    char **tab;

    i = 0;
    pos.x = -0.1;
    pos.y = -0.8;
    tab = get_map();
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(1280, 960, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
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
        glColor3f(9.f, 9.f, 9.f);
        glVertex2d(-1, -1);
        glColor3f(9.f, 9.f, 9.f);
        glVertex2d(1, -1);
        glColor3f(9.f, 9.f, 9.f);
        glVertex2d(1, 1);
        glEnd();
        aff_ship(pos);
        tab = aff_brick(tab);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return (0);
}
