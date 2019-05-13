/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:30:27 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/13 18:21:11 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

int			bad_window_size(t_select *select)
{
	set_column(select);
	if (select->termcap->li < select->nb_li + 1
			|| select->termcap->col <= select->max_len)
	{
		ft_putstr_fd("Bad Window Size", select->fd);
		return (1);
	}
	return (0);
}

size_t		get_max_len(t_select *select)
{
	t_args	*tmp;
	size_t	len;

	tmp = select->args;
	if (!tmp)
		return (0);
	len = ft_strlen(tmp->arg);
	while (tmp)
	{
		if (len < ft_strlen(tmp->arg))
			len = ft_strlen(tmp->arg);
		tmp = tmp->next;
	}
	return (len);
}

static int	check_next(t_args *current)
{
	t_args	*tmp;

	tmp = NULL;
	if (current->next)
		tmp = current->next;
	while (tmp)
	{
		if (tmp->choice == TRUE)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		return_select(t_select *select)
{
	t_args	*current;

	current = NULL;
	current = select->args;
	xtputs(select->termcap->cl, 1, my_outc);
	while (current)
	{
		if (current->choice == TRUE)
		{
			select->ret = TRUE;
			set_colors(current->arg, select);
			ft_putstr(current->arg);
			(check_next(current)) ? ft_putchar(' ') : ft_putchar('\n');
			ft_putstr_fd("\033[0m", select->fd);
		}
		current = current->next;
	}
}

void		ft_select(t_select *select)
{
	init_term(select);
	xtputs(select->termcap->cl, 1, my_outc);
	xtputs(select->termcap->vi, 1, my_outc);
	select->max_len = get_max_len(select);
	if (!select->max_len)
	{
		reset_term(select);
		my_error("ft_select: error: argument's list is empty");
	}
	my_signals(select);
	if (!bad_window_size(select))
		display(select);
	while (deal_keys(select))
	{
		xtputs(select->termcap->cl, 1, my_outc);
		get_size(select->termcap);
		if (!bad_window_size(select))
			display(select);
	}
	return_select(select);
}
