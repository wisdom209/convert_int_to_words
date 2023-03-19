/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:12:26 by coder             #+#    #+#             */
/*   Updated: 2023/03/19 20:20:12 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	contains_delimiter(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ':' && i != 0)
			return (1);
		i++;
	}
	return (0);
}

char	**split_read_str(char *str, char **str_array)
{
	int		count;
	char	*p;

	p = _strtok(str, "\n");
	count = 0;
	while (p != NULL)
	{
		str_array[count] = ft_strdup(p);
		if (contains_delimiter(str_array[count]) == 0)
		{
			while (count >= 0)
				free(str_array[count--]);
			return (NULL);
		}
		p = _strtok(NULL, "\n");
		count++;
	}
	str_array[count] = NULL;
	return (str_array);
}

char	**split_string(char **str_array, char *ref_dictionary)
{
	char	buff[BUFFER_SIZE];
	char	str[BUFFER_SIZE];
	int		fd;
	int		count;

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
