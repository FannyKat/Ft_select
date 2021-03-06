/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 10:36:44 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/13 18:23:17 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"
#include <sys/ioctl.h>
#include <signal.h>

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

static void		exit_signal(int sig)
{
	(void)sig;
	reset_term(g_select);
	xtputs(g_select->termcap->cl, 0, my_outc);
	xtputs(g_select->termcap->ve, 1, my_outc);
	free_select(g_select);
	if (sig == 11)
		my_error("Segmentation Fault");
	if (sig == 6 || sig == 5)
		my_error("Abort Trap");
	if (sig == 8)
		my_error("Floating-point exception");
	if (sig == 10)
		my_error("Bus error");
	exit(EXIT_SUCCESS);
}

static void		continue_signal(int sig)
{
	(void)sig;
	init_term(g_select);
	xtputs(g_select->termcap->vi, 0, my_outc);
	xtputs(g_select->termcap->cl, 0, my_outc);
	signal(SIGTSTP, stop_signal);
	signal(SIGINT, exit_signal);
	get_size(g_select->termcap);
	if (!bad_window_size(g_select))
		display(g_select);
}

static void		winch_signal(int sig)
{
	(void)sig;
	xtputs(g_select->termcap->cl, 1, my_outc);
	xtputs(g_select->termcap->ve, 1, my_outc);
	get_size(g_select->termcap);
	set_column(g_select);
	if (!bad_window_size(g_select))
		display(g_select);
	xtputs(g_select->termcap->vi, 1, my_outc);
}

void			my_signals(t_select *select)
{
	int			i;

	g_select = select;
	i = 0;
	while (++i < 32)
	{
		if (i == SIGINT || i == SIGSEGV || i == SIGQUIT || i == SIGABRT
		|| i == SIGFPE || i == SIGBUS || i == SIGTRAP)
			xsignal(i, exit_signal);
		else if (i == SIGTSTP)
			xsignal(i, stop_signal);
		else if (i == SIGWINCH)
			xsignal(i, winch_signal);
		else if (i == SIGCONT)
			xsignal(i, continue_signal);
		else
			signal(i, SIG_IGN);
	}
}
