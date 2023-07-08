#include "rush02.h"

void	ft_put_str(const char *str)
{
	if (str != NULL)
	{
		while (*str != '\0')
		{
			write(1, str, 1);
			str++;
		}
	}
}

void	ft_put_str_space(char *str)
{
	extern char	*g_print_str;

	if (g_print_str == NULL)
		g_print_str = ft_strjoin(ft_strdup(str), " ");
	else
	{
		str = ft_strjoin(ft_strdup(str), " ");
		g_print_str = ft_strjoin(g_print_str, str);
		free(str);
	}
}
