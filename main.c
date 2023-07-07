//cmp gcc -o rush-02 main.c
#include "rush02.h"

void reverseString(char* str) {
	int length = strlen(str);
	int start = 0;
	int end = length - 1;

	while (start < end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

void create_numbers(char* str, int nb, t_dictionary **head) {
	t_dictionary* entry;
	
	entry = (t_dictionary*)malloc(sizeof(t_dictionary));
	entry->nb = nb;
	reverseString(str);
	entry->str_number = ft_strdup(str);
	entry->next = NULL;

	free(str);
	ft_lstadd_front(head, entry);
}

void print_zero(t_dictionary *dictionary)
{
	printf("%s\n", dictionary->str_number);
}

int main(int argc, char* argv[]){
	char *dictionary_file;
	char *result = "";
	char **dictionary_splited;
	t_dictionary *dictionary;
	char *str_nb;

	if (argc < 2 || argc > 3) {
		write(1, "Error\n", 6);
		return 1;
	}
	else{
		verify_number(argc, argv, &dictionary_file, &str_nb); //ALOCA 
		int file = open(dictionary_file, O_RDONLY);
		if(file > 0)
		{
			dictionary = NULL;
			while(result){
				result = get_next_line(file);
				if(!result)
					break;
				if(result[0] == '\n')
					continue;
				dictionary_splited = ft_split(result, ':');
                free(result);
				create_dictionary(dictionary_splited, &dictionary);
                free(dictionary_splited);
			}  
			bubble_sort(dictionary);

			t_dictionary *number;
			int i;
			int j = 0;
			int k = 1;
			char *str;
			
			if(atoi(str_nb) == 0){
				print_zero(dictionary);
				exit(1);
			}
			str = malloc(sizeof(char));
			str = "\0";
			i = ft_strlen(str_nb);
			i--;
			number = NULL;
			while(i >= 0)
			{
				str = ft_strjoin(ft_strdup(str), charToString(str_nb[i]));
				j++;
				if(j == 3 || i == 0 )
				{
					if(j == 2)
						str = ft_strjoin(ft_strdup(str), "0");
					create_numbers(str, k, &number);
					str = "\0";
					k++;
					j= 0;
				}
				i--;
			}
			print_dictionary(number, dictionary);
            
            free1d(dictionary_file);
            free(dictionary);
            
		}
	}
    return (0);
}
