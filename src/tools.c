#include "fractol.h"

int exit_program(fractol *data)
{
    ft_bzero(data, sizeof(data));
    exit(0);
}

void    init_data(char **argv, fractol *data)
{
    ft_bzero(data, sizeof(data));
    if (!ft_strncmp("Mandelbrot", argv[1], ft_strlen(argv[1])))
        data->type = MANDELBROT;
    if (!ft_strncmp("Julia", argv[1], ft_strlen(argv[1])))
        data->type = JULIA;
    data->zoom = 1;
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, SCREENX, SCREENY, "fractol");
    data->mlx_img = mlx_new_image(data->mlx, SCREENX, SCREENY);
    data->addr = mlx_get_data_addr(data->mlx_img, &data->bits_per_pixel, &data->line_length, &data->endian);
}

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