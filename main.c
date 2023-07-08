#include "rush02.h"

void	process_number(char	*str_nb, t_dictionary	**number)
{
	char	*str;
	int		i;
	int		j;
	int		k;
	char	*str_aux;

	str = ft_strdup("\0");
	i = ft_strlen(str_nb) - 1;
	j = 0;
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
	process_number(str_nb, &number);
	print_dictionary(number, dictionary);
	free_dictionary(number);
}

void	set_dictionary(int file, t_dictionary **dictionary)
{
	char	*result;
	char	**dictionary_splited;

	result = "";
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
		create_dictionary(dictionary_splited, dictionary);
		free(dictionary_splited);
	}
}

int	main(int argc, char *argv[])
{
	char			*dictionary_file;
	t_dictionary	*dictionary;
	char			*str_nb;
	int				file;

	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else
	{
		verify_number(argc, argv, &dictionary_file, &str_nb);
		file = open(dictionary_file, O_RDONLY);
		if (file > 0)
		{
			dictionary = NULL;
			set_dictionary(file, &dictionary);
			bubble_sort(dictionary);
			write_number(dictionary, str_nb);
			free_file_name(dictionary_file);
			free_dictionary(dictionary);
		}
	}
	return (0);
}
