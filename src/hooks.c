#include "fractol.h"

int key_press(int key, fractol *data)
{
    if (key == ESC)
        exit_program(data);
    if (key == UP)
        data->up = PRESS;
    if (key == DOWN)
        data->down = PRESS;
    if (key == RIGHT)
        data->right = PRESS;
    if (key == LEFT)
        data->left = PRESS;
    return (0);
}

int key_released(int key, fractol *data)
{
    (void)data;
    if (key == UP)
        data->up = RELEASE;
    if (key == DOWN)
        data->down = RELEASE;
    if (key == RIGHT)
        data->right = RELEASE;
    if (key == LEFT)
        data->left = RELEASE;
    return (0);
}

int mouse_manage(int key, int x, int y, fractol *data)
{
    (void)x;
    (void)y;
    if (key == SCROLLUP)
        data->zoom *= 1.25;
    if (key == SCROLLDOWN)
        data->zoom /= 1.25;
    return (0);
}

int manage_hooks(fractol *data)
{
    mlx_hook(data->mlx_win, 2, 1L << 0, key_press, data);
    mlx_hook(data->mlx_win, 17, 0, exit_program, data);
    mlx_key_hook(data->mlx_win, key_released, data);
    mlx_mouse_hook(data->mlx_win, mouse_manage, data);
    set_fractol(data);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
    return (0);
}