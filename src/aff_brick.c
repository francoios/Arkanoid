/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_brick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 13:02:40 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 15:04:01 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"

t_coord posb;

void		get_brick(float y, float x, char c, float f, float e)
{
	if (c == '4')
	{
		glBegin(GL_QUADS);
		glColor3f(0.f, 0.f, 0.f);
		glVertex2d(-x, -y);
		glColor3f(0.f, 0.f, 0.f);
		glVertex2d(-x, -y + -e*3);
		glColor3f(0.f, 0.f, 0.f);
		glVertex2d(-x + -f, -y + -e*3);
		glColor3f(0.f, 0.f, 0.f);
		glVertex2d(-x + -f, -y);
		glEnd();
	}
	if (c == '1')
	{
		glBegin(GL_QUADS);
		glColor3f(0.f, 10.f, 0.f);
		glVertex2d(-x, -y);
		glColor3f(10.f, 1.f, 10.f);
		glVertex2d(-x, -y + -e/100 * 98);
		glColor3f(0.f, 10.f, 0.f);
		glVertex2d(-x + -f/100 * 90, -y + -e/100 * 98);
		glColor3f(10.f, 1.f, 10.f);
		glVertex2d(-x + -f/100 * 90, -y);
		glEnd();
	}
	if (c == '2')
	{
		glBegin(GL_QUADS);
		glColor3f(5.3f, 200.f, 0.3f);
		glVertex2d(-x, -y);
		glColor3f(0.f, 0.3f, 5.f);
		glVertex2d(-x, -y + -e/100 * 98);
		glColor3f(5.3f, 200.f, 0.3f);
		glVertex2d(-x + -f/100 * 90, -y + -e/100 * 98);
		glColor3f(0.f, 0.9f, 5.f);
		glVertex2d(-x + -f/100 * 90, -y);
		glEnd();
	}
	if (c == '3')
	{
		glBegin(GL_QUADS);
		glColor3f(4.f, 1.f, 1.f);
		glVertex2d(-x, -y);
		glColor3f(1.f, 0.f, 1.f);
		glVertex2d(-x, -y + -e/100 * 98);
		glColor3f(6.f, 0.f, 1.f);
		glVertex2d(-x + -f/100 * 90, -y + -e/100 * 98);
		glColor3f(0.3f, 6.f, 1.f);
		glVertex2d(-x + -f/100 * 90, -y);
		glEnd();
	}
}

char		**aff_brick(char **map)
{
	int i;
	int b;
	int bmax;
	int imax;
	float c;
	float d;

	imax = 0;
	while (map[imax][0] != '\0')
	{
		bmax = 0;
		while (map[imax] && map[imax][bmax])
		{
			bmax++;
		}
		imax++;
	}
	i = 0;
	c = ((float)2/bmax);
	d = ((float)1/imax);
	posb.bmax = bmax;
	posb.imax = imax;
	while (map[i][0] != '\0')
	{
		b = 0;
		while (map[i][b])
		{
			if (map[i] && map[i][b] && map[i][b] > '0' && map[i][b] < '5')
			{
				get_brick((float)((float)i/(float)imax)*2-1.0, (float)((float)b/(float)bmax)*2-1.0, map[i][b], c, d);
			}
			b++;
		}
		i++;
	}
	return (map);
}

char		**ft_check(char **tab, t_circlePos *movement)
{
	int		i = 0;
		printf("mov.ypos = %f\n  posb.ypos_b = %f\n mov.xpos = %f\n posb.xpos = %f\n posb.xpos -f = %f\n posb.f%f\n posb.e %f\n", movement->yPos, posb.ypos_b, movement->xPos, posb.xpos_b, posb.ypos_b - posb.f, posb.f, (posb.e/100)*90);

	if (movement->yPos <= -posb.ypos_b && movement->yPos >= -posb.ypos_b -(posb.f/100)*10 &&movement->xPos <= -posb.xpos_b && movement->xPos >= -posb.xpos_b -posb.e)
	{
		i = 4;
		calculColision2(&movement, i);
		tab[posb.i][posb.b] = tab[posb.i][posb.b] - 1;
	}
	if (movement->xPos <= -posb.xpos_b && movement->xPos >= -posb.xpos_b -(posb.e/100)*10 &&movement->yPos <= -posb.ypos_b && movement->yPos >= -posb.ypos_b -posb.f)
	{
		i = 3;
		calculColision2(&movement, i);
		tab[posb.i][posb.b] = tab[posb.i][posb.b] - 1;
	}
	if (movement->xPos >= -posb.xpos_b - posb.e && movement->xPos <= -posb.xpos_b -((posb.e/100)*90) && movement->yPos <= -posb.ypos_b && movement->yPos >= -posb.ypos_b -posb.f)
	{
		i = 1;
		calculColision2(&movement, i);
		tab[posb.i][posb.b] = tab[posb.i][posb.b] - 1;
	}
	if (movement->yPos >= -posb.ypos_b - posb.f && movement->yPos <= -(posb.ypos_b/100)*90 &&movement->xPos <= -posb.xpos_b && movement->xPos >= -posb.xpos_b -posb.e)
	{
		i = 2;
		calculColision2(&movement, i);
		tab[posb.i][posb.b] = tab[posb.i][posb.b] - 1;
	}
	return (tab);
}

char		**check_colision_map(char **map, t_circlePos *movement)
{
	posb.i = 0;
	posb.e = (((float)2/posb.bmax)/100)*98;
	posb.f = (((float)1/posb.imax)/100)*90;
	while (map[posb.i][0] != '\0')
	{
		posb.b = 0;
		while (map[posb.i][posb.b])
		{
			if (map[posb.i] && map[posb.i][posb.b] && map[posb.i][posb.b] > '0' && map[posb.i][posb.b] < '4')
			{
				posb.ypos_b = (float)((float)posb.i/(float)posb.imax)*2-1.0;;
				posb.xpos_b = (float)((float)posb.b/(float)posb.bmax)*2-1.0;
				map = ft_check(map, movement);
			}
			posb.b++;
		}
		posb.i++;
	}
	return (map);
}
