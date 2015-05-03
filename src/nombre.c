/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nombre.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 16:52:20 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 18:21:34 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"

void c_6(float x, float y)
{
	glBegin(GL_LINES);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(x+0.025, y, 0.f);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(x+0.025, y-0.025, 0.f);
	glEnd();
}

void c_7(float x, float y)
{
	glBegin(GL_LINES);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(x+0.025, y-0.025, 0.f);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(x+0.025, y-0.05, 0.f);
	glEnd();
}

void	chiffre(int nb)
{
	char *s;
	int i;
	float y;
	int l;
	int j;

	i = 0;
	y = 0.6;
	s = malloc(10);
	while (i <= 10)
		s[i++] = 0;
	s = ft_itoa(nb);
	i = 0;
	l = ft_strlen(s);
	while (i < 10 - l)
	{
		chiffre_1(0.95, y, 0);
		i++;
		y -= 0.1;
	}
	j = 0;
	y += 0.1;
	while (i <= 10)
	{
		chiffre_1(0.95, y - 0.1, s[j++]-48);
		i++;
		y -= 0.1;
	}


}

void chiffre_1(float x, float y, int i)
{
	if (i == 0 || i == 2 || i == 3 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9)
		c_1(x, y);
	if (i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 8 || i == 9)
		c_2(x, y);
	if (i == 0 || i == 2 || i == 3 || i == 5 || i == 6 || i == 8 || i == 9)
		c_3(x, y);
	if (i == 0 || i == 4 || i == 5 || i == 6 || i == 8 || i == 9)
		c_4(x, y);
	if (i == 0 || i == 2 || i == 6 || i == 8)
		c_5(x, y);
	if (i == 0 || i == 1 || i == 2 || i == 3 || i == 4 || i == 7 || i == 8 || i == 9)
		c_6(x, y);
	if (i == 0 || i == 1 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9)
		c_7(x, y);
}
