/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 09:51:12 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/08 13:54:18 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void			my_error(char *str)
{
	my_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

int				main(int ac, char **av)
{
	t_select	*select;

	if (!isatty(0))
		my_error("is atty");
	if (ac > 1)
	{
		init(&select);
		stock_arg(select, av, ac);
		ft_select(select);
		reset_term(select);
		free_select(select);
	}
	else
		my_printf("Usage : ./ft_select [...]\n");
	return (0);
}
