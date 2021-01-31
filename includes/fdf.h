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
# include "../libft/includes/libft.h"
# include <stdio.h>

# define INVALID_FILE_CONTENT "Error. Invalid file content"


typedef struct		s_main
{
	int				array_size;
	int				item_size;
	int				**items;
}					t_main;

typedef struct		s_join
{
	char			*str;
	size_t			length;
	struct s_join	*next;
}					t_join;

void				die_reason(const char *reason);
void				die();
char				*file_get_contents(int ch);
void            	ft_help(void);
t_main				*init(char *source);


#endif
