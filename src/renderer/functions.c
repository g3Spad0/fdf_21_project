#include "../../includes/fdf.h"

t_vector_4		vector_4_for(float x, float y, float z, float w)
{
	t_vector_4	v;

	v.coords.x = x;
	v.coords.y = y;
	v.coords.z = z;
	v.coords.w = w;
	return (v);
}

t_vector_4		mult_vm_4(t_vector_4 v, t_matrix_4 m)
{
	t_vector_4	res;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		res.arr[i] = 0;
		while (j < 4)
		{
			res.arr[i] += v.arr[j] * m.arr[j][i];
			printf("(%.2f, %.2f)", v.arr[j], m.arr[j][i]);
			j++;
		}
		printf("  ");
		i++;
	}
	printf("\n");
	return res;
}

t_matrix_4		mult_m_4(t_matrix_4 m1, t_matrix_4 m2)
{
	t_matrix_4	res;
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			res.arr[i][j] = 0;
			while (k < 4)
			{
				res.arr[i][j] += m1.arr[i][k] * m2.arr[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return res;
}

void	print_matrix(t_matrix_4 m)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%.2f ", m.arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void	print_vertexes(t_vector_4 **vertexes, int array_size, int item_size)
{
	for (int i = 0; i < array_size; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			for (int j = 0; j < item_size; j++)
				printf("%.2f\t", vertexes[i][j].arr[k]);
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");
}