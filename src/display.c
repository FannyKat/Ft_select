/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:47:18 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/02 14:33:52 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

static void		reverse_video(t_select *select, t_args *current)
{
	if (current == select->pos)
	{
		ft_putstr_fd("\033[38;5;141m", 0);
		xtputs(select->termcap->us, 1, my_outc);
		ft_putstr_fd(current->arg, 0);
		ft_putstr_fd("\033[35m", 0);
		xtputs(select->termcap->ue, 1, my_outc);
	}
	else if (current->choice == TRUE)
	{
		xtputs(select->termcap->so, 1, my_outc);
		ft_putstr_fd(current->arg, 0);
		xtputs(select->termcap->se, 1, my_outc);
	}
	else
		ft_putstr_fd(current->arg, 0);
}

void			display(t_select *select)
{
	int			x;
	int			y;
	int			len;
	t_args		*current;

	x = 0;
	y = 0;
	len = 0;
	current = select->args;
	while (current)
	{
		len = ft_strlen(current->arg);
		xtputs(tgoto(select->termcap->cm, x, y), 1, my_outc);
		reverse_video(select, current);
		x += len + 2;
		current = current->next;
	}
}
