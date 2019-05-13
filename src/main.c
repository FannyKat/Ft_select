/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 09:51:12 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/13 18:37:21 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void			my_error(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}

int				main(int ac, char **av)
{
	t_select	*select;

	if (!isatty(0))
		my_error("isatty error");
	if (ac > 1)
	{
		init(&select);
		stock_arg(select, av, ac);
		ft_select(select);
		reset_term(select);
		close(select->fd);
		free_select(select);
	}
	else
		ft_putstr_fd("Usage : ./ft_select [...]\n", 2);
	return (0);
}
