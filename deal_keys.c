/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:35:05 by fcatusse          #+#    #+#             */
/*   Updated: 2019/04/30 11:43:53 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char		*check_arrow(char *buff)
{
	char	*arrow;

	arrow = buff;
	if (ft_strlen(buff) >= 3 && buff[0] == 27)
	{
		if (buff[1] == '[')
		{
			if (buff[2] == 'D')
				arrow = ft_strdup("kr");
			else if (buff[2] == 'C')
				arrow = ft_strdup("kl");
		}
		return (arrow);
	}
	return (buff);
}

int		esc_key(t_select *select, char *buff)
{
	if (buff[0] == 27)
	{
		free(buff);
		tputs(select->termcap->ve, 1, my_outc);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int		enter_key(char *buff)
{
	if (buff[0] == '\n')
		return (1);
	return (0);
}

void		space_key(t_select *select, char *buff)
{
	if (buff[0] == ' ')
	{
		select->pos->choice = TRUE;
		if (select->pos->next)
			select->pos = select->pos->next;
		else
			select->pos = select->args;
	}
}

int		deal_keys(t_select *select)
{
	char	*buff;

	buff = ft_strnew(sizeof(*buff) * 3);
	read(0, buff, 3);
	buff = check_arrow(buff);
	arrow_keys(select, buff);
	space_key(select, buff);
	esc_key(select, buff);
	if (enter_key(buff))
		return (0);
		puts("ok");
	return (1);
}
