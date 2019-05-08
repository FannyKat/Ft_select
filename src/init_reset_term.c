/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_reset_term.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:11:41 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/08 14:22:35 by fcatusse         ###   ########.fr       */
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
	if (tcgetattr(0, &select->data) == -1)
		my_error("TCGETATTR error");
	select->data.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, TCSANOW, &select->data) == -1)
		my_error("TCSETATTR error");
	if (select->ret == FALSE)	
		xtputs(select->termcap->cl, 1, my_outc);
	xtputs(select->termcap->ve, 1, my_outc);
}

void				init_term(t_select *select)
{
	if (tcgetattr(0, &select->data) == -1)
		my_error("TCGETATTR error");
	if (ioctl(0, TIOCGETA, &select->data) < 0)
		my_error("TCGETS error");
	select->data.c_lflag &= ~(ICANON | ECHO);
	select->data.c_cc[VMIN] = 1;
	select->data.c_cc[VTIME] = 0;
	if (!(select->fd = open(ttyname(0), O_RDWR)))
		my_error("Bad fd");
	if (ioctl(0, TIOCSETA, &select->data) < 0)
		my_error("TCSETS error");
	if (tcsetattr(0, TCSADRAIN, &select->data) == -1)
		my_error("TCSETATTR error");
}
