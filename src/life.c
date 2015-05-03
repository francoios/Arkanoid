/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 17:20:18 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 20:29:03 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"

void		drawcircle2(float x1, float y1)
{
	float	x2;
	float	y2;
	float	angle;
	double	radius;

	radius = 0.0095;
	glColor3f(1, 1, 1);
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

void		ft_draw_life(int life)
{
	if (life >= 1)
		drawcircle2(-0.95, -0.95);
	if (life >= 2)
		drawcircle2(-0.95, -0.9);
	if (life >= 3)
		drawcircle2(-0.95, -0.85);
}
