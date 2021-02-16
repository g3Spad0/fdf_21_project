#include "../includes/fdf.h"

void            ft_help(void)
{
    ft_printf("TODO write help\n");
    exit(1);
}

void			die_reason(const char *reason)
{
	int		fd;

	fd = 1;
	if (reason && reason[0])
		write(fd, reason, ft_strlen(reason));
	write(fd, "\n", 1);
	exit(1);
}

void				die()
{
    int		fd;

	fd = 1;
	write(fd, "ERROR", ft_strlen("ERROR"));
	write(fd, "\n", 1);
	exit(1);
}