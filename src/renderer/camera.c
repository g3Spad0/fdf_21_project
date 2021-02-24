#include "fdf.h"

void    move_camera(t_main *main, int axis, float val)
{
    main->camera.w_position = vector_4_for(0, 0, 0, 1);
    main->camera.w_position.arr[axis] += val;
    main->camera.position = mult_vm_4(main->camera.w_position, 
                        mult_m_4(main->camera.transition, main->camera.rotation));
}

t_matrix_4  get_ur_matrix(float angle)
{
    int			i;
	t_matrix_4	r_matrix;

	ft_bzero(&r_matrix, sizeof(t_matrix_4));
	i = 0;
	r_matrix.arr[1][1] = 1;
    r_matrix.arr[0][0] = cosf(angle);
    r_matrix.arr[0][2] = sinf(angle);
    r_matrix.arr[2][0] = -sinf(angle);
    r_matrix.arr[2][2] = cosf(angle);
	return (r_matrix);
}

t_matrix_4  get_rr_matrix(float angle)
{
    int			i;
	t_matrix_4	r_matrix;

	ft_bzero(&r_matrix, sizeof(t_matrix_4));
	i = 0;
	r_matrix.arr[0][0] = 1;
    r_matrix.arr[1][1] = cosf(angle);
    r_matrix.arr[1][2] = sinf(angle);
    r_matrix.arr[2][1] = -sinf(angle);
    r_matrix.arr[2][2] = cosf(angle);
	return (r_matrix);
}

void    rotate_camera(t_main *main, t_matrix_4 r_matr)
{
    t_vector_4      arr[3];

    // print_matrix(r_matr);
    // print_matrix(main->camera.rotator);
    arr[0] = mult_vm_4(main->w_axises[0], r_matr);
    arr[1] = mult_vm_4(main->w_axises[1], r_matr);
    arr[2] = mult_vm_4(main->w_axises[2], r_matr);

    // printf("rotated:\n");
    // print_vector(arr[0]);
    // print_vector(arr[1]);
    // print_vector(arr[2]);
    main->camera.r_axis = mult_vm_4(arr[0], main->camera.rotation);
    main->camera.u_axis = mult_vm_4(arr[1], main->camera.rotation);
    main->camera.f_axis = mult_vm_4(arr[2], main->camera.rotation);
}