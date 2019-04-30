/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:35:05 by fcatusse          #+#    #+#             */
/*   Updated: 2019/04/30 11:43:53 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		deal_keys(t_select *select)
{
	char	*buff;

	buff = ft_strnew(sizeof(*buff) * 5);
	read(0, buff, 5);
	//check_arrow(select, buff);
	return (1);
}
