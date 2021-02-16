#include "fdf.h"

void    get_vertexes(t_main *main)
{
	int             i;
	int             j;

	main->vertexes = (t_vector_4 **)malloc(main->array_size * sizeof(t_vector_4 *));
	main->vertexes_to_display = (t_vector_4 **)malloc(main->array_size * sizeof(t_vector_4 *));
	main->points = (t_point **)malloc(main->array_size * sizeof(t_point *));
	
	i = -1;
	while (++i < main->array_size)
	{
		main->vertexes[i] = (t_vector_4 *)malloc(main->item_size * sizeof(t_vector_4));
		main->vertexes_to_display[i] = (t_vector_4 *)malloc(main->item_size * sizeof(t_vector_4));
		main->points[i] = (t_point *)malloc(main->item_size * sizeof(t_point));
	}
	i = -1;
	while (++i < main->array_size)
	{
		j = -1;
		while (++j < main->item_size)
		{
			main->vertexes[i][j] = vector_4_for(j, i, 0.2 * main->items[i][j], 1.0);
			printf("%d, ", main->items[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void    init_camera(t_main *main)
{
	main->camera.position = vector_4_for(9, 11, 10, 1);
	main->camera.r_axis = vector_4_for(1, 0, 0, 1);
	main->camera.u_axis = vector_4_for(0, -0.707, 0.707, 1);
	main->camera.f_axis = vector_4_for(0, -0.707, -0.707, 1);
}

void    init_display(t_main *main)
{
	int bpx;
	int bts;
	int end;

	get_vertexes(main);
	init_camera(main);
	main->mlx_ptr = mlx_init();
	main->win_ptr = mlx_new_window(main->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	bpx = 32;
	bts = WINDOW_HEIGHT * 4;
	end = 0;
	main->display_img = mlx_new_image(main->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	main->display_buff = mlx_get_data_addr(main->display_img, &bpx, &bts, &end);
}
