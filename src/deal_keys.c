/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:35:05 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/02 14:33:39 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

int			esc_key(t_select *select, char *buff)
{
	if (buff[0] == 27)
	{
		free(buff);
		xtputs(select->termcap->ve, 1, my_outc);
		/* Don't Forget To Free Select */
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int			enter_key(char *buff)
{
	if (buff[0] == '\n')
		return (1);
	return (0);
}

void		space_key(t_select *select, char *buff)
{
	t_args	*current;

	current = NULL;
	if (buff[0] == ' ')
	{
		select->pos->choice = TRUE;
		if (!(current = malloc(sizeof(*current))))
			return ;
	//	current->select = select->pos->arg;
		if (select->pos->next)
			select->pos = select->pos->next;
		else
			select->pos = select->args;
	}
}

int			deal_keys(t_select *select)
{
	char	*buff;

	buff = ft_strnew(sizeof(*buff) * 5);
	read(0, buff, 5);
	buff = check_arrow(buff);
	arrow_keys(select, buff);
	space_key(select, buff);
	esc_key(select, buff);
	if (enter_key(buff))
		return (0);
	return (1);
}
