/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 20:29:37 by tuardoui          #+#    #+#             */
/*   Updated: 2015/05/03 21:51:54 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"

void	ft_launch(t_circlepos *movement)
{
	movement->xvec = 0.001f;
	movement->yvec = 0.001f;
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
