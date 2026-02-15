int	ft_strlen(char *str);

char	split_number(char *number)
{
	int		index;
	int		len;
	char	block[4];
	int		actual_block;

	len = ft_strlen(number);
	actual_block = len % 3;
	index = 0;
	while (index < actual_block)
	{
		block[index] = number[index];
		index++;	
	}
	block[index] = '\0';
	block_to_number(block);
	block_index(number % (len - actual_block));
	number_combination(number % (len - actual_block));
}