/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuardoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 20:39:00 by tuardoui          #+#    #+#             */
/*   Updated: 2015/05/03 21:28:24 by tuardoui         ###   ########.fr       */
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
		if (pos.x < 0.91)
			pos.x += 0.04;
	}
	if (key == 263 && action != GLFW_RELEASE)
	{
		if (pos.x > -0.62)
			pos.x = pos.x - 0.04;
	}
	if (key == 32 && action != GLFW_RELEASE)
	{
		pos.space = 1;
	}
}

void			ft_process(GLFWwindow *window)
{
	glfwMakeContextCurrent(window);
	glfwSwapInterval(0);
	glfwSetKeyCallback(window, key_callback);
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
	pos.x = xmove;
}

void			ft_init(t_circlePos *movement)
{
	movement->xPos = 0.f;
	movement->yPos = -0.7f;
	movement->xVec = 0.00f;
	movement->yVec = 0.00f;
	movement->cnt = 0;
	movement->life = 3;
	pos.x = -0.1;
	pos.y = -0.8;
	pos.space = 0;
	pos.replay = 1;
	pos.breack = 0;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
}
