/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 20:23:48 by tuardoui          #+#    #+#             */
/*   Updated: 2015/05/03 21:59:14 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"

void	ft_life_loose(t_circlepos *movement)
{
	movement->xpos = 0;
	movement->ypos = -0.7f;
	movement->xvec = 0.00f;
	movement->yvec = 0.00f;
	movement->life--;
}

int		ft_check_colision_bordure(char **tab, t_circlepos *movement)
{
	tab = check_colision_map(tab, movement);
	if (movement->xpos > 0.92)
		calculpolision(movement, 3);
	if (movement->ypos > 0.92)
		calculpolision(movement, 2);
	if (movement->xpos < -0.92)
		calculpolision(movement, 1);
	if (movement->ypos < -1.10)
	{
		ft_life_loose(movement);
		g_pos.replay = 1;
	}
	if (g_pos.space == 1 && g_pos.replay == 1)
	{
		ft_launch(movement);
		g_pos.space = 0;
		g_pos.replay = 0;
	}
	if (movement->life == 0)
		g_pos.breack = 1;
	if (movement->ypos <= g_pos.y && movement->ypos >= g_pos.y - 0.05f \
		&& movement->xpos <= g_pos.x && movement->xpos >= g_pos.x - 0.3f)
		calculpolision(movement, 4);
}

void	ft_exit(GLFWwindow *window)
{
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

char	**ft_resize_and_draw_shit(GLFWwindow *window, char **tab)
{
	ft_resize(window);
	ft_draw_background();
	aff_ship(g_pos);
	aff_brick(tab);
	return (tab);
}

void	ft_do_some_shit(t_circlepos *movement, char **tab)
{
	chiffre(movement->cnt);
	ft_draw_life(movement->life);
	move_circle(movement);
	ft_check_colision_bordure(tab, movement);
}
