#pragma once 

#include <mlx.h>
#include <math.h>
#include "libft.h"

typedef struct
{
    void    *mlx;
    void    *mlx_win;
    void    *mlx_img;
    char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;


    int     up;
    int     down;
    int     right;
    int     left;

    int type;
    int zoom;
    int x;
    int y;
} fractol;

#define MANDELBROT 0
#define JULIA 1

#define ESC 53
#define UP 126
#define DOWN 125
#define RIGHT 124
#define LEFT 123

#define SCROLLUP 4 
#define SCROLLDOWN 5

#define PRESS 1
#define RELEASE 0

#define SCREENX 1920
#define SCREENY 1080

/* fractol functions */

int     main(int argc, char **argv);

/* tools */

void    init_data(char **argv, fractol *data);
int     exit_program(fractol *data);
int     parse_arguments(int argc, char **argv);

/* hooks */

int     manage_hooks(fractol *data);
int     key_press(int key, fractol *data);
int     key_released(int key, fractol *data);
int     mouse_manage(int key, int x, int y, fractol *data);

/* drawing */

void	my_mlx_pixel_put(fractol *data, int x, int y, int color);
void    set_fractol(fractol *data);

/* fractals */