#include "../inc/ft_select.h"

int			my_outc(int c)
{
	write(0, &c, 1);
	return (0);
}

void			reset_term(t_select *select)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		my_error("TCGETATTR ERROR");
	term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, TCSANOW, &term) == -1)
		my_error("TCSETATTR ERROR");
	xtputs(select->termcap->cl, 1, my_outc);
	xtputs(select->termcap->ve, 0, my_outc);
	tputs(select->termcap->te, 0, my_outc);
}

void			init_term(t_select *select)
{
	struct termios	term;

	if ((select->fd = open(ttyname(0), O_RDWR)) == -1)
		my_error("bad fd");
	if (tcgetattr(0, &term) == -1)
		my_error("TCGETATTR ERROR");
	if (ioctl(0, TCGETS, &term) < 0)
		my_error("TCGETS ERROR");
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (ioctl(0, TCSETS, &term) < 0)
		my_error("TCSETS ERROR");
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		my_error("TCSADRAIN ERROR");
	tputs(select->termcap->ti, 0, my_outc);
}
