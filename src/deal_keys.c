/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:35:05 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/13 16:59:57 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

static int		esc_key(t_select *select, char *buff)
{
	if (buff[0] == 27 && buff[1] == 0)
	{
		ft_strdel(&buff);
		reset_term(select);
		free_select(select);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

static int		enter_key(char *buff)
{
	if (buff[0] == '\n')
	{
		ft_strdel(&buff);
		return (1);
	}
	return (0);
}

static void		space_key(t_select *select, char *buff)
{
	if (buff[0] == ' ' && !bad_window_size(select))
	{
		if (select->pos->choice == FALSE)
			select->pos->choice = TRUE;
		else
			select->pos->choice = FALSE;
		if (select->pos->next)
			select->pos = select->pos->next;
		else
			select->pos = select->args;
	}
}

int				deal_keys(t_select *select)
{
	char		*buff;

	buff = ft_strnew(sizeof(*buff) * 5);
	if (read(0, buff, 5) < 0)
	{
		ft_strdel(&buff);
		my_error("Read error");
	}
	buff = check_arrow(buff, select);
	arrow_keys(select, buff);
	space_key(select, buff);
	esc_key(select, buff);
	if (enter_key(buff))
		return (0);
	del_bs_keys(select, buff);
	ft_strdel(&buff);
	return (1);
}
