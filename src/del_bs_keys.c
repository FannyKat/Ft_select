/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_bs_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:26:45 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/07 10:28:46 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

t_select	*move_pos(t_select *select)
{
	t_args	*tmp_next;
	t_args	*tmp_prev;

	tmp_next = select->pos->next;
	tmp_prev = select->pos->prev;
	free(select->pos);
	if (tmp_prev)
		tmp_prev->next = tmp_next;
	else
	{
		select->pos = tmp_next;
		select->args = tmp_next;
	}
	if (tmp_next)
	{
		tmp_next->prev = tmp_prev;
		select->pos = tmp_next;
	}
	else
		select->pos = tmp_prev;
	return (select);
}

void		del_bs_keys(t_select *select, char *buff)
{
	if (buff[0] == 127 || buff[1] == 91)
	{
		select->pos->choice = FALSE;
		select = move_pos(select);
		if (!select->pos)
		{
			reset_term(select);
			exit(EXIT_SUCCESS);
		}
	}
}
