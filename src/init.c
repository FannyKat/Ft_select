/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 09:52:18 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/08 14:15:51 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

int			total_len(t_select *select)
{
	t_args	*tmp;
	int		total_len;

	total_len = 0;
	tmp = select->args;
	while (tmp->next)
	{
		total_len += ft_strlen(tmp->arg);
		tmp = tmp->next;
	}
	return (total_len);
}

void				get_caps(t_term *caps, char *term)
{
	char			bp[1024];

	if (tgetent(bp, term) != 1)
		my_error("getent error");
	caps->cm = tgetstr("cm", NULL);
	caps->cl = tgetstr("cl", NULL);
	caps->ve = tgetstr("ve", NULL);
	caps->vi = tgetstr("vi", NULL);
	caps->se = tgetstr("se", NULL);
	caps->so = tgetstr("so", NULL);
	caps->ue = tgetstr("ue", NULL);
	caps->us = tgetstr("us", NULL);
	caps->te = tgetstr("te", NULL);
	caps->ti = tgetstr("ti", NULL);
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
