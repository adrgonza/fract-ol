#pragma once 

#include <mlx.h>
#include "libft.h"

typedef struct
{
    void    *mlx;
    void    *mlx_win;

    int     type;
} fractol;

#define MANDELBROT 0
#define JULIA 1

#define ESC 53

/* fractol functions */

int main(int argc, char **argv);