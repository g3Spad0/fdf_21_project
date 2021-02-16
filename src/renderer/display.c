#include "fdf.h"

void    display(t_main *main)
{
    printf("qwrerwfsf\n");
    get_vertexes_to_render(main);

    for (int i = 0; i < main->array_size - 1; i++)
    {
        for (int j = 0; j < main->item_size - 1; j++)
        {
            printf("(%d, %d, %d), ", main->points[i][j].x, main->points[i][j].y, main->points[i][j].visible);

            if (main->points[i][j].visible || main->points[i][j + 1].visible)
                line(main, main->points[i][j], main->points[i][j + 1], 0xffffff);
            if (main->points[i][j].visible || main->points[i + 1][j].visible)
                line(main, main->points[i][j], main->points[i + 1][j], 0xffffff);
        }
        printf("\n");
    }
        printf("gtuhufhfqwrerwfsf\n");

}