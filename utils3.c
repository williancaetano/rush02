#include "rush02.h"

void	print_dictionary(t_dictionary *number, t_dictionary *dictionary)
{
	t_dictionary	*current;
	extern char		*g_print_str;
	char			*str_aux;

	current = number;
	while (current != NULL)
	{
		print_100_i(current->str_number, dictionary);
		if (ft_atoi(current->str_number) != 0)
			print_sufix(current->nb, dictionary);
		current = current->next;
	}
	str_aux = ft_strtrim(g_print_str, " ");
	ft_put_str(str_aux);
	write(1, "\n", 1);
	free(g_print_str);
	free(str_aux);
}
