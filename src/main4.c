/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 20:30:57 by tuardoui          #+#    #+#             */
/*   Updated: 2015/05/03 21:55:41 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"

void			draw_circle(float x1, float y1)
{
	float	x2;
	float	y2;
	float	angle;
	double	radius;

	radius = 0.015;
	glColor3f(0, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);
	angle = 0.0f;
	while (angle < 2 * 3.14159)
	{
		x2 = x1 + ft_sin(angle) * radius;
		y2 = y1 + ft_cos(angle) * radius;
		glVertex2f(x2, y2);
		angle += 0.001;
	}
	glEnd();
}

void			windowsizecallback(GLFWwindow *window, int width, int height)
{
	if (height < 100)
	{
		ft_putendl("the window is too small");
		exit(-1);
	}
}

void			move_circle(t_circlepos *movement)
{
	movement->xpos = movement->xpos + movement->xvec;
	movement->ypos = movement->ypos + movement->yvec;
	draw_circle(movement->xpos, movement->ypos);
}

void			calculpolision(t_circlepos *movement, int direction)
{
	if (direction == 1)
	{
		movement->xvec = movement->xvec * -1;
	}
	if (direction == 2)
	{
		movement->yvec = movement->yvec * -1;
	}
	if (direction == 3)
	{
		movement->xvec = movement->xvec * -1;
	}
	if (direction == 4)
	{
		movement->yvec = movement->yvec * -1;
	}
}

void			calculcolision2(t_circlepos *movement, int direction)
{
	if (direction == 1)
	{
		(movement)->xvec = (movement)->xvec * -1;
	}
	if (direction == 2)
	{
		(movement)->yvec = (movement)->yvec * -1;
	}
	if (direction == 3)
	{
		(movement)->xvec = (movement)->xvec * -1;
	}
	if (direction == 4)
	{
		(movement)->yvec = (movement)->yvec * -1;
	}
}
