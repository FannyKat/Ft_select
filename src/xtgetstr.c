/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtgetstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:28:57 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/13 13:33:27 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"
#include <curses.h>

char		*xtgetstr(char *id, char **area)
{
	char	*str;

	if ((str = tgetstr(id, area)) == NULL)
		my_error("tgetstr error");
	return (str);
}
