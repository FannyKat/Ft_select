#include "ft_select.h"

void		get_caps(t_term *caps, char *term)
{
	char	bp[1024];
	char	area[2048];

	if (tgetent(bp, term) != 1)
		my_error("getent error");
	caps->cm = tgetstr("cm", (char**)&area);
}

void		get_size(t_term *term)
{
	struct winsize	size;

	if (ioctl(0, TIOCGWINSZ, &size) < 0)
		my_error("ioctl error");
	term->col = size.ws_col;
	term->li = size.ws_col;
}

t_term		*init_termcaps()
{
	t_term	*termcaps;
	char	*term;

	termcaps = ft_memalloc(sizeof(*termcaps));
	if (!(term = getenv("TERM")))
		my_error("getenv error");
	get_caps(termcaps, term);
	get_size(termcaps);
	return (termcaps);
}

void	init(t_select **select, int ac, char **av)
{
	*select = ft_memalloc(sizeof(**select));
	(*select)->termcap = init_termcaps();
}
