#include "main.h"

struct s_words *get_wordarr(int count, char **str_array)
{
	struct s_words *word_arr;
	int i;

	i = 0;
	word_arr = malloc(sizeof(struct s_words) * count + 10);
	if(word_arr == NULL)
		exit(-1);
	while (i < count)
	{
		word_arr[i].key = ft_atoi(strtok((str_array[i]), ":"));
		word_arr[i].value =	trim_spaces(strtok(NULL, ":"));
		i++;
	}
	return (word_arr);
}
