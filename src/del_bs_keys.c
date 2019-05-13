/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_bs_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:26:45 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/13 17:11:57 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

static void	move_index(t_select *select)
{
	t_args	*tmp;
	int		ac;
	int		i;

	i = 1;
	tmp = select->args;
	ac = select->ac;
	while (ac--)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

t_select	*move_pos(t_select *select)
{
	t_args	*tmp_next;
	t_args	*tmp_prev;

	tmp_next = select->pos->next;
	tmp_prev = select->pos->prev;
	if (select->pos == select->last_arg)
		tmp_prev ? select->last_arg = tmp_prev : 0;
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
	select->ac -= 1;
	move_index(select);
	return (select);
}

void		del_bs_keys(t_select *select, char *buff)
{
	if ((buff[0] == 127 || buff[2] == 51) && !bad_window_size(select))
	{
		select->pos->choice = FALSE;
		select = move_pos(select);
		if (!select->pos)
		{
			reset_term(select);
			exit(EXIT_SUCCESS);
		}
		else
			select->max_len = get_max_len(select);
	}
}
