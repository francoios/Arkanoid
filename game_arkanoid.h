/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_arkanoid.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 09:56:04 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/02 18:22:33 by frcugy           ###   ########.fr       */
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
}				t_coord;

char		**get_map();
void		get_brick(float x, float y, char c, float e, float f);
char		**aff_brick(char **map);
void		aff_ship(t_coord pos);

#endif
