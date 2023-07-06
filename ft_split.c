#include "rush02.h"

static char	**ft_sizemat(const char *str, char c)
{
	char	**mat;
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			while (str[i] && str[i] != c)
				i++;
			n++;
		}
	}
	mat = (char **) malloc((n + 1) * sizeof(char *));
	if (!mat)
		return (NULL);
	return (mat);
}

static int	ft_wordsize(const char *str, char c, int indice)
{
	int	wordsize;

	wordsize = 0;
	while (str[indice] && str[indice] != c)
	{
		wordsize++;
		indice++;
	}
	return (wordsize + 1);
}

char	**ft_split(const char *s, char c)
{
	char	**mat;
	int		j;
	int		i;
	int		k;

	mat = ft_sizemat(s, c);
	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (s[i])
		{
			mat[j] = (char *)malloc(ft_wordsize(s, c, i) * sizeof(char));
			if (!mat[j])
				return (NULL);
			while (s[i] && s[i] != c)
				mat[j][k++] = s[i++];
			mat[j++][k] = '\0';
		}
	}
	mat[j] = NULL;
	return (mat);
}