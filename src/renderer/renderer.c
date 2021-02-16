#include "fdf.h"

t_matrix_4      get_transition_matrix(t_main *main)
{
	int			i;
	t_matrix_4	tr_matrix;

	ft_bzero(&tr_matrix, sizeof(t_matrix_4));
	tr_matrix.arr[0][0] = 1;
	tr_matrix.arr[1][1] = 1;
	tr_matrix.arr[2][2] = 1;
	tr_matrix.arr[3][3] = 1;
	tr_matrix.arr[3][0] = -main->camera.position.coords.x;
	tr_matrix.arr[3][1] = -main->camera.position.coords.y;
	tr_matrix.arr[3][2] = -main->camera.position.coords.z;
	return tr_matrix;
}

t_matrix_4		get_rotation_matrix(t_main *main)
{
	int			i;
	t_matrix_4	r_matrix;

	ft_bzero(&r_matrix, sizeof(t_matrix_4));
	i = 0;
	while (i < 3)
	{
		r_matrix.arr[i][0] = main->camera.r_axis.arr[i];
		r_matrix.arr[i][1] = main->camera.u_axis.arr[i];
		r_matrix.arr[i][2] = main->camera.f_axis.arr[i];
		++i;
	}
	r_matrix.arr[3][3] = 1;
	return (r_matrix);
}

void	normalize(t_main *main)
{
	int i;
	int j;
	int k;

	i = -1;
	while (++i < main->array_size)
	{
		j = -1;
		while (++j < main->item_size)
		{
			k = -1;
			while (++k < 4)
			{
				main->vertexes_to_display[i][j].arr[k] /= main->vertexes_to_display[i][j].arr[3];
			}
			main->vertexes_to_display[i][j].coords.x /= (1 * main->vertexes_to_display[i][j].coords.z);
			main->vertexes_to_display[i][j].coords.y /= -(1 * main->vertexes_to_display[i][j].coords.z);
		}
	}
}

void	mult_on_matr(t_main *main, t_vector_4 **vrt, t_matrix_4 matr)
{

	int		i;
	int		j;

	i = -1;
	while (++i < main->array_size)
	{
		j = -1;
		while (++j < main->item_size)
			main->vertexes_to_display[i][j] = mult_vm_4(vrt[i][j], matr);
	}
}

void	get_vertexes_to_render(t_main *main)
{
	t_matrix_4		tr_matr;
	int				i;
	int				j;

	t_matrix_4 t_matr = get_transition_matrix(main);
	t_matrix_4 r_matr = get_rotation_matrix(main);
	tr_matr = mult_m_4(t_matr, r_matr);
	// tr_matr = get_transition_matrix(main);

	mult_on_matr(main, main->vertexes, tr_matr);
	normalize(main);
	print_vertexes(main->vertexes_to_display, main->array_size, main->item_size);

	i = -1;
	while (++i < main->array_size)
	{
		j = -1;
		while (++j < main->item_size)
		{
			main->points[i][j].x = (WINDOW_WIDTH/2) * main->vertexes_to_display[i][j].coords.x;
			main->points[i][j].y = (WINDOW_HEIGHT/2) * main->vertexes_to_display[i][j].coords.y;
			main->points[i][j].visible = 
				main->points[i][j].x > -WINDOW_WIDTH/2 && main->points[i][j].x < WINDOW_WIDTH/2 
				&& main->points[i][j].y > -WINDOW_HEIGHT/2 && main->points[i][j].y < WINDOW_HEIGHT/2;
			main->points[i][j].x += WINDOW_WIDTH/2;
			main->points[i][j].y += WINDOW_HEIGHT/2;
		}
	}
}