/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:52:27 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/06 14:14:21 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

int				get_max_len(t_select *select)
{
	t_args		*tmp;
	int			len;

	len = 0;
	tmp = select->args;
	while (tmp->next)
	{
		if (len < (int)ft_strlen(tmp->arg))
			len = ft_strlen(tmp->arg);
		tmp = tmp->next;
	}
	return (len);
}

void		padding(int nb, int fd)
{
	int		i;

	i = 0;
	while (nb >= 10)
	{
		nb -= 10;
		i++;
	}
	while (i--)
		write(1, "          ", 10);
	write(fd, "          ", nb);
}


