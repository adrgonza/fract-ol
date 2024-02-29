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

int main(int argc, char **argv);