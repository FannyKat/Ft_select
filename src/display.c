/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:47:18 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/06 20:14:26 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

static int		display_keys(t_select *select, int y)
{
	if (select->termcap->col < 53)
		return (y);
	ft_putstr_fd("\033[1;35m", 0);
	ft_putstr_fd("\t ___________________________________________\n", 0);
	ft_putstr_fd("\t|                                           |\n", 0);
	ft_putstr_fd("\t|  LEFT/RIGHT ARROWS KEY : MOVE THE CURSOR. |\n", 0);
	ft_putstr_fd("\t|   DELETE/BACKSPACE KEY : DELETE ARGUMENT. |\n", 0);
	ft_putstr_fd("\t|        SPACE KEY       : SELECT ARGUMENT. |\n", 0);
	ft_putstr_fd("\t|        ENTER KEY       : RETURN ARGUMENT. |\n", 0);
	ft_putstr_fd("\t|       ESCAPE KEY       :  QUIT PROGRAM.   |\n", 0);
	ft_putstr_fd("\t|___________________________________________|\n\n", 0);
	ft_putstr_fd("\033[0m", 0);
	return (10);
}

void			set_colors(char *path)
{
	struct stat	buf;

	lstat(path, &buf);
	if (S_ISREG(buf.st_mode) && (buf.st_mode & S_IXUSR
		|| buf.st_mode & S_IXGRP || buf.st_mode & S_IXOTH))
		ft_putstr_fd("\033[31m", 0);
	else if (S_ISDIR(buf.st_mode) && !S_ISLNK(buf.st_mode))
		ft_putstr_fd("\033[36m", 0);
	else if (S_ISLNK(buf.st_mode))
		ft_putstr_fd("\033[35m", 0);
	else if (S_ISSOCK(buf.st_mode))
		ft_putstr_fd("\033[32m", 0);
	else if (S_ISCHR(buf.st_mode) || S_ISFIFO(buf.st_mode))
		ft_putstr_fd("\033[33m", 0);
	else
		ft_putstr_fd("\033[1;34m", 0);
}

static void		set_column(t_select *select, t_args *current)
{
	select->nb_col = select->termcap->col / select->max_len;

	if (select->max_len == 0)
		return ;
	if ((current->index) % select->nb_col == 0)
		current->column = TRUE;
	else
		current->column = FALSE;
}

static void		reverse_video(t_select *select, t_args *current)
{
	set_colors(current->arg);
	if (current == select->pos)
	{
		xtputs(select->termcap->us, 1, my_outc);
		ft_putstr_fd(current->arg, 0);
		xtputs(select->termcap->ue, 1, my_outc);
	}
	else if (current->choice == TRUE)
	{
		xtputs(select->termcap->so, 1, my_outc);
		ft_putstr_fd(current->arg, 0);
		xtputs(select->termcap->se, 1, my_outc);
	}
	else
		ft_putstr_fd(current->arg, 0);
	ft_putstr_fd("\033[0m", 0);
	set_column(select, current);
}

void			display(t_select *select)
{
	int			x;
	int			y;
	int			len;
	t_args		*current;

	x = 0;
	y = 0;
	len = 0;
	current = select->args;
	y = display_keys(select, y);
	while (current)
	{
		len = ft_strlen(current->arg);
		xtputs(tgoto(select->termcap->cm, x, y), 1, my_outc);
		reverse_video(select, current);
		if (current->column == TRUE)
		{
			x = 0;
			y += 1;
		}
		else
			x += select->max_len + 1;
		current = current->next;
	}
}
