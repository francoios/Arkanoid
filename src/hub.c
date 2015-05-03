/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 13:03:18 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 12:06:59 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"
// t_coord posb;

// char		**ft_check(char **tab, t_circlePos *movement)
// {
// 	// int		i = 0;
// 	// if (movement->yPos <= posb.ypos_b && movement->xPos <= posb.xpos_b && movement->xPos >= posb.xpos_b -posb.f)
// 	// {
// 	// 	printf("1\n");
// 	// 	i = 4;
// 	// 	calculColision(movement, i);
// 	// //	tab[posb.i][posb.b] = tab[posb.i][posb.b] - 1;
// 	// }
// 	// else if (movement->xPos <= posb.xpos_b && movement->yPos <= posb.ypos_b && movement->yPos >= posb.ypos_b -posb.e)
// 	// {
// 	// 	printf("2\n");
// 	// 	i = 1;
// 	// 	printf("colision xvec = %f\n", movement->xVec);
// 	// 	calculColision(movement, i);
// 	// //	tab[posb.i][posb.b] = tab[posb.i][posb.b] - 1;
// 	// }
// 	// else if (movement->xPos <= posb.xpos_b - posb.f && movement->yPos <= posb.ypos_b && movement->xPos >= posb.ypos_b -posb.e)
// 	// {
// 	// 	printf("3\n");
// 	// 	i = 3;
// 	// 	calculColision(movement, i);
// 	// //	tab[posb.i][posb.b] = tab[posb.i][posb.b] - 1;
// 	// }
// 	// else if (movement->yPos <= posb.ypos_b - posb.e && movement->xPos <= posb.xpos_b && movement->xPos >= posb.xpos_b -posb.f)
// 	// {
// 	// 	printf("4\n");
// 	// 	i = 2;
// 	// 	calculColision(movement, i);
// 	// //	tab[posb.i][posb.b] = tab[posb.i][posb.b] - 1;
// 	// }
// 	return (tab);
// }

// char		**check_colision_map(char **map, t_circlePos *movement)
// {
// 	posb.imax = 0;
// 	while (map[posb.imax][0] != '\0')
// 	{
// 		posb.bmax = 0;
// 		while (map[posb.imax] && map[posb.imax][posb.bmax])
// 		{
// 			printf("toto\n");
// 			posb.bmax++;
// 		}
// 		printf("toto2\n");
// 		posb.imax++;
// 	}
// 	posb.i = 0;
// 	posb.e = ((float)2/posb.bmax);
// 	posb.f = ((float)1/posb.imax);
// 	while (map[posb.i][0] != '\0')
// 	{
// 		printf("toto3\n");
// 		posb.b = 0;
// 		while (map[posb.i][posb.b])
// 		{
// 			printf("toto4\n");
// 			if (map[posb.i] && map[posb.i][posb.b] && map[posb.i][posb.b] > '0' && map[posb.i][posb.b] < '5')
// 			{
// 				printf("toto5\n");
// 				posb.ypos_b = (float)((float)posb.i/(float)posb.imax)*2-1.0;;
// 				posb.xpos_b = (float)((float)posb.b/(float)posb.bmax)*2-1.0;
// 				map = ft_check(map, movement);
// 				printf("sortie\n");
// 			}
// 			posb.b++;
// 		}
// 		posb.i++;
// 	}
// 	printf("bollos\n");
// 	return (map);
// }
