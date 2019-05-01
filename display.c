/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:47:18 by fcatusse          #+#    #+#             */
/*   Updated: 2019/04/30 14:35:47 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		reverse_video(t_select *select, t_args *current)
{
	if (current == select->pos)
	{
		ft_putstr("\033[38;5;141m");
		tputs(select->termcap->us, 1, my_outc);
		ft_putstr(current->arg);
		ft_putstr("\033[35m");
		tputs(select->termcap->ue, 1, my_outc);
	}
	else if (current->choice == TRUE)
	{	
		tputs(select->termcap->so, 1, my_outc);
		ft_putstr(current->arg);
		tputs(select->termcap->se, 1, my_outc);
	}
	else
		ft_putstr(current->arg);
}

void			display(t_select *select)
{
	int			x;
	int			y;
	int		len;
	t_args			*current;

	x = 0;
	y = 0;
	len = 0;
	current = select->args;
	while (current)
	{
		len = ft_strlen(current->arg);
		tputs(tgoto(select->termcap->cm, x, y), 1, my_outc);
		reverse_video(select, current);
		x += len + 2;
		current = current->next;
	}
}
