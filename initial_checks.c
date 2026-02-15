#include <unistd.h>
#include "includes/dict.h"

s_dict	*ft_get_dictionary(char *dict_path, s_dict *dict);
s_dict	*ft_dict_create();

s_dict	*ft_dict_check(char *dict_path, s_dict *dict)
{
	s_dict	*dict;
	ft_get_dictionary(dict_path, dict);
	return(dict);
}

int		ft_number_check(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}
/*
void	ft_eliminate_initial_zeros(char *str)
{

}
*/