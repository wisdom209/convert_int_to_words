/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:17:52 by coder             #+#    #+#             */
/*   Updated: 2023/03/19 17:44:20 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	arr_count(char **str_array)
{
	int	count;

	count = 0;
	while (str_array[count] != NULL)
		count++;
	return (count);
}

void	handle_value_printing(int arg, char *ref_dictionary)
{
	char			**mybuf;
	char			**str_array;
	struct s_words	*word_arr;

	mybuf = malloc(BUFFER_SIZE);
	if (mybuf == NULL)
		exit(-1);
	str_array = split_string(mybuf, ref_dictionary);
	if (str_array == NULL)
	{
		_putstr("Dict Error\n");
		return ;
	}
	word_arr = get_wordarr(arr_count(str_array), str_array);
	if (word_arr == NULL)
		exit(-1);
	print_to_words((arg), word_arr, arr_count(str_array));
	_putstr("\n");
	free(mybuf);
	free(word_arr);
}

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	int	arg;

	if (argc == 2)
	{
		arg = ft_atoi(argv[1]);
		handle_value_printing(arg, "numbers.dict");
	}
	else if (argc == 3)
	{
		arg = ft_atoi(argv[2]);
		handle_value_printing(arg, argv[1]);
	}
	return (0);
}
