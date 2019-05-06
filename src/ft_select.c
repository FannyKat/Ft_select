/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:30:27 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/03 17:00:02 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

static int	check_next(t_args *current)
{
	t_args	*tmp;

	tmp = NULL;
	if (current->next)
		tmp = current->next;
	while (tmp)
	{
		if (tmp->choice == TRUE)
		{
			free(tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	free(tmp);
	return (0);
}

static void	return_select(t_select *select)
{
	t_args	*current;

	current = NULL;
	current = select->args;
	xtputs(select->termcap->cl, 1, my_outc);
	while (current)
	{
		if (current->choice == TRUE)
		{
			ft_putstr_fd(current->arg, select->fd);
			if (check_next(current))
				write(1, " ", 1);
		}
		current = current->next;
	}
}

void		ft_select(t_select *select)
{
	init_term(select);
	xtputs(select->termcap->cl, 1, my_outc);
	xtputs(select->termcap->vi, 1, my_outc);
	catch_signals(select);
	display(select);
	while (deal_keys(select))
	{
		xtputs(select->termcap->cl, 1, my_outc);
		get_size(select->termcap);
		display(select);
	}
	reset_term(select);
	return_select(select);
}
