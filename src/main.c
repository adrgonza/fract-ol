#include "fractol.h"

int main(int argc, char **argv)
{
    fractol data;

    if (!parse_arguments(argc, argv))
        return (1);
    init_data(argv, &data);
    mlx_loop_hook(data.mlx, manage_hooks, &data);
    mlx_loop(data.mlx);
}