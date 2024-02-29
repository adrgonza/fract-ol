#include "fractol.h"

void	my_mlx_pixel_put(fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void set_fractol(fractol *data)
{
    int i, j;
    i = -1;
    while (++i < SCREENY)
    {
        j = -1;
        while (++j < SCREENX)
        {
            my_mlx_pixel_put(data, j, i, 0XFFBF00);
        }
    }
}
