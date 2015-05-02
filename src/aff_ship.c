/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_ship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 13:02:51 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/02 21:35:37 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"

void		aff_ship(t_coord pos)
{
	glBegin(GL_QUADS);
	glColor3f(4.1f, 0.1f, 0.1f);
	glVertex2d(pos.x, pos.y);
	glColor3f(0.2f, 04.2f, 0.2f);
	glVertex2d(pos.x, pos.y - 0.05f);
	glColor3f(0.2f, 0.2f, 4.2f);
	glVertex2d(pos.x -0.3f, pos.y -0.05f);
	glColor3f(4.3f, 0.3f, 0.3f);
	glVertex2d(pos.x -0.3f, pos.y);
	glEnd();
}
