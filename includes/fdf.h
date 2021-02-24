/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:26:58 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/03 16:26:59 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# define WINDOW_HEIGHT 500
# define WINDOW_WIDTH 500
# define INVALID_FILE_CONTENT "Error. Invalid file content"


typedef struct		s_join
{
	char			*str;
	size_t			length;
	struct s_join	*next;
}					t_join;

struct			s_vector_4
{
	float	x;
	float	y;
	float	z;
	float	w;
};

typedef union			u_vector_4
{
	struct s_vector_4	coords;
	float 				arr[4];
}						t_vector_4;

typedef struct			s_matrix_4
{
	float				arr[4][4];
}						t_matrix_4;

typedef struct			s_point
{
	int					x;
	int					y;
	char				visible;
}						t_point;

typedef struct			s_camera
{
	t_vector_4			position;
	t_vector_4			w_position;
	t_vector_4			r_axis;
	t_vector_4			u_axis;
	t_vector_4			f_axis;
	t_matrix_4			rotation;
	t_matrix_4			transition;
}						t_camera;

typedef struct		s_main
{
	int				array_size;
	int				item_size;
	int				**items;
	void			*mlx_ptr;
	void			*win_ptr;
	t_vector_4		**vertexes;
	t_vector_4		**vertexes_to_display;
	t_point			**points;
	t_camera		camera;
	t_vector_4		w_axises[3];
	void			*display_img;
	char			*display_buff;
}					t_main;

void				die_reason(const char *reason);
void				die();
char				*file_get_contents(int ch);
void            	ft_help(void);
t_main				*init(char *source);

void    			display(t_main *main);
t_vector_4			mult_vm_4(t_vector_4 v, t_matrix_4 m);
t_matrix_4			mult_m_4(t_matrix_4 m1, t_matrix_4 m2);
t_vector_4			vector_4_for(float x, float y, float z, float w);
void				get_vertexes_to_render(t_main *main);
void    			init_display(t_main *main);
t_matrix_4  		get_ur_matrix(float angle);
t_matrix_4  		get_rr_matrix(float angle);
void				rotate_camera(t_main *main, t_matrix_4 r_matr);
void    			move_camera(t_main *main, int axis, float val);
void			line(t_main *main, t_point p1, t_point p2, int color);
void			print_vertexes(t_vector_4 **vertexes, int array_size, int item_size);
void			print_vector(t_vector_4 v);
void			print_matrix(t_matrix_4 m);



#endif
