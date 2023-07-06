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


typedef struct s_dicionary{
	int nb;
	char* str_number;
	struct s_dicionary *next;
}t_dicionary;

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *str, int c);

char	*ft_strdup(const char *src);

char	*ft_strjoin(char *s1, char const *s2);

char	*get_next_line(int fd);


void    verify_number(int *nb, int argc, char *argv[], char **dicionary);
int     ft_atoi(const char *str);
char	*ft_strdup(const char *src);
char	*get_next_line(int fd);
char    *ft_epur_str(char *content);
char	**ft_split(const char *s, char c);
char    *ft_strtrim(char const *s1, char const *set);
void    ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t number, size_t size);
void create_dicionary(char** dictionary_line, t_dicionary **head);
void    ft_lstadd_back(t_dicionary **lst, t_dicionary *new);
void bubble_sort(t_dicionary** head);
void print_dicionary(t_dicionary* head); //teste de impreção do dicionario
#endif