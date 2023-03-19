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

char **split_string(char **str_array)
{
	char buff[BUFFER_SIZE];
	char str[BUFFER_SIZE];
	int fd;
	int count;
	char *p;

	fd = open("./numbers.dict", O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	count = 0;
	while (read(fd, buff, 1) > 0)
		str[count++] = buff[0];
	p = strtok(str, "\n");
	count = 0;
	while (p != NULL)
	{
		str_array[count++] = p;
		p = strtok(NULL, "\n");
	}
	str_array[count] = NULL;
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
	return (NULL);
}
