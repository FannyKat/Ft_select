/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 11:17:21 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/07 18:15:33 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

static void		move_up(t_select *select, char *buff)
{
	int			i;
	int			pos;

	pos = select->pos->index;
	i = select->nb_col + 1;
	if (!ft_strcmp(buff, "ku"))
	{
		while (--i)
		{
			if (select->pos->prev)
				select->pos = select->pos->prev;
			else
			{
				(pos == 1) ? i = 1 : i++;
				select->pos = select->last_arg;
			}
		}
	}
}

static void		move_down(t_select *select, char *buff)
{
	int			i;
	int			pos;

	pos = select->pos->index;
	i = select->nb_col + 1;
	if (!ft_strcmp(buff, "kd"))
	{
		while (--i)
		{
			if (select->pos->next)
				select->pos = select->pos->next;
			else
			{
				i = pos % select->nb_col;
				(i == 0) ? i = select->nb_col : 0;
				select->pos = select->args;
			}
		}
	}
}

void			arrow_keys(t_select *select, char *buff)
{
	if (!ft_strcmp(buff, "kr"))
	{
		if (select->pos->next)
			select->pos = select->pos->next;
		else
			select->pos = select->args;
	}
	else if (!ft_strcmp(buff, "kl"))
	{
		if (select->pos->prev)
			select->pos = select->pos->prev;
		else
			select->pos = select->last_arg;
	}
	move_up(select, buff);
	move_down(select, buff);
}

char			*check_arrow(char *buff)
{
	char		*arrow;

	arrow = buff;
	if (ft_strlen(buff) >= 3 && buff[0] == 27)
	{
		if (buff[1] == '[')
		{
			if (buff[2] == 'D')
				arrow = ft_strdup("kl");
			else if (buff[2] == 'C')
				arrow = ft_strdup("kr");
			else if (buff[2] == 'A')
				arrow = ft_strdup("ku");
			else if (buff[2] == 'B')
				arrow = ft_strdup("kd");
		}
		ft_strdel(&buff);
		return (arrow);
	}
	return (buff);
}