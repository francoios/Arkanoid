/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 20:39:00 by tuardoui          #+#    #+#             */
/*   Updated: 2015/05/03 21:54:04 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"

static	void	error_callback(int error, const char *description)
{
	fputs(description, stderr);
}

static	void	key_callback(GLFWwindow *window, int key, int scancode,
		int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == 262 && action != GLFW_RELEASE)
	{
		if (g_pos.x < 0.91)
			g_pos.x += 0.04;
	}
	if (key == 263 && action != GLFW_RELEASE)
	{
		if (g_pos.x > -0.62)
			g_pos.x = g_pos.x - 0.04;
	}
	if (key == 32 && action != GLFW_RELEASE)
	{
		g_pos.space = 1;
	}
}

void			ft_process(GLFWwindow *window)
{
	glfwMakeContextCurrent(window);
	glfwSwapInterval(0);
	glfwSetKeyCallback(window, key_callback);
	glfwSetWindowSizeCallback(window, windowsizecallback);
	glfwSetCursorPosCallback(window, cursor_pos_callback);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
}

static	void	cursor_pos_callback(GLFWwindow *window, double x, double y)
{
	double	xmove;

	xmove = x / 1000;
	g_pos.x = xmove;
}

void			ft_init(t_circlepos *movement)
{
	movement->xpos = 0.f;
	movement->ypos = -0.7f;
	movement->xvec = 0.00f;
	movement->yvec = 0.00f;
	movement->cnt = 0;
	movement->life = 3;
	g_pos.x = -0.1;
	g_pos.y = -0.8;
	g_pos.space = 0;
	g_pos.replay = 1;
	g_pos.breack = 0;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
}
