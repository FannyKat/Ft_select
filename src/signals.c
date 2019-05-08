/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 10:36:44 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/08 18:56:11 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

t_select	*g_select;

static void		stop_signal(int sig)
{
	int			i;

	i = 0;
	(void)sig;
	reset_term(g_select);
	while (i != SIGCONT && i < 32)
		signal(i++, SIG_DFL);
	ioctl(0, TIOCSTI, "\x1A");
}

static void		continue_signal(int sig)
{
	(void)sig;
	init_term(g_select);
	xtputs(g_select->termcap->vi, 0, my_outc);
	xtputs(g_select->termcap->cl, 0, my_outc);
	signal(SIGTSTP, stop_signal);
	display(g_select);
}

static void		exit_signal(int sig)
{
	(void)sig;
	reset_term(g_select);
	xtputs(g_select->termcap->cl, 0, my_outc);
	xtputs(g_select->termcap->ve, 1, my_outc);
	free_select(g_select);
	exit(EXIT_SUCCESS);
}

static void		winch_signal(int sig)
{
	(void)sig;
	xtputs(g_select->termcap->ve, 1, my_outc);
	xtputs(g_select->termcap->cl, 1, my_outc);
	get_size(g_select->termcap);
	if (g_select->termcap->col <= g_select->max_len)
		ft_putstr_fd("Bad Window Size\n", 0);
	else
		display(g_select);
}

void			my_signals(t_select *select)
{
	int			i;

	g_select = select;
	i = 0;
	while (++i < 32)
	{
		if (i == SIGTSTP)
			xsignal(SIGTSTP, stop_signal);
		else if (i == SIGINT)
			xsignal(SIGINT, exit_signal);
		else if (i == SIGWINCH)
			xsignal(SIGWINCH, winch_signal);
		else if (i == SIGQUIT)
			xsignal(SIGQUIT, exit_signal);
		else if (i == SIGCONT)
			xsignal(SIGCONT, continue_signal);
	}
}
