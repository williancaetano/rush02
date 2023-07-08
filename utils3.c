#include "rush02.h"

void	print_dictionary(t_dictionary *number, t_dictionary *dictionary)
{
	t_dictionary	*current;

	current = number;
	while (current != NULL)
	{
		print_100_i(current->str_number, dictionary);
		if (ft_atoi(current->str_number) != 0)
			print_sufix(current->nb, dictionary);
		current = current->next;
	}
	write(1, "\n", 1);
}
