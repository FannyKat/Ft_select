/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:36:29 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/03 16:57:42 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/libft.h"
# include <termcap.h>
# include <signal.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <fcntl.h>
# include <term.h>
# include <curses.h>

# define TRUE 1
# define FALSE 0

typedef	struct		s_term
{
	char		*cm;
	char		*cl;
	char		*dl;
	char		*kb;
	char		*kl;
	char		*kr;
	char		*ve;
	char		*vi;
	char		*sc;
	char		*se;
	char		*so;
	char		*ue;
	char		*us;
	char		*te;
	char		*ti;
	int		col;
	int		li;
}			t_term;

typedef	struct		s_args
{
	struct s_args	*next;
	struct s_args	*prev;
	char		*arg;
	char		*stock;
	int		choice;
}			t_args;

typedef struct		s_select
{
	struct s_term	*termcap;
	struct s_select	*next;
	struct s_args	*args;
	struct s_args	*pos;
	struct s_args	*pre_arg;
	struct s_args	*head;
	int		fd;
}					t_select;

void				init(t_select **select);
void				stock_arg(t_select *select, char **av, int ac);
void				my_error(char *str);
void				init_term(t_select *select);
void				reset_term(t_select *select);
void				ft_select(t_select *select);
int					my_outc(int c);
int					deal_keys(t_select *select);
void				arrow_keys(t_select *select, char *buff);
char				*check_arrow(char *buff);
void				get_size(t_term *term);
void				display(t_select *select);
void				my_signal(t_select *select);
void				xtputs(char *str, int i, int (*f)(int));
void				free_select(t_select *select);
void				catch_signals(t_select *select);

#endif
