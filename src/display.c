/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:47:18 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/13 16:21:37 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"
#include <sys/stat.h>

static int		display_keys(t_select *select, int y)
{
	int			fd;

	fd = select->fd;
	if (select->termcap->col < 53 || select->termcap->li < select->nb_li + 10)
		return (y);
	ft_putstr_fd("\033[1;35m", fd);
	ft_putstr_fd("\n\t ___________________________________________ \n", fd);
	ft_putstr_fd("\t|                                           |\n", fd);
	ft_putstr_fd("\t|       ARROW KEYS       : MOVE THE CURSOR. |\n", fd);
	ft_putstr_fd("\t|  DELETE/BACKSPACE KEYS : DELETE ARGUMENT. |\n", fd);
	ft_putstr_fd("\t|        SPACE KEY       : SELECT ARGUMENT. |\n", fd);
	ft_putstr_fd("\t|        ENTER KEY       : RETURN ARGUMENT. |\n", fd);
	ft_putstr_fd("\t|       ESCAPE KEY       :  QUIT PROGRAM.   |\n", fd);
	ft_putstr_fd("\t|___________________________________________|\n\n", fd);
	ft_putstr_fd("\033[0m", fd);
	return (10);
}

void			set_colors(char *path, t_select *term)
{
	struct stat	buf;

	if (lstat(path, &buf) < 0)
	{
		ft_putstr_fd("\033[1;34m", term->fd);
		return ;
	}
	if (S_ISREG(buf.st_mode) && (buf.st_mode & S_IXUSR
				|| buf.st_mode & S_IXGRP || buf.st_mode & S_IXOTH))
		ft_putstr_fd("\033[31m", term->fd);
	else if (S_ISDIR(buf.st_mode) && !S_ISLNK(buf.st_mode))
		ft_putstr_fd("\033[36m", term->fd);
	else if (S_ISLNK(buf.st_mode))
		ft_putstr_fd("\033[35m", term->fd);
	else if (S_ISSOCK(buf.st_mode) || S_ISBLK(buf.st_mode))
		ft_putstr_fd("\033[32m", term->fd);
	else if (S_ISCHR(buf.st_mode) || S_ISFIFO(buf.st_mode))
		ft_putstr_fd("\033[33m", term->fd);
	else
		ft_putstr_fd("\033[1;34m", term->fd);
}

void			set_column(t_select *select)
{
	if (select->max_len != 0)
		select->nb_col = select->termcap->col / select->max_len;
	if (select->nb_col > select->ac)
		select->nb_col = 0;
	if (select->nb_col != 0)
		select->nb_li = select->ac / select->nb_col;
	else if (select->nb_li == 0)
		select->nb_li = 1;
}

static void		reverse_video(t_select *select, t_args *current)
{
	set_colors(current->arg, select);
	if (current == select->pos)
	{
		(current->choice == TRUE) ? xtputs(select->termcap->so, 1, my_outc) : 0;
		xtputs(select->termcap->us, 1, my_outc);
		ft_putstr_fd(current->arg, select->fd);
		xtputs(select->termcap->ue, 1, my_outc);
		(current->choice == TRUE) ? xtputs(select->termcap->se, 1, my_outc) : 0;
	}
	else if (current->choice == TRUE)
	{
		xtputs(select->termcap->so, 1, my_outc);
		ft_putstr_fd(current->arg, select->fd);
		xtputs(select->termcap->se, 1, my_outc);
	}
	else
		ft_putstr_fd(current->arg, select->fd);
	ft_putstr_fd("\033[0m", select->fd);
	set_column(select);
}

void			display(t_select *select)
{
	int			x;
	int			y;
	int			i;
	t_args		*current;

	x = 0;
	y = 0;
	i = 0;
	current = select->args;
	y = display_keys(select, y);
	while (current)
	{
		i++;
		xtputs(tgoto(select->termcap->cm, x, y), 1, my_outc);
		reverse_video(select, current);
		if (i == select->nb_col)
		{
			x = 0;
			y += 1;
			i = 0;
		}
		else
			x += select->max_len + 1;
		current = current->next;
	}
}
