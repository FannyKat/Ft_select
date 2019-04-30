/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:30:27 by fcatusse          #+#    #+#             */
/*   Updated: 2019/04/30 11:37:55 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_select(t_select *select)
{
	init_term();
	tputs(select->termcap->cl, 1, my_outc);
	tputs(select->termcap->vi, 1, my_outc);
	//signals
	//display_args
	while (deal_keys(select))
	{
		tputs(select->termcap->cl, 1, my_outc);	
		get_size(select->termcap);
	}
}
