#include "../includes/fdf.h"

int         main(int argc, char **argv)
{
    t_main  *main;
    char    *str;
    int		ch;

    if (argc != 2 || argv[1] == NULL || ft_strlen(argv[1]) == 0)
        ft_help();
    if ((ch = open(argv[1], O_RDONLY)) == -1)
		die_reason(ft_strjoin("Can't read source file ", argv[1]));
    if (!(str = file_get_contents(ch)))
		die_reason(ft_strjoin("Empty file ", argv[1]));
    main = init(str);
    free(str);
    // TODO render
    return (0);
}