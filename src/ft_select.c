/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:30:27 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/02 14:36:45 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

static void	return_select(t_select *select)
{
	t_args	*current;

	current = select->args;
	xtputs(select->termcap->cl, 1, my_outc);
	while (current)
	{
		if (current->choice == TRUE)
		{
			ft_putstr(current->arg);
			write(1, " ", 1);
		}
		current = current->next;
	}
}

void		ft_select(t_select *select)
{
	init_term();
	xtputs(select->termcap->cl, 1, my_outc);
	xtputs(select->termcap->vi, 1, my_outc);
	display(select);
	while (deal_keys(select))
	{
		xtputs(select->termcap->cl, 1, my_outc);	
		get_size(select->termcap);
		display(select);
	}
	return_select(select);
}
