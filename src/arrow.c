/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:38:21 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/02 12:49:06 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		arrow_keys(t_select *select, char *buff)
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
			select->pos = select->args;
	}
}

char		*check_arrow(char *buff)
{
	char	*arrow;

	arrow = buff;
	if (ft_strlen(buff) >= 3 && buff[0] == 27)
	{
		if (buff[1] == '[')
		{
			if (buff[2] == 'D')
				arrow = ft_strdup("kl");
			else if (buff[2] == 'C')
				arrow = ft_strdup("kr");

		}
		return (arrow);
	}
	return (buff);
}
