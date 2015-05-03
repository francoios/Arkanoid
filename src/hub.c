/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 13:03:18 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 18:24:11 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"

void			print_brick_1(float y, float x, float f, float e)
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
void			print_brick_2(float y, float x, float f, float e)
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
void			print_brick_3(float y, float x, float f, float e)
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
void			print_brick_4(float y, float x, float f, float e)
{
	glBegin(GL_QUADS);
	glColor3f(0.f, 16.f, 1.f);
	glVertex2d(-x, -y);
	glColor3f(16.f, 1.f, 0.f);
	glVertex2d(-x, -y + -e/100 * 98);
	glColor3f(1.f, 16.f, 0.f);
	glVertex2d(-x + -f/100 * 90, -y + -e/100 * 98);
	glColor3f(1.f, 1.f, 0.f);
	glVertex2d(-x + -f/100 * 90, -y);
	glEnd();
}
void			print_brick_5(float y, float x, float f, float e)
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
