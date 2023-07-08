#include "rush02.h"

void	verify_number(int argc, char *argv[], char **dictionary, char **str_nb)
{
	if (argc == 2)
	{
		*str_nb = argv[1];
		*dictionary = ft_strdup("numbers.dict");
	}
	if (argc == 3)
	{
		*str_nb = argv[2];
		*dictionary = ft_strdup(argv[1]);
	}
	(void)dictionary;
}

char	*ft_epur_str(char *content)
{
	char	*new_content;
	int		i;
	int		j;
	int		flag;
	char	*str_aux_trim;

	i = 0;
	j = 0;
	flag = 0;
	while (content[i] == ' ' || content[i] == '\t')
		i++;
	new_content = ft_calloc(sizeof(char), (ft_strlen(content) + 1));
	while (content[i])
	{
		if (content[i] == ' ' || content[i] == '\t')
			flag = 1;
		if (!(content[i] == ' ' || content[i] == '\t'))
		{
			if (flag)
				new_content[j++] = ' ';
			flag = 0;
			new_content[j++] = content[i];
		}
		i++;
	}
	str_aux_trim = ft_strtrim(new_content, " ");
	free(new_content);
	return (str_aux_trim);
}

void	create_dictionary(char **dictionary_line, t_dictionary	**head)
{
	t_dictionary	*entry;
	char			*str_aux_epur;
	char			*str_aux_epur1;

	entry = (t_dictionary *)malloc(sizeof(t_dictionary));
	str_aux_epur = ft_epur_str(dictionary_line[0]);
	entry->nb = ft_atoi(str_aux_epur);
	str_aux_epur1 = ft_epur_str(dictionary_line[1]);
	entry->str_number = ft_strtrim(str_aux_epur1, "\n");
	entry->next = NULL;
	free(dictionary_line[0]);
	free(dictionary_line[1]);
	free(str_aux_epur);
	free(str_aux_epur1);
	ft_lstadd_front(head, entry);
}

char	*char_to_string(char c)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void	reverse_string(char *str)
{
	int		length;
	int		start;
	int		end;
	char	temp;

	length = strlen(str);
	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
