/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:35:05 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/03 15:04:26 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

int			esc_key(t_select *select, char *buff)
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
		if (select->pos->next)
			select->pos = select->pos->next;
		else
			select->pos = select->args;
	}
	free(current);
}

void		delete_keys(t_select *select, char *buff)
{
	t_args	*tmp_next;
	t_args	*tmp_prev;

	if (buff[0] == 127 || buff[1] == 91)
	{
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
		if (!select->pos)
			exit(EXIT_SUCCESS);
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
	delete_keys(select, buff);
	esc_key(select, buff);
	if (enter_key(buff))
	{
		ft_strdel(&buff);
		return (0);
	}
	return (1);
}
