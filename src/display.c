/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:47:18 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/03 17:01:56 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void			display_menu(t_select *select)
{
	ft_putstr_fd("\033[35m", select->fd);
	ft_putstr_fd("\t ___________________________________________\n", select->fd);
	ft_putstr_fd("\t|                                           |\n", select->fd);
	ft_putstr_fd("\t|  LEFT/RIGHT ARROWS KEY : MOVE THE CURSOR. |\n", select->fd);
	ft_putstr_fd("\t|   DELETE/BACKSPACE KEY : DELETE ARGUMENT. |\n", select->fd);
	ft_putstr_fd("\t|        SPACE KEY       : SELECT ARGUMENT. |\n", select->fd);
	ft_putstr_fd("\t|        ENTER KEY       : RETURN ARGUMENT. |\n", select->fd);
	ft_putstr_fd("\t|       ESCAPE KEY       :  QUIT PROGRAM.   |\n", select->fd);
	ft_putstr_fd("\t|___________________________________________|\n\n", select->fd);
}

static void		reverse_video(t_select *select, t_args *current)
{
	if (current == select->pos)
	{
		ft_putstr_fd("\033[38;5;141m", select->fd);
		xtputs(select->termcap->us, 1, my_outc);
		ft_putstr_fd(current->arg, select->fd);
		ft_putstr_fd("\033[35m", select->fd);
		xtputs(select->termcap->ue, 1, my_outc);
	}
	else if (current->choice == TRUE)
	{
		xtputs(select->termcap->so, 1, my_outc);
		ft_putstr_fd(current->arg, select->fd);
		xtputs(select->termcap->se, 1, my_outc);
	}
	else
		ft_putstr_fd(current->arg, select->fd);
}

void			display(t_select *select)
{
	int			x;
	int			y;
	int			len;
	t_args		*current;

	x = 0;
	y = 10;
	len = 0;
	current = select->args;
	display_menu(select);
	while (current)
	{
		len = ft_strlen(current->arg);
		xtputs(tgoto(select->termcap->cm, x, y), 1, my_outc);
		reverse_video(select, current);
		x += len + 2;
		current = current->next;
	}
}
