/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:09:07 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/13 13:27:27 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

static t_args	*add_elem(char *av, int i)
{
	t_args		*new;

	new = NULL;
	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->arg = av;
	new->choice = FALSE;
	new->index = i;
	return (new);
}

static void		stock_ptr(t_args **head, t_args **new, t_args **prev)
{
	if (!(*head))
	{
		*head = *new;
		*prev = *new;
		(*head)->next = NULL;
		(*head)->prev = NULL;
	}
	else
	{
		(*prev)->next = *new;
		(*new)->prev = *prev;
		*prev = *new;
	}
	(*new)->next = NULL;
}

void			stock_arg(t_select *select, char **av, int ac)
{
	int			i;
	int			j;
	t_args		*head;
	t_args		*new;
	t_args		*prev;

	i = 0;
	j = 0;
	new = NULL;
	prev = NULL;
	head = NULL;
	while (++i < ac)
	{
		if (!ft_strlen(av[i]))
			j++;
		else
		{
			new = add_elem(av[i], i - j);
			stock_ptr(&head, &new, &prev);
		}
	}
	select->last_arg = new;
	select->args = head;
	select->pos = head;
	select->ac = ac - j - 1;
}
