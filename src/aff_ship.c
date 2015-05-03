/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_ship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 13:02:51 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 21:57:26 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"

void		aff_ship(t_coord pos)
{
	glBegin(GL_QUADS);
	glColor3f(4.1f, 0.1f, 0.1f);
	glVertex2d(g_pos.x, g_pos.y);
	glColor3f(0.2f, 04.2f, 0.2f);
	glVertex2d(g_pos.x, g_pos.y - 0.05f);
	glColor3f(0.2f, 0.2f, 4.2f);
	glVertex2d(g_pos.x - 0.3f, g_pos.y - 0.05f);
	glColor3f(4.3f, 0.3f, 0.3f);
	glVertex2d(g_pos.x - 0.3f, g_pos.y);
	glEnd();
}
