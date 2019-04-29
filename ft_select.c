#include "ft_select.h"

void		ft_select(t_select *select)
{
	init_term();
	tputs(select->termcap->cl, 1, my_outc);
	tputs(select->termcap->vi, 1, my_outc);
	//signals
	//display_args
	while (deal_keys(select))
	{
		tputs(select->termcap->cl, 1, my_outc);	
		get_size(select->termcap);
	}
}
