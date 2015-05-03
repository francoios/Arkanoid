/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_arkanoid.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 09:56:04 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 19:22:30 by frcugy           ###   ########.fr       */
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
	int space;
	int     replay;
	int		breack;
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

t_coord pos;

char		**get_map();
void		get_brick(float x, float y, char c, float e, float f);
void		aff_brick(char **map);
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
void			print_brick_1(float y, float x, float f, float e);
void			print_brick_2(float y, float x, float f, float e);
void			print_brick_3(float y, float x, float f, float e);
void			print_brick_4(float y, float x, float f, float e);
void			print_brick_5(float y, float x, float f, float e);
int				*ft_get_lenght(char **map);

//main.c
static void error_callback(int error, const char* description);
void    ft_init(t_circlePos *movement);
void    ft_process(GLFWwindow* window);
static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void    ft_process(GLFWwindow* window);

//main4.c
void    ft_init(t_circlePos *movement);
t_circlePos     calculColision2(t_circlePos **movement, int direction);
t_circlePos     calculColision(t_circlePos *movement, int direction);
void    moveCircle(t_circlePos *movement);
void  drawCircle(float x1, float y1);

// main3.c
void		ft_resize(GLFWwindow* window);
void   		ft_draw_background(void);
void    	ft_launch(t_circlePos *movement);
void    	ft_process(GLFWwindow* window);
static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);

// main2.c
void		ft_do_some_shit(t_circlePos *movement, char  **tab);
char**		ft_resize_and_draw_shit(GLFWwindow* window, char **tab);
void		ft_exit(GLFWwindow* window);
void		ft_life_loose(t_circlePos *movement);
int   		ft_check_colision_bordure(char **tab, t_circlePos *movement);

// math.c
static float		ft_sin2(float x, float my_sin);
float				ft_sin(float x);
static float		ft_cos2(float x, float my_cos);
float				ft_cos(float x);
float				ft_sqrt2(const float n);


char		**ft_check(char **tab, t_circlePos *movement);
char		**check_colision_map(char **tab, t_circlePos *movement);



#endif
