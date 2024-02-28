#include "fractol.h"

int parse_arguments(int argc, char **argv)
{
    if (argc < 2)
        return (ft_printf("Error! Fractol must have an argument (Mandelbrot, Juia)\n"), 0);
    if (!ft_strncmp("Mandelbrot", argv[1], ft_strlen(argv[1])))
    {
        if (argc != 2)
            return (ft_printf("Error! Mandelbrot must not have arguments\n"), 0);
        return (1);
    }
    else if (!ft_strncmp("Julia", argv[1], ft_strlen(argv[1])))
    {
        if (argc != 3)
            return (ft_printf("Error! Julia must have an argument\n"), 0);
        return (1);
    }
    else
        return (ft_printf("Error! %s not found\n", argv[1]), 0);
    return (1);
}

void    init_data(char **argv, fractol *data)
{
    ft_bzero(data, sizeof(data));
    if (!ft_strncmp("Mandelbrot", argv[1], ft_strlen(argv[1])))
        data->type = MANDELBROT;
    if (!ft_strncmp("Julia", argv[1], ft_strlen(argv[1])))
        data->type = JULIA;
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, SCREENX, SCREENY, "fractol");
    data->mlx_img = mlx_new_image(data->mlx, SCREENX, SCREENY);
}

int exit_program(fractol *data)
{
    ft_bzero(data, sizeof(data));
    exit(0);
}

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

int mouse_manage(fractol *data)
{

}

int manage_hooks(fractol *data)
{
    mlx_hook(data->mlx_win, 2, 1L << 0, key_press, data);
    mlx_key_hook(data->mlx_win, key_released, data);
    mlx_mouse_hook(data->mlx_win, mouse_manage, data);
    // to paint and do fractals
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
    mlx_hook(data->mlx_win, 17, 0, exit_program, data);
    return (0);
}

int main(int argc, char **argv)
{
    fractol data;

    if (!parse_arguments(argc, argv))
        return (1);
    init_data(argv, &data);
    mlx_loop_hook(data.mlx, manage_hooks, &data);
    mlx_loop(data.mlx);
}