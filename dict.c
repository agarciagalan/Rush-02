#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "includes/dict.h"
#define DICT_SIZE 128
#define BUFFER_SIZE 128

// int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(char str);

// File functions //
int		ft_file_length(char *dict_path)
{
	int		file_description;
	char	buffer[BUFFER_SIZE];
	int		counter;

	file_description=open(dict_path, O_RDONLY);
	counter = 0;
	while (read(file_description, buffer, BUFFER_SIZE) != 0)
	{
		while (buffer[counter])
			counter++;
	}
	close(file_description);
	return (counter);
}

char	*ft_get_text(int file_description, char *text)
{
	int		content;
	int		buffer_index;
	int		text_index;
	char	buffer[BUFFER_SIZE];

	text_index = 0;
	while ((content=read(file_description, buffer, BUFFER_SIZE)) != 0)
	{
		buffer_index = 0;
		while (buffer[buffer_index])
		{
			text[text_index] = buffer[buffer_index];
			buffer_index++;
			text_index++;
		}
	}
	return (text);
}

// Dictionary functions //
s_dict	*ft_dict_create()
{
    s_dict	*dict = malloc(sizeof(s_dict));

	if (dict == NULL)
		return (NULL);
    dict->size = DICT_SIZE;
	dict->count = 0;
    dict->entries = malloc(sizeof(s_entry) * DICT_SIZE);
	if (dict->entries == NULL)
	{
		free(dict);
		return (NULL);
	}
    return dict;
}

void	ft_dict_destroy(s_dict *dict)
{
	int		index;
	
	index = 0;
	while (index < dict->count)
	{
		free(dict->entries[index].key);
		free(dict->entries[index].value);
		index++;
	}
	free(dict->entries);
	free(dict);
}

int		ft_check_keys(char *text)
{
	
}

s_entry	*ft_create_entry(char *text, char *key, char *value)
{
	s_entry *entry;

	while (ft_isdigit(*text))
	{
		text++;
	}
	if (key == NULL)
		return (NULL);
	else
		entry->key = key;
	while (*text == ' ')
		text++;
	if (*text != ':')
		return (NULL);
	else
		text++;
	while (*text == ' ')
		text++;
	while (*text >= 32 && *text <= 126)
	{
		*value = *text;
		value++;
		text++;
	}
	if (value == NULL)
		return (NULL);
	else
		entry->value = value;
	return (entry);
}

s_dict	*ft_parse_dictionary(char *text, s_dict *dict)
{
	char	line[200];
	char	*key;
	char	*value;
	s_entry	*entry;

	key = malloc(50 * sizeof(char));
	value = malloc(50 * sizeof(char));
	while (text[text_index])
	{
		
	}
	return (dict);
}

s_dict	*ft_get_dictionary(char *dict_path, s_dict *dict)
{
	int		file_description;
	int		content;
	int		file_size;
	char	buffer[BUFFER_SIZE];
	char	*text;

	if((file_description=open(dict_path, O_RDONLY)) == -1)
		return (NULL);
	if((content=read(file_description, buffer, BUFFER_SIZE)) == -1)
		return (NULL);
	else
	{
		file_size = ft_file_length(dict_path);
		text = malloc(file_size * sizeof(char*));
		ft_get_text(file_description, text);
		if ((ft_check_keys(text)))
			return (NULL);
		ft_parse_dictionary(text, dict);
	}
	close(file_description);
	return (dict);
}




/*
int dict_find_index(s_dict *dict, const char *key) {
	int		index;

	index = 0;
	while (index < dict.len)
	{
		if (!ft_strcmp(dict.entry[i], key)) {
            return i;
        }
		index++;
	}
    return -1;
}
r "./diccionario.dict" "12345"

void    order_dictionary(void)
{

}
*/