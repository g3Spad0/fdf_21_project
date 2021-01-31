#include "../includes/fdf.h"

static	void		free_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		++i;
	}
	free(arr);
}

static	int			arr_count(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		++i;
	}
	return (i);
}

static	void		init_item_size(t_main *main, char *str)
{
	char	**arr;

	if (!(arr = ft_strsplit(str, ' ')) || arr[0] == NULL)
		die_reason(INVALID_FILE_CONTENT);
	main->item_size = arr_count(arr);
	free_arr(arr);
}

static	void		parse_str(t_main *main, char *str, int curr)
{
	char	**arr;
	int		i;

	if (!(arr = ft_strsplit(str, ' ')) || arr[0] == NULL)
		die_reason(INVALID_FILE_CONTENT);
	i = 0;
	if (arr_count(arr) != main->item_size)
		die_reason(INVALID_FILE_CONTENT);
	while (i < main->item_size)
	{
		// TODO validate arr[i]
		main->items[curr][i] = ft_atoi(arr[i]);
		++i;
	}
	free_arr(arr);
}

t_main				*init(char *source)
{
	t_main	*main;
	char	**arr;
	int		i;

	main = (t_main*)smart_malloc(sizeof(t_main));
	if (!(arr = ft_strsplit(source, '\n')) || arr[0] == NULL)
		die_reason(INVALID_FILE_CONTENT);
	main->array_size = arr_count(arr);
	i = 0;
	init_item_size(main, arr[0]);
	main->items = (int**)smart_malloc(sizeof(void*) * main->array_size);
	while (i < main->array_size)
	{
		main->items[i] = (int*)smart_malloc(sizeof(int) * main->item_size);
		parse_str(main, arr[i], i);
		++i;
	}
	free_arr(arr);
	return (main);
}
