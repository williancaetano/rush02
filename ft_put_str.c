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

void	ft_put_str_space(const char *str)
{
	if (str != NULL)
	{
		while (*str != '\0')
		{
			write(1, str, 1);
			str++;
		}
		write(1, " ", 1);
	}
}
