/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 17:20:18 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 19:01:22 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void  drawCircle2(float x1, float y1)
{
    float x2,y2;
    float angle;
    double radius = 0.0095;

    glColor3f(1, 1, 1);
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


void		ft_draw_life(int life)
{
	if (life >= 1)
		drawCircle2(-0.95, -0.95);
	if (life >= 2)
		drawCircle2(-0.95, -0.9);
	if (life >= 3)
		drawCircle2(-0.95, -0.85);
}
