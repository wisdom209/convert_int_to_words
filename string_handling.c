#include "main.h"

int _strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *trim_spaces(char *str)
{
	int begin = 0;

	while (_isspace((unsigned char)str[begin]))
		begin++;
	return (&str[begin]);
}

int contains_delimiter(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == ':' && i != 0)
			return (1);
		i++;
	}
	return (0);
}


char **split_read_str(char *str, char **str_array)
{
	int		count;
	char	*p;

	p = strtok(str, "\n");
	count = 0;
	while (p != NULL)
	{
		str_array[count] = strdup(p);
		if (contains_delimiter(str_array[count]) == 0)
		{
			return (NULL);
		}
		p = strtok(NULL, "\n");
		count++;
	}
	str_array[count] = NULL;
	return(str_array);
}

char **split_string(char **str_array, char *ref_dictionary)
{
	char buff[BUFFER_SIZE];
	char str[BUFFER_SIZE];
	int fd;
	int count;

	fd = open(ref_dictionary, O_RDONLY);
	if (fd < 0)
		return (NULL);
	count = 0;
	while (read(fd, buff, 1) > 0)
		str[count++] = buff[0];
	str_array = split_read_str(str, str_array);
	close(fd);
	return (str_array);
}

char *find_in_dictionary(int count, int arg, struct s_words *word_arr)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (arg == word_arr[i].key)
			return (word_arr[i].value);
		i++;
	}
	exit(-1);
	return (NULL);
}

void _putstr(char *str)
{
	int i;
	
	i = 0;
	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}