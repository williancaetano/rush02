#include "rush02.h"

void verify_number(int *nb, int argc, char *argv[], char **dicionary)
{
    if(argc == 2)
    {
        *nb = ft_atoi(argv[1]);
        *dicionary = ft_strdup("numbers.dict");
    }
    if (argc == 3)
    {
        *nb = ft_atoi(argv[2]);
        *dicionary = argv[1];
    }
    (void)dicionary;
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
    return (ft_strtrim(new_content, " "));
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


void    ft_lstadd_back(t_dicionary **lst, t_dicionary *new)
{
    t_dicionary    *first;

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


void create_dicionary(char** dictionary_line, t_dicionary **head) {
  
    t_dicionary* entry = (t_dicionary*)malloc(sizeof(t_dicionary));
    entry->nb = ft_atoi(ft_epur_str(dictionary_line[0]));
    entry->str_number = ft_strdup(ft_epur_str(dictionary_line[1]));
    entry->next = NULL;

    free(dictionary_line[0]);
    free(dictionary_line[1]);     

    ft_lstadd_back(head, entry);
}


void bubble_sort(t_dicionary** head) {
    int swapped = 1;
    t_dicionary* lptr = NULL;
    int temp_nb;
    char* temp_str;

    if (*head == NULL)
        return;

    while (swapped) {
        swapped = 0;
        t_dicionary* current = *head;

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

//teste de impressão
void print_dicionary(t_dicionary* head) {
    t_dicionary* current = head;

    while (current != NULL) {
        printf("nb: %d, str_number: %s\n", current->nb, current->str_number);
        current = current->next;
    }
}




