#include <mlx.h>
#include <stdlib.h>

void    a()
{
    system("leaks a.out");
}

int main()
{
    atexit(a);
    void    *mlx;
    void    *mlx_win;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 15, 35, "xx");
    mlx_destroy_window(mlx, mlx_win);
}