#include "fdf.h"

void    render(t_main *main)
{
    get_vertexes_to_render(main);

    mlx_put_image_to_window(main->mlx_ptr, main->win_ptr, main->display_img, 0, 0);

    for (int i = 0; i < main->array_size - 1; i++)
    {
        for (int j = 0; j < main->item_size - 1; j++)
        {
            if (main->points[i][j].visible || main->points[i][j + 1].visible)
                line(main, main->points[i][j], main->points[i][j + 1], 0xffffff);
            if (main->points[i][j].visible || main->points[i + 1][j].visible)
                line(main, main->points[i][j], main->points[i + 1][j], 0xffffff);
        }
    }
}

int     func(void *param)
{
    t_main *main = (t_main *)param;
        rotate_camera(main, get_ur_matrix(0.05));
        move_camera(main, 2, 0.001);
        render(main);
    return 0;
}

int     key_hook(int key, void *main)
{
    switch (key)
    {
        case 123:
            rotate_camera(main, get_ur_matrix(0.05));
            render(main);
            break;
        case 124:
            rotate_camera(main, get_ur_matrix(-0.05));
            render(main);
            break;
        case 125:
            rotate_camera(main, get_rr_matrix(0.05));
            render(main);
            break;
        case 126:
            rotate_camera(main, get_rr_matrix(-0.05));
            render(main);
            break;
        case 0:
            move_camera(main, 0, -0.1);
            render(main);
            break;
        case 2:
            move_camera(main, 0, 0.1);
            render(main);
            break;
        case 1:
            move_camera(main, 2, -0.1);
            render(main);
            break;
        case 13:
            move_camera(main, 2, 0.1);
            render(main);
            break;
        case 53:
            exit(0);
        default:
            printf("%d\n", key);
    }
    return 0;
}

int mouse_hook(int button,int x,int y,void *main)
{
    printf("%d, %d\n", x, y);
    return(0);
}

void    display(t_main *main)
{
    render(main);
    mlx_key_hook(main->win_ptr, key_hook, main);
    mlx_mouse_hook(main->win_ptr, mouse_hook, main);
}