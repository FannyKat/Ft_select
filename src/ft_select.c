/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:30:27 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/07 19:51:40 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

int			get_max_len(t_select *select)
{
	t_args	*tmp;
	int		len;

	tmp = select->args;
	len = ft_strlen(tmp->arg);
	while (tmp->next)
	{
		if (len < (int)ft_strlen(tmp->arg))
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
			set_colors(current->arg);
			ft_putstr(current->arg);
			if (check_next(current))
				write(1, " ", 1);
		}
		current = current->next;
	}
	ft_putstr("\n");
}

void		ft_select(t_select *select)
{
	init_term(select);
	xtputs(select->termcap->cl, 1, my_outc);
	xtputs(select->termcap->vi, 1, my_outc);
	select->max_len = get_max_len(select);
	my_signals(select);
	display(select);
	while (deal_keys(select))
	{
		xtputs(select->termcap->cl, 1, my_outc);
		get_size(select->termcap);
		display(select);
	}
	xtputs(select->termcap->ve, 1, my_outc);
	return_select(select);
}
