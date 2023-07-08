#include "rush02.h"

void verify_number(int argc, char *argv[], char **dictionary, char **str_nb)
{
	if(argc == 2)
	{
		*str_nb = argv[1];
		*dictionary = ft_strdup("numbers.dict");
	}
	if (argc == 3)
	{
		*str_nb = argv[2];
		*dictionary = argv[1];
	}
	(void)dictionary;
}

//para tirar espaço em branco

static int    ft_char_in_set(char c, char const *set)
{
	int    i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
	char    *str;
	int        i;
	int        start;
	int        end;

	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

char    *ft_epur_str(char *content)
{
	char    *new_content;
	int        i;
	int        j;
	int        flag;

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
	char *str_aux_trim = ft_strtrim(new_content, " ");
	free(new_content);
	return (str_aux_trim);
}


//fim para tirar espaço em bracno

//testar leek depois
// char* trim(char* str) {
//     int len = strlen(str);
//     int start = 0;
//     int end = len - 1;

//     while (start < len && str[start] == ' ')
//         start++;

//     while (end >= 0 && str[end] == ' ')
//         end--;

//     str[end + 1] = '\0';
//     return str + start;
// }

void	ft_lstadd_front(t_dictionary **lst, t_dictionary *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

void    ft_lstadd_back(t_dictionary **lst, t_dictionary *new)
{
	t_dictionary    *first;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		first = *lst;
		while (first->next != NULL)
			first = first->next;
		first->next = new;
		new->next = NULL;
	}
}


void create_dictionary(char** dictionary_line, t_dictionary **head) {
  
	t_dictionary* entry = (t_dictionary*)malloc(sizeof(t_dictionary));
	
	char *str_aux_epur = ft_epur_str(dictionary_line[0]);

	entry->nb = ft_atoi(str_aux_epur);
	

	char *str_aux_epur1 = ft_epur_str(dictionary_line[1]);
	
	entry->str_number = ft_strtrim(str_aux_epur1, "\n");
	
	entry->next = NULL;

	free(dictionary_line[0]);
	free(dictionary_line[1]);  
	free(str_aux_epur);   
	free(str_aux_epur1); 

	ft_lstadd_front(head, entry);
}


void bubble_sort(t_dictionary *head) {
	int swapped = 1;
	t_dictionary* lptr = NULL;
	int temp_nb;
	char* temp_str;

	if (head == NULL)
		return;

	while (swapped) {
		swapped = 0;
		t_dictionary* current = head;

		while (current->next != lptr) {
			if (current->nb > current->next->nb)
			{
				// Trocar os valores dos nós
				temp_nb = current->nb;

				current->nb = current->next->nb;
				current->next->nb = temp_nb;

				temp_str = current->str_number;

				current->str_number = current->next->str_number;
				current->next->str_number = temp_str;

				swapped = 1;
			}

			current = current->next;
		}
		lptr = current;
	}
}

void print_hundred(char number, t_dictionary* dictionary)
{
	t_dictionary* current;

	current = dictionary;
	char *str_aux = charToString(number);
	while (current != NULL) {
		if(ft_atoi(str_aux) == current->nb){
			printf("%s ", current->str_number);
			break;
		}
		current = current->next;
	}
	free(str_aux);
	current = dictionary;
	while (current != NULL) {
		if((1 * 100) == current->nb){
			printf("%s ", current->str_number);
			break;
		}
		current = current->next;
	}
}

void print_number(int number, t_dictionary* dictionary)
{
	t_dictionary* current;

	current = dictionary;
	while (current != NULL) {
		if(number == current->nb){
			printf("%s ", current->str_number);
			break;
		}
		current = current->next;
	}
}

void print_100(char* number, t_dictionary* dictionary)
{
	int nb;
	char *str_aux;

	nb = ft_atoi(number);
	if(nb == 0)
		return;
	if(nb > 99)
	{
		print_hundred(number[0], dictionary);
		str_aux = charToString(number[0]);
		nb = nb - (ft_atoi(str_aux) * 100);
		free(str_aux);
	}
	if(nb == 0)
		return;
	if(nb >= 20)
	{
		str_aux = charToString(number[1]);
		print_number(ft_atoi(str_aux) * 10, dictionary);
		free(str_aux);
		if((nb % 10) != 0){
			str_aux = charToString(number[2]);
			print_number(ft_atoi(str_aux), dictionary);
			free(str_aux);
		}
	}
	if(nb < 20)
	{
		print_number(nb, dictionary);
	}
}

void print_sufix(int nb, t_dictionary* dictionary)
{
	int number;
	t_dictionary* current;

	number = 0;
	if(nb == 4)
		number = 1000000000;
	if(nb == 3)
		number = 1000000;
	if(nb == 2)
		number = 1000;
	if(number != 0)
	{
		current = dictionary;
		while (current != NULL) {
			if(number == current->nb){
				printf("%s ", current->str_number);
				break;
			}
			current = current->next;
		}
	}
}

//teste de impressão
void print_dictionary(t_dictionary* number, t_dictionary* dictionary) {
	t_dictionary* current = number;

	while (current != NULL) {
		print_100(current->str_number, dictionary);
		if(atoi(current->str_number) != 0)
			print_sufix(current->nb, dictionary);
		current = current->next;
	}
	printf("\n");
}

char* charToString(char c) {
	char*	str;
	
	str = malloc(2 * sizeof(char));
	str[0] = c;
	str[1] = '\0';
	return str;
}


