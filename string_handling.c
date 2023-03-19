/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:49:11 by bbarney           #+#    #+#             */
/*   Updated: 2023/03/19 20:12:19 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*trim_spaces(char *str)
{
	int	begin;

	begin = 0;
	while (_isspace((unsigned char)str[begin]))
		begin++;
	return (&str[begin]);
}

char	*find_in_dictionary(int count, int arg, struct s_words *word_arr)
{
	int	i;

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
