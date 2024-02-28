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
    data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "fractol");
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
    return (0);
}
void manage_hooks(fractol *data)
{
    mlx_hook(data->mlx_win, 2, 1L << 0, key_press, &data);
    mlx_hook(data->mlx_win, 17, 0, exit_program, &data);
}

int main(int argc, char **argv)
{
    fractol data;

    if (!parse_arguments(argc, argv))
        return (1);
    init_data(argv, &data);
    manage_hooks(&data);
    
    mlx_loop(data.mlx);
    return (0);
}