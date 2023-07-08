#include "rush02.h"

void	print_100_i(char *number, t_dictionary *dictionary)
{
	int		nb;
	char	*str_aux;

	str_aux = NULL;
	nb = ft_atoi(number);
	if (nb == 0)
		return ;
	print_100(number, dictionary, nb, str_aux);
}
