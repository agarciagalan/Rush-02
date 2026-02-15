typedef struct 	s_entry
{
	char	*key;
	char	*value;
}s_entry;

typedef struct	s_dict
{
	s_entry		*entries;
	int 		size;
	int			count;
}s_dict;

typedef struct  s_block
{
	char	data[4];
} s_block;

typedef struct	s_splited_number
{
	int			len;
	s_block		*number;
} s_splited_number;