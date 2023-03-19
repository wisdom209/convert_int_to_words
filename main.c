/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:17:52 by coder             #+#    #+#             */
/*   Updated: 2023/03/19 20:51:01 by coder            ###   ########.fr       */
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

void	free_str_arr(char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i] != NULL)
		free(str_array[i++]);
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
		free(mybuf);
		_putstr("dict Error\n");
		return ;
	}
	word_arr = get_wordarr(arr_count(str_array), str_array);
	if (word_arr == NULL)
		exit(-1);
	print_to_words((arg), word_arr, arr_count(str_array));
	_putstr("\n");
	free_str_arr(str_array);
	free(mybuf);
	free(word_arr);
}

int	is_valid_int(char *str)
{
	int	i;

	str = trim_spaces(str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(1, "error\n", 6);
			return (0);
		}
		i++;
	}
	if ((i >= 10 && ft_atoi(str) <= 0))
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	int	arg;

	if (argc == 2 && is_valid_int(argv[1]))
	{
		arg = ft_atoi(argv[1]);
		handle_value_printing(arg, "numbers.dict");
	}
	else if (argc == 3 && is_valid_int(argv[2]))
	{
		arg = ft_atoi(argv[2]);
		handle_value_printing(arg, argv[1]);
	}
	return (0);
}
