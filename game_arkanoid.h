/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_arkanoid.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 09:56:04 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 17:29:07 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARKANOID_H
# define ARKANOID_H
# include "includes/libft.h"
#include "glfw-3.1.1/include/GLFW/glfw3.h"

typedef struct	s_coord
{
	float x;
	float y;

	float xpos_b;
	float ypos_b;
	int	i;
	int b;
	int imax;
	int bmax;
	float e;
	float f;
	float speed;
}				t_coord;


typedef struct   s_circlePos
{
    float       xPos;
    float       yPos;
    float       xVec;
    float       yVec;
    float       rad;
    int			cnt;
    int			life;
}               t_circlePos;

char		**get_map();
void		get_brick(float x, float y, char c, float e, float f);
char		**aff_brick(char **map);
void		aff_ship(t_coord pos);
t_circlePos     calculColision2(t_circlePos **movement, int direction);
t_circlePos     calculColision(t_circlePos *movement, int direction);
void chiffre_1(float x, float y, int i);
void	chiffre(int nb);
void c_1(float x, float y);
void c_2(float x, float y);
void c_3(float x, float y);
void c_4(float x, float y);
void c_5(float x, float y);
void c_6(float x, float y);
void c_7(float x, float y);


char		**ft_check(char **tab, t_circlePos *movement);
char		**check_colision_map(char **tab, t_circlePos *movement);



#endif
