#ifndef RUSH02_H
# define RUSH02_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif


#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>


typedef struct s_dictionary{
	int nb;
	char* str_number;
	struct s_dictionary *next;
}t_dictionary;

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *str, int c);

char	*ft_strdup(const char *src);

char	*ft_strjoin(char *s1, char const *s2);

char	*get_next_line(int fd);

char	**free1d(char *ptr);

char	**free2d(char **pp);


void    verify_number(int argc, char *argv[], char **dictionary, char **str);
int     ft_atoi(const char *str);
char	*ft_strdup(const char *src);
char	*get_next_line(int fd);
char    *ft_epur_str(char *content);
char	**ft_split(const char *s, char c);
char    *ft_strtrim(char const *s1, char const *set);
void    ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t number, size_t size);
void create_dictionary(char** dictionary_line, t_dictionary **head);
void    ft_lstadd_back(t_dictionary **lst, t_dictionary *new);
void bubble_sort(t_dictionary* head);
void print_dictionary(t_dictionary* number, t_dictionary* dictionary); //teste de impreção do dicionario
void	ft_lstadd_front(t_dictionary **lst, t_dictionary *new);
char* charToString(char c);
#endif