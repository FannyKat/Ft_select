#include "ft_select.h"

int		deal_keys(t_select *select)
{
	char	*buff;

	buff = ft_strnew(sizeof(*buff) * 5);
	read(0, buff, 5);
	check_arrow(select, buff);
	return (1);
}
