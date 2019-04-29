#include "ft_select.h"

void			my_error(char *str)
{
	my_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

int			main(int ac, char **av)
{
	t_select	*select;

	if (ac > 1)
	{
		init(&select, ac, av);
		ft_select(select);
	}
	else
		my_printf("Usage : ./ft_select [...]\n");
	return (0);
}
