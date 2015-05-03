/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_arkanoid.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:41:43 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 22:05:46 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ARKANOID_H
# define GAME_ARKANOID_H
# include "includes/libft.h"
# include "glfw-3.1.1/include/GLFW/glfw3.h"

typedef struct			s_coord
{
	float				x;
	float				y;
	float				xpos_b;
	float				ypos_b;
	int					i;
	int					b;
	int					imax;
	int					bmax;
	float				e;
	float				f;
	float				speed;
	int					space;
	int					replay;
	int					breack;
}						t_coord;
typedef struct			s_circlepos
{
	float				xpos;
	float				ypos;
	float				xvec;
	float				yvec;
	float				rad;
	int					cnt;
	int					life;
}						t_circlepos;
t_coord					g_pos;
char					**get_map();
void					get_brick(float x, float y, char c, float e[]);
void					aff_brick(char **map);
void					aff_ship(t_coord pos);
void					windowsizecallback(GLFWwindow *window, int width,
	int height);
void					chiffre_1(float x, float y, int i);
void					chiffre(int nb);
void					c_1(float x, float y);
void					c_2(float x, float y);
void					c_3(float x, float y);
void					c_4(float x, float y);
void					c_5(float x, float y);
void					c_6(float x, float y);
void					c_7(float x, float y);
void					print_brick_1(float y, float x, float f, float e);
void					print_brick_2(float y, float x, float f, float e);
void					print_brick_3(float y, float x, float f, float e);
void					print_brick_4(float y, float x, float f, float e);
void					print_brick_5(float y, float x, float f, float e);
int						*ft_get_lenght(char **map);
static void				error_callback(int error, const char *description);
void					ft_init(t_circlepos *movement);
void					ft_process(GLFWwindow *window);
static void				cursor_pos_callback(GLFWwindow *window, double xpos,
	double ypos);
static void				key_callback(GLFWwindow *window, int key, int scancode,
	int action, int mods);
void					ft_process(GLFWwindow *window);
void					ft_init(t_circlepos *movement);
void					calculcolision2(t_circlepos *movement, int direction);
void					calculpolision(t_circlepos *movement, int direction);
void					movecircle(t_circlepos *movement);
void					drawcircle(float x1, float y1);
void					ft_resize(GLFWwindow *window);
void					ft_draw_background(void);
void					ft_launch(t_circlepos *movement);
void					ft_process(GLFWwindow *window);
static void				cursor_pos_callback(GLFWwindow *window, double xpos,
	double ypos);
void					ft_do_some_shit(t_circlepos *movement, char **tab);
char					**ft_resize_and_draw_shit(GLFWwindow *window,
	char **tab);
void					ft_exit(GLFWwindow *window);
void					ft_life_loose(t_circlepos *movement);
int						ft_check_colision_bordure(char **tab,
	t_circlepos *movement);
static float			ft_sin2(float x, float my_sin);
float					ft_sin(float x);
static float			ft_cos2(float x, float my_cos);
float					ft_cos(float x);
float					ft_sqrt2(const float n);
char					**ft_check(char **tab, t_circlepos *movement);
char					**check_colision_map(char **tab, t_circlepos *movement);
t_coord					g_b;
#endif
