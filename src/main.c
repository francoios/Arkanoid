/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 09:49:20 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 20:08:59 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int     i;
    char    **tab;
    t_circlePos    movement;

    i = 0;
    ft_init(&movement);
    tab = get_map();
    GLFWwindow* window;
    window = glfwCreateWindow(1280, 960, "game_arkanoid", NULL, NULL);
    ft_process(window);
    glfwPollEvents();
    while (!glfwWindowShouldClose(window))
    {
        ft_resize_and_draw_shit(window, tab);
        ft_do_some_shit(&movement, tab);
        if (pos.breack == 1)
            break ;
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    ft_exit(window);
    return (0);
}
