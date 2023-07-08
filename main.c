#include "rush02.h"

char	*g_print_str;

void	process_number(char	*str_nb, t_dictionary	**number, int i, int j)
{
	char	*str;
	int		k;
	char	*str_aux;

	str = ft_strdup("\0");
	k = 1;
	while (i >= 0)
	{
		str_aux = char_to_string(str_nb[i]);
		str = ft_strjoin(str, str_aux);
		free(str_aux);
		j++;
		if (j == 3 || i == 0)
		{
			if (j == 2)
				str = ft_strjoin(str, "0");
			create_numbers(str, k, number);
			free(str);
			str = ft_strdup("\0");
			k++;
			j = 0;
		}
		i--;
	}
	free(str);
}

void	process_number_i(char	*str_nb, t_dictionary	**number)
{
	int		i;
	int		j;

	i = ft_strlen(str_nb) - 1;
	j = 0;
	process_number(str_nb, number, i, j);
}

void	write_number(t_dictionary *dictionary, char *str_nb)
{
	t_dictionary	*number;

	if (ft_atoi(str_nb) == 0)
	{
		print_zero(dictionary);
		free_dictionary(dictionary);
		exit(1);
	}
	number = NULL;
	process_number_i(str_nb, &number);
	print_dictionary(number, dictionary);
	free_dictionary(number);
}

int	set_dictionary(int file, t_dictionary **dictionary)
{
	char	*result;
	char	**dictionary_splited;
	int		i;

	result = "";
	i = 1;
	while (result)
	{
		result = get_next_line(file);
		if (!result)
			break ;
		if (result[0] == '\n')
		{
			free(result);
			continue ;
		}
		dictionary_splited = ft_split(result, ':');
		free(result);
		if (create_dictionary(dictionary_splited, dictionary))
			i = 0;
		free(dictionary_splited);
	}
	bubble_sort(*dictionary);
	return (i);
}

int	main(int argc, char *argv[])
{
	char			*dictionary_file;
	t_dictionary	*dictionary;
	char			*str_nb;
	int				file;

	if (verify_args(argc, argv))
		return (1);
	else
	{
		verify_number(argc, argv, &dictionary_file, &str_nb);
		file = open(dictionary_file, O_RDONLY);
		if (file > 0)
		{
			dictionary = NULL;
			if (set_dictionary(file, &dictionary))
				write_number(dictionary, str_nb);
			else
				write(1, "Dict Error\n", ft_strlen("Dict Error\n"));
			free_file_name(dictionary_file);
			free_dictionary(dictionary);
		}
		else
			write(1, "Dict Error\n", ft_strlen("Dict Error\n"));
	}
	return (0);
}
