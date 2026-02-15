#include <unistd.h>
#include "includes/dict.h"

s_dict	*ft_dict_check(char *path, s_dict *dict);
int		ft_number_check(char *str);
// void	ft_process_number(char *number, char *dict_path);

int	main(int argc, char **argv)
{
	char	*dict_path;
	char	*number;
	s_dict	*dict;


	dict_path = "";
	if (argc == 2 || argc == 3)
	{
		if (argc == 2)
			number = argv[1];
		if (argc == 3)
		{
			dict_path = argv[1];
			number = argv[2];
		}
		if (ft_number_check(number))
			write(2, "Error\n", 6);
		else if ((dict=ft_dict_create()) != NULL)
			if ((ft_dict_check(dict_path, dict)) == NULL)
			write(2, "Dict Error\n", 11);
		else
		{
			//ft_process_number(number, dict);
			return (0);
		}
		return(1);
	}
}