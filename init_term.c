/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 09:34:28 by fcatusse          #+#    #+#             */
/*   Updated: 2019/04/30 10:18:53 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			my_outc(int c)
{
	write(0, &c, 1);
	return (0);
}

void				init_term()
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		my_error("TCGETATTR error");
	if (ioctl(0, TCGETS, &term) < 0)
		my_error("TCGETS error");
	term.c_lflag &= ~(ICANON|ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (ioctl(0, TCSETS, &term) < 0)
		my_error("TCSETS error");
}
