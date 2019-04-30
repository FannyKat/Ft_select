/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:09:07 by fcatusse          #+#    #+#             */
/*   Updated: 2019/04/30 14:45:52 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_args		*add_elem(char *av)
{
	t_args			*new;

	new = NULL;
	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->arg = av;
	return (new);
}

void				stock_arg(t_select *select, char **av, int ac)
{
	int				i;
	t_select		*head;
	t_args			*new;

	head = select;
	i = 0;
	new = NULL;
	while (++i < ac)
	{
		new = add_elem(av[i]);
		printf("%s\n", new->arg);
	}
	new->next = NULL;
	select = head;
}
