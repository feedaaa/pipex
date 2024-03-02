char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*all;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	all = (char *)malloc(sizeof(char) *(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!all)
		return (NULL);
	while (s1[i] && s1)
	{
		all[i] = s1[i];
		i++;
	}
	while (s2[j] && s2)
	{
		all[i] = s2[j];
		j++;
		i++;
	}
	all[i] = '\0';
	return (all);
}

static int	wordcount(char *str, char c)
{
	int	i;
	int	word;

	i = 1;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static void	freemem(char **str, int i)
{
	if (!str)
		return ;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free (str);
}

static char	**allocation(const char *s, char c)
{
	char	**all;
	int		word;

	if (s == NULL || *s == '\0')
	{
		all = malloc(sizeof(char *));
		if (!all)
			return (NULL);
		all[0] = NULL;
		return (all);
	}
	word = wordcount((char *)s, c);
	all = malloc(sizeof(char **) * (word + 1));
	if (!all)
		return (NULL);
	all[word] = 0;
	return (all);
}

static void	substring(char **all, const char *s, char c, int word)
{
	int		j;
	size_t	len;
	size_t	i;

	j = 0;
	i = 0;
	while (s[i])
	{
		len = 0;
		while (s[i + len] != c && s[i + len])
			len++;
		if (len && j < word)
		{
			all[j] = ft_substr(s, i, len);
			if (!all[j])
			{
				freemem(all, j);
				return ;
			}
			j++;
		}
		i += len;
		i++;
	}
}

char	**ft_split(const char *s, char c)
{
	char	**all;
	int		word;

	if (!s)
		return (NULL);
	all = allocation(s, c);
	if (!all)
		return (NULL);
	if (*s == '\0' && c != '\0')
	{
		all[0] = NULL;
		return (all);
	}
	word = wordcount((char *)s, c);
	substring(all, s, c, word);
	return (all);