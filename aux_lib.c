#include "rush02.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-')
			sign = sign * (-1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}

void    ft_bzero(void *s, size_t n)
{
    size_t    i;

    i = 0;
    while (i < n)
    {
        *(unsigned char *)(s + i) = 0;
        i++;
    }
}

void	*ft_calloc(size_t number, size_t size)
{
	size_t	total;
	void	*ptr;

	total = number * size;
	ptr = malloc(total);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}