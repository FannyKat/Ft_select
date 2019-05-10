/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:36:29 by fcatusse          #+#    #+#             */
/*   Updated: 2019/05/09 17:00:41 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/libft.h"
# include <termcap.h>
# include <termios.h>
# include <term.h>

# define TRUE 1
# define FALSE 0

typedef	struct		s_term
{
	char			*cm;
	char			*cl;
	char			*ve;
	char			*vi;
	char			*se;
	char			*so;
	char			*ue;
	char			*us;
	char			*te;
	char			*ti;
	int				col;
	int				li;
}					t_term;

typedef	struct		s_args
{
	char			*arg;
	char			*stock;
	int				choice;
	int				index;
	struct s_args	*next;
	struct s_args	*prev;
}					t_args;

typedef struct		s_select
{
	struct s_term	*termcap;
	struct termios	old_t;
	struct termios	new_t;
	struct s_select	*next;
	struct s_args	*args;
	struct s_args	*pos;
	struct s_args	*last_arg;
	struct s_args	*head;
	int				max_len;
	int				nb_col;
	int				nb_li;
	int				ac;
	int				fd;
	int				ret;
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
void				del_bs_keys(t_select *select, char *buff);
char				*check_arrow(char *buff);
void				get_size(t_term *term);
void				display(t_select *select);
void				xtputs(char *str, int i, int (*f)(int));
void				free_select(t_select *select);
void				my_signals(t_select *select);
void				xsignal(int sig, void (*f)(int));
void				set_colors(char *path, t_select *term);
int					total_len(t_select *select);
void				return_select(t_select *select);

#endif
