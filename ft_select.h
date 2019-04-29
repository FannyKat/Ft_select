# ifndef FT_SELECT_H
#define FT_SELECT_H

#include "../lib/libft.h"
#include <termios.h>
#include <sys/ioctl.h>
#include <term.h>
#include <curses.h>

typedef struct		s_term
{
	char		*cm;
	char		*cl;
	char		*vi;
	int		col;
	int		li;
}			t_term;

typedef struct		s_select
{
	struct s_term	*termcap;	
}			t_select;

void	init(t_select **select, int ac, char **av);
void	my_error(char *str);
void	init_term(void);
void	ft_select(t_select *select);
int	my_outc(int c);
int	deal_keys(t_select *select);
void	check_arrow(t_select *select, char *buff);
void	get_size(t_term *term);

#endif
