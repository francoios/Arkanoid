/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_brick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 13:02:40 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/02 17:28:52 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"

void		get_brick(float y, float x, char c, float f, float e)
{
	if (c == '1')
	{
		glBegin(GL_QUADS);
		printf("x== %f y== %f\n", x, y);
		printf("e== %f f== %f\n", e, f);
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
	if (c == '2')
	{
		glBegin(GL_QUADS);
		printf("x== %f y== %f\n", x, y);
		printf("e== %f f== %f\n", e, f);
		glColor3f(0.f, 1.f, 0.f);
		glVertex2d(-x, -y);
		glColor3f(0.f, 1.f, 0.f);
		glVertex2d(-x, -y + -e/100 * 98);
		glColor3f(0.f, 1.f, 0.f);
		glVertex2d(-x + -f/100 * 90, -y + -e/100 * 98);
		glColor3f(0.f, 1.f, 0.f);
		glVertex2d(-x + -f/100 * 90, -y);
		glEnd();
	}
	if (c == '3')
	{
		glBegin(GL_QUADS);
		printf("x== %f y== %f\n", x, y);
		printf("e== %f f== %f\n", e, f);
		glColor3f(1.f, 1.f, 0.f);
		glVertex2d(-x, -y);
		glColor3f(1.f, 1.f, 0.f);
		glVertex2d(-x, -y + -e/100 * 98);
		glColor3f(1.f, 1.f, 0.f);
		glVertex2d(-x + -f/100 * 90, -y + -e/100 * 98);
		glColor3f(1.f, 1.f, 0.f);
		glVertex2d(-x + -f/100 * 90, -y);
		glEnd();
	}
	if (c == '4')
	{
		glBegin(GL_QUADS);
		printf("x== %f y== %f\n", x, y);
		printf("e== %f f== %f\n", e, f);
		glColor3f(0.f, 1.f, 1.f);
		glVertex2d(-x, -y);
		glColor3f(0.f, 1.f, 1.f);
		glVertex2d(-x, -y + -e/100 * 98);
		glColor3f(0.f, 1.f, 1.f);
		glVertex2d(-x + -f/100 * 90, -y + -e/100 * 98);
		glColor3f(0.f, 1.f, 1.f);
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
