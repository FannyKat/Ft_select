/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:47:18 by fcatusse          #+#    #+#             */
/*   Updated: 2019/04/30 14:35:47 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			display(t_select *select)
{
	int			x;
	int			y;
	t_args		*tmp;

	x = 0;
	y = 20;
	tmp = select->args;
	while (tmp)
	{
		tputs(tgoto(select->termcap->cm, x, y), 1, my_outc);
		//reverse_video
		tmp = tmp->next;
	}
}
