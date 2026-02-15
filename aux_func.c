int     ft_atoi(char *str)
{
	
}

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 > *s2 || *s1 < *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

int		ft_isdigit(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}