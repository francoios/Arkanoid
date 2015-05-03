#include "../game_arkanoid.h"

void    ft_life_loose(t_circlePos *movement)
{
    movement->xPos = 0;
    movement->yPos = -0.7f;
    movement->xVec = 0.00f;
    movement->yVec = 0.00f;
    movement->life--;    
}

int   ft_check_colision_bordure(char **tab, t_circlePos *movement)
{
    tab = check_colision_map(tab, movement);
    if (movement->xPos > 0.92)
        calculColision(movement, 3);
    if (movement->yPos > 0.92)
        calculColision(movement, 2);
    if (movement->xPos < -0.92)
       calculColision(movement, 1);
    if (movement->yPos < -1.10)
    {
        ft_life_loose(movement);
        pos.replay = 1;
    }
    if (pos.space == 1 && pos.replay == 1)
    {
        ft_launch(movement);
        pos.space = 0;
        pos.replay = 0;
        
    }
    if (movement->life == 0)
        pos.breack = 1 ;
    if (movement->yPos <= pos.y && movement->yPos >= pos.y -0.05f 
        && movement->xPos <= pos.x && movement->xPos >= pos.x -0.3f)
        calculColision(movement, 4);
}

void    ft_exit(GLFWwindow* window)
{
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

char**    ft_resize_and_draw_shit(GLFWwindow* window, char **tab)
{
    ft_resize(window);
    ft_draw_background();
    aff_ship(pos);
    aff_brick(tab);
    return (tab);
}

void    ft_do_some_shit(t_circlePos *movement, char  **tab)
{
    chiffre(movement->cnt);
    ft_draw_life(movement->life);
    moveCircle(movement);
    ft_check_colision_bordure(tab, movement);
}
