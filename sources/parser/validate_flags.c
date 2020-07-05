#include "parser/parser.h"

/*
*/

static void collect_flags(t_flags *flags, const char arg)
{
	if (arg == 'l')
		flags->l = true;
	if (arg == 'R')
		flags->big_r = true;
	if (arg == 'a')
		flags->a = true;
	if (arg == 'r')
		flags->little_r = true;
	if (arg == 't')
		flags->t = true;
	if (arg == '1')
		flags->one = true;
}

/*
*	\return index in user input that equals folder or error flag
*/

int		validate_flags(t_flags *flags, const char *arg)
{
	int	i;

	if (arg[0] != '-')
		return (1);
	i = 0;
	while (arg[++i])
	{
		if (arg[i] == 'R' || arg[i] == 'r' || arg[i] == 'l'
			|| arg[i] == 'a' || arg[i] == 't' || arg[i] == '1')
		{
			//ft_putchar(arg[i]);
			collect_flags(flags, arg[i]);
		}
		else
		{}////////exit here with usage
	}
	return (!arg[i] ? 1 : i);
}