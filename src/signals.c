/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 10:36:44 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/06 20:13:16 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

t_select	*g_select;

static void		stop_signal(int sig)
{
	(void)sig;
	reset_term(g_select);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, "\x1A");
	return ;
}

static void		continue_signal(int sig)
{
	(void)sig;
	init_term();
	xtputs(g_select->termcap->vi, 1, my_outc);
	xtputs(g_select->termcap->cl, 1, my_outc);
	signal(SIGTSTP, stop_signal);
	
}


static void		exit_signal(int sig)
{
	(void)sig;
	reset_term(g_select);
	free_select(g_select);
	xtputs(g_select->termcap->ve, 1, my_outc);
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

void			catch_signals(t_select *select)
{
	g_select = select;
	if (signal(SIGTSTP, stop_signal) == SIG_ERR 
		|| signal(SIGINT, exit_signal) == SIG_ERR
		|| signal(SIGWINCH, winch_signal) == SIG_ERR
		|| signal(SIGQUIT, exit_signal) == SIG_ERR
		|| signal(SIGCONT, continue_signal) == SIG_ERR)
		ft_putstr_fd("signal error\n", 2);
}
