/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 18:18:59 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 20:15:59 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"

void c_1(float x, float y)
{
	glBegin(GL_LINES);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(x, y, 0.f);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(x + 0.025, y, 0.f);
	glEnd();
}

void c_2(float x, float y)
{
	glBegin(GL_LINES);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(x, y - 0.025, 0.f);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(x + 0.025, y - 0.025, 0.f);
	glEnd();
}

void c_3(float x, float y)
{
	glBegin(GL_LINES);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(x, y - 0.05, 0.f);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(x + 0.025, y - 0.05, 0.f);
	glEnd();
}

void c_4(float x, float y)
{
	glBegin(GL_LINES);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(x, y, 0.f);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(x, y - 0.025, 0.f);
	glEnd();
}

void c_5(float x, float y)
{
	glBegin(GL_LINES);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(x, y - 0.025, 0.f);
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(x, y - 0.05, 0.f);
	glEnd();
}
