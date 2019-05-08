/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:35:05 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/08 16:29:01 by fcatusse         ###   ########.fr       */
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
	if (buff[0] == ' ')
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
	read(0, buff, 5);
	buff = check_arrow(buff);
	arrow_keys(select, buff);
	space_key(select, buff);
	del_bs_keys(select, buff);
	esc_key(select, buff);
	if (enter_key(buff))
		return (0);
	ft_strdel(&buff);
	return (1);
}
