/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:36:32 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/09 16:41:20 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"
#include <curses.h>

void	xtputs(char *str, int i, int (*f)(int))
{
	if ((tputs(str, i, f) == ERR))
		my_error("tputs error");
}
