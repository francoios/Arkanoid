/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_brick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 13:02:40 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 19:42:42 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"

void			get_brick(float y, float x, char c, float f[])
{
	if (c == '5')
		print_brick_5(y, x, f[0], f[1]);
	if (c == '1')
		print_brick_1(y, x, f[0], f[1]);
	if (c == '4')
		print_brick_4(y, x, f[0], f[1]);
	if (c == '2')
		print_brick_2(y, x, f[0], f[1]);
	if (c == '3')
		print_brick_3(y, x, f[0], f[1]);
}

void			aff_brick(char **map)
{
	int			*t;
	float		c[2];

	t = ft_get_lenght(map);
	c[0] = ((float)2 / t[1]);
	c[1] = ((float)1 / t[0]);
	posb.bmax = t[1];
	posb.imax = t[0];
	t[0] = 0;
	while (map[t[0]][0] != '\0')
	{
		t[1] = 0;
		while (map[t[0]][t[1]])
		{
			if (map[t[0]] && map[t[0]][t[1]] && map[t[0]][t[1]] > '0' &&
			map[t[0]][t[1]] < '6')
			{
				get_brick((float)((float)t[0] / (float)posb.imax) * 2 - 1.0,
				(float)((float)t[1] / (float)posb.bmax)
				* 2 - 1.0, map[t[0]][t[1]], c);
			}
			t[1]++;
		}
		t[0]++;
	}
}

char			**ft_mid_check(char **tab, t_circlePos *movement)
{
	if (movement->xPos <= -posb.xpos_b - posb.e &&
	movement->xPos >= -posb.xpos_b - ((posb.e / 100) * 110) &&
	movement->yPos <= -posb.ypos_b && movement->yPos >= -posb.ypos_b - posb.f)
	{
		calculColision2(&movement, 1);
		if (tab[posb.i][posb.b] != '4')
		{
			movement->cnt += 10;
			tab[posb.i][posb.b] = tab[posb.i][posb.b] - 1;
		}
	}
	if (movement->yPos >= -posb.ypos_b - posb.f &&
	movement->yPos <= -(posb.ypos_b / 100) * 110 &&
	movement->xPos <= -posb.xpos_b && movement->xPos >= -posb.xpos_b - posb.e)
	{
		calculColision2(&movement, 2);
		if (tab[posb.i][posb.b] != '4')
		{
			movement->cnt += 10;
			tab[posb.i][posb.b] = tab[posb.i][posb.b] - 1;
		}
	}
	return (tab);
}

char			**ft_check(char **tab, t_circlePos *movement)
{
	if (movement->yPos >= -posb.ypos_b &&
	movement->yPos <= -posb.ypos_b - (posb.f / 100) * -10 &&
	movement->xPos <= -posb.xpos_b && movement->xPos >= -posb.xpos_b - posb.e)
	{
		calculColision2(&movement, 4);
		if (tab[posb.i][posb.b] != '4')
		{
			movement->cnt += 10;
			tab[posb.i][posb.b] = tab[posb.i][posb.b] - 1;
		}
	}
	if (movement->xPos >= -posb.xpos_b &&
	movement->xPos <= -posb.xpos_b - (posb.e / 100) * -10 &&
	movement->yPos <= -posb.ypos_b && movement->yPos >= -posb.ypos_b - posb.f)
	{
		calculColision2(&movement, 3);
		if (tab[posb.i][posb.b] != '4')
		{
			movement->cnt += 10;
			tab[posb.i][posb.b] = tab[posb.i][posb.b] - 1;
		}
	}
	tab = ft_mid_check(tab, movement);
	return (tab);
}

char			**check_colision_map(char **map, t_circlePos *movement)
{
	posb.i = 0;
	posb.e = (((float)2 / posb.bmax) / 100) * 98;
	posb.f = (((float)1 / posb.imax) / 100) * 90;
	while (map[posb.i][0] != '\0')
	{
		posb.b = 0;
		while (map[posb.i][posb.b])
		{
			if (map[posb.i] && map[posb.i][posb.b] &&
			map[posb.i][posb.b] > '0' && map[posb.i][posb.b] < '5')
			{
				posb.ypos_b = (float)((float)posb.i / (float)posb.imax)
				* 2 - 1.0;
				posb.xpos_b = (float)((float)posb.b / (float)posb.bmax)
				* 2 - 1.0;
				map = ft_check(map, movement);
			}
			posb.b++;
		}
		posb.i++;
	}
	return (map);
}
