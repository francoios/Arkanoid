/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuardoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 20:29:37 by tuardoui          #+#    #+#             */
/*   Updated: 2015/05/03 21:27:13 by tuardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"

void	ft_launch(t_circlePos *movement)
{
	movement->xVec = 0.001f;
	movement->yVec = 0.001f;
}

void	ft_draw_background(void)
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

void	ft_resize(GLFWwindow *window)
{
	float	ratio;
	int		width;
	int		height;

	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, 0, 0, 0, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
