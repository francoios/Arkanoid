/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_brick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 13:02:40 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 22:05:18 by frcugy           ###   ########.fr       */
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
	g_b.bmax = t[1];
	g_b.imax = t[0];
	t[0] = 0;
	while (map[t[0]][0] != '\0')
	{
		t[1] = 0;
		while (map[t[0]][t[1]])
		{
			if (map[t[0]] && map[t[0]][t[1]] && map[t[0]][t[1]] > '0' &&
			map[t[0]][t[1]] < '6')
			{
				get_brick((float)((float)t[0] / (float)g_b.imax) * 2 - 1.0,
				(float)((float)t[1] / (float)g_b.bmax)
				* 2 - 1.0, map[t[0]][t[1]], c);
			}
			t[1]++;
		}
		t[0]++;
	}
}

char			**ft_mid_check(char **tab, t_circlepos *movement)
{
	if (movement->xpos <= -g_b.xpos_b - g_b.e &&
	movement->xpos >= -g_b.xpos_b - ((g_b.e / 100) * 110) &&
	movement->ypos <= -g_b.ypos_b && movement->ypos >= -g_b.ypos_b - g_b.f)
	{
		calculcolision2(movement, 1);
		if (tab[g_b.i][g_b.b] != '4')
		{
			movement->cnt += 10;
			tab[g_b.i][g_b.b] = tab[g_b.i][g_b.b] - 1;
		}
	}
	if (movement->ypos >= -g_b.ypos_b - g_b.f &&
	movement->ypos <= -(g_b.ypos_b / 100) * 110 &&
	movement->xpos <= -g_b.xpos_b && movement->xpos >= -g_b.xpos_b - g_b.e)
	{
		calculcolision2(movement, 2);
		if (tab[g_b.i][g_b.b] != '4')
		{
			movement->cnt += 10;
			tab[g_b.i][g_b.b] = tab[g_b.i][g_b.b] - 1;
		}
	}
	return (tab);
}

char			**ft_check(char **tab, t_circlepos *movement)
{
	if (movement->ypos >= -g_b.ypos_b &&
	movement->ypos <= -g_b.ypos_b - (g_b.f / 100) * -10 &&
	movement->xpos <= -g_b.xpos_b && movement->xpos >= -g_b.xpos_b - g_b.e)
	{
		calculcolision2(movement, 4);
		if (tab[g_b.i][g_b.b] != '4')
		{
			movement->cnt += 10;
			tab[g_b.i][g_b.b] = tab[g_b.i][g_b.b] - 1;
		}
	}
	if (movement->xpos >= -g_b.xpos_b &&
	movement->xpos <= -g_b.xpos_b - (g_b.e / 100) * -10 &&
	movement->ypos <= -g_b.ypos_b && movement->ypos >= -g_b.ypos_b - g_b.f)
	{
		calculcolision2(movement, 3);
		if (tab[g_b.i][g_b.b] != '4')
		{
			movement->cnt += 10;
			tab[g_b.i][g_b.b] = tab[g_b.i][g_b.b] - 1;
		}
	}
	tab = ft_mid_check(tab, movement);
	return (tab);
}

char			**check_colision_map(char **map, t_circlepos *movement)
{
	g_b.i = 0;
	g_b.e = (((float)2 / g_b.bmax) / 100) * 98;
	g_b.f = (((float)1 / g_b.imax) / 100) * 90;
	while (map[g_b.i][0] != '\0')
	{
		g_b.b = 0;
		while (map[g_b.i][g_b.b])
		{
			if (map[g_b.i] && map[g_b.i][g_b.b] &&
			map[g_b.i][g_b.b] > '0' && map[g_b.i][g_b.b] < '5')
			{
				g_b.ypos_b = (float)((float)g_b.i / (float)g_b.imax)
				* 2 - 1.0;
				g_b.xpos_b = (float)((float)g_b.b / (float)g_b.bmax)
				* 2 - 1.0;
				map = ft_check(map, movement);
			}
			g_b.b++;
		}
		g_b.i++;
	}
	return (map);
}
