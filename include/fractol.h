#pragma once 

#include <mlx.h>
#include "libft.h"

typedef struct
{
    void    *mlx;
    void    *mlx_win;
    void    *mlx_img;

    int     type;

    int     up;
    int     down;
    int     right;
    int     left;
} fractol;

#define MANDELBROT 0
#define JULIA 1

#define ESC 53
#define UP 126
#define DOWN 125
#define RIGHT 124
#define LEFT 123

#define PRESS 1
#define RELEASE 0

#define SCREENX 500
#define SCREENY 500

/* fractol functions */

int main(int argc, char **argv);