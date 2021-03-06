/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 10:21:33 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/08 13:49:59 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void		free_select(t_select *select)
{
	t_args	*tmp;

	tmp = NULL;
	free(select->termcap);
	while (select->args)
	{
		tmp = select->args->next;
		free(select->args);
		select->args = tmp;
	}
	free(select);
}
