/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 10:36:44 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/03 17:03:09 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

t_select	*g_select;

static void		sigstp(int sig)
{
	(void)sig;
	return ;
}

static void		sigint(int sig)
{
	(void)sig;
	free_select(g_select);
	xtputs(g_select->termcap->ve, 1, my_outc);
	exit(EXIT_SUCCESS);
}

static void		sigwinch(int sig)
{
	(void)sig;
	xtputs(g_select->termcap->ve, 1, my_outc);
	get_size(g_select->termcap);
	display(g_select);
}

void			catch_signals(t_select *select)
{
	g_select = select;
	if (signal(SIGTSTP, sigstp) == SIG_ERR || signal(SIGINT, sigint) == SIG_ERR
			|| signal(SIGWINCH, sigwinch) == SIG_ERR)
		ft_putstr_fd("signal error\n", 2);
}
