#include "rush02.h"

void	print_hundred(char number, t_dictionary *dictionary)
{
	t_dictionary	*current;
	char			*str_aux;

	current = dictionary;
	str_aux = char_to_string(number);
	while (current != NULL)
	{
		if (ft_atoi(str_aux) == current->nb)
		{
			ft_put_str_space(current->str_number);
			break ;
		}
		current = current->next;
	}
	free(str_aux);
	current = dictionary;
	while (current != NULL)
	{
		if ((1 * 100) == current->nb)
		{
			ft_put_str_space(current->str_number);
			break ;
		}
		current = current->next;
	}
}

void	print_100(char *number, t_dictionary *dictionary)
{
	int		nb;
	char	*str_aux;

	nb = ft_atoi(number);
	if (nb == 0)
		return ;
	if (nb > 99)
	{
		print_hundred(number[0], dictionary);
		str_aux = char_to_string(number[0]);
		nb = nb - (ft_atoi(str_aux) * 100);
		free(str_aux);
	}
	if (nb == 0)
		return ;
	if (nb >= 20)
	{
		str_aux = char_to_string(number[1]);
		print_number(ft_atoi(str_aux) * 10, dictionary);
		free(str_aux);
		if ((nb % 10) != 0)
		{
			str_aux = char_to_string(number[2]);
			print_number(ft_atoi(str_aux), dictionary);
			free(str_aux);
		}
	}
	if (nb < 20)
	{
		print_number(nb, dictionary);
	}
}

void	print_number(int number, t_dictionary *dictionary)
{
	t_dictionary	*current;

	current = dictionary;
	while (current != NULL)
	{
		if (number == current->nb)
		{
			ft_put_str_space(current->str_number);
			break ;
		}
		current = current->next;
	}
}

void	print_sufix(int nb, t_dictionary *dictionary)
{
	int				number;
	t_dictionary	*current;

	number = 0;
	if (nb == 4)
		number = 1000000000;
	if (nb == 3)
		number = 1000000;
	if (nb == 2)
		number = 1000;
	if (number != 0)
	{
		current = dictionary;
		while (current != NULL)
		{
			if (number == current->nb)
			{
				ft_put_str_space(current->str_number);
				break ;
			}
			current = current->next;
		}
	}
}

void	print_zero(t_dictionary *dictionary)
{
	ft_put_str(dictionary->str_number);
	write(1, "\n", 1);
}
