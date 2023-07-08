#include "rush02.h"

char	*char_to_string(char c)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	str[0] = c;
	str[1] = '\0';
	return (str);
}

long int	ft_atol(const char *str)
{
	long int	i;
	long int	sign;
	long int	num;

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

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 47 || str[i] >= 58)
			return (0);
		i++;
	}	
	return (1);
}

int	verify_args(int argc, char **argv)
{
	char	*str_nb;
	int		j;

	j = 0;
	if (argc < 2 || argc > 3)
		j = 1;
	if (argc == 2)
		str_nb = argv[1];
	if (argc == 3)
		str_nb = argv[2];
	if (ft_atol(str_nb) > INT_MAX)
		j = 1;
	if (ft_atol(str_nb) < 0)
		j = 1;
	if (ft_isdigit(str_nb) == 0)
		j = 1;
	if (j == 1)
		write(1, "Error\n", 6);
	return (j);
}
