/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_reset_term.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:11:41 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/06 11:21:08 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

int					my_outc(int c)
{
	write(0, &c, 1);
	return (0);
}

void				reset_term(t_select *select)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		my_error("TCGETATTR error");
	term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, TCSANOW, &term) == -1)
		my_error("TCSETATTR error");
	xtputs(select->termcap->cl, 1, my_outc);
	xtputs(select->termcap->ve, 1, my_outc);
}

void				init_term(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		my_error("TCGETATTR error");
	if (ioctl(0, TIOCGETA, &term) < 0)
		my_error("TCGETS error");
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (ioctl(0, TIOCSETA, &term) < 0)
		my_error("TCSETS error");
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		my_error("TCSETATTR error");
}
