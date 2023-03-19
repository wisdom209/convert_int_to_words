/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:36:55 by bbarney           #+#    #+#             */
/*   Updated: 2023/03/19 19:43:27 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

struct s_words	*get_wordarr(int count, char **str_array)
{
	struct s_words	*word_arr;
	int				i;

	i = 0;
	word_arr = malloc(sizeof(struct s_words) * count + 10);
	if (word_arr == NULL)
		exit(-1);
	while (i < count)
	{
		word_arr[i].key = ft_atoi(_strtok((str_array[i]), ":"));
		word_arr[i].value = trim_spaces(_strtok(NULL, ":"));
		i++;
	}
	return (word_arr);
}
