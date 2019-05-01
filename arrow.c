/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:38:21 by fcatusse          #+#    #+#             */
/*   Updated: 2019/04/30 11:46:21 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		arrow_keys(t_select *select, char *buff)
{
	if (!ft_strcmp(buff, select->termcap->kr))
	{
		if (select->pos->next)
			select->pos = select->pos->next;
		else
			select->pos = select->args;
	}
	else if (!ft_strcmp(buff, select->termcap->kl))
	{
		if (select->pos->prev)
			select->pos = select->pos->prev;
	}
}
