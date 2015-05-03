/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_arkanoid.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 09:56:04 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 12:45:55 by frcugy           ###   ########.fr       */
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
}				t_coord;


typedef struct   s_circlePos
{
    float       xPos;
    float       yPos;
    float       xVec;
    float       yVec;
    float       rad;
}               t_circlePos;

char		**get_map();
void		get_brick(float x, float y, char c, float e, float f);
char		**aff_brick(char **map);
void		aff_ship(t_coord pos);
t_circlePos     calculColision2(t_circlePos **movement, int direction);
t_circlePos     calculColision(t_circlePos *movement, int direction);


char		**ft_check(char **tab, t_circlePos *movement);
char		**check_colision_map(char **tab, t_circlePos *movement);



#endif
