/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 09:52:18 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/06 14:48:04 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void				get_caps(t_term *caps, char *term)
{
	char			bp[1024];
	char			area[2048];

	if (tgetent(bp, term) != 1)
		my_error("getent error");
	caps->cm = tgetstr("cm", (char**)&area);
	caps->cl = tgetstr("cl", (char**)&area);
	caps->ve = tgetstr("ve", (char**)&area);
	caps->vi = tgetstr("vi", (char**)&area);
	caps->se = tgetstr("se", (char**)&area);
	caps->so = tgetstr("so", (char**)&area);
	caps->ue = tgetstr("ue", (char**)&area);
	caps->us = tgetstr("us", (char**)&area);
}

void				get_size(t_term *term)
{
	struct winsize	size;

	if (ioctl(0, TIOCGWINSZ, &size) < 0)
		my_error("ioctl error");
	term->col = size.ws_col;
	term->li = size.ws_row;
}

t_term				*init_termcaps(void)
{
	t_term			*termcaps;
	char			*term;

	termcaps = ft_memalloc(sizeof(*termcaps));
	if (!(term = getenv("TERM")))
		my_error("getenv error");
	get_caps(termcaps, term);
	get_size(termcaps);
	return (termcaps);
}

void				init(t_select **select)
{
	*select = ft_memalloc(sizeof(**select));
	(*select)->termcap = init_termcaps();
}
