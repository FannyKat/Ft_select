/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xsignal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 10:18:28 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/07 14:36:56 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"
#include <signal.h>

void	xsignal(int sig, void (*f)(int))
{
	if (signal(sig, f) == SIG_ERR)
		my_error("signal error");
}
