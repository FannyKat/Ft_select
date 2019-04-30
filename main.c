/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 09:51:12 by fcatusse          #+#    #+#             */
/*   Updated: 2019/04/30 14:46:28 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		stock_arg(select, av, ac);
		ft_select(select);
	}
	else
		my_printf("Usage : ./ft_select [...]\n");
	return (0);
}
