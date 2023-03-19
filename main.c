/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iononiwu <iononiwu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:10:00 by iononiwu          #+#    #+#             */
/*   Updat
ed: 2023/03/18 18:10:04 by iononiwu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	char **mybuf;
	char **str_array;
	int count;
	struct s_words *word_arr;
	int arg = ft_atoi(argv[1]);

	mybuf = malloc(BUFFER_SIZE);
	str_array = split_string(mybuf);
	count = 0;
	while (str_array[count] != NULL)
		count++;
	word_arr = get_wordarr(count, str_array);
	print_to_words(arg, word_arr, count);
	printf("\n");
	free(mybuf);
	free(word_arr);
	return (0);
}

// int _pow(int x, int y)
// {
// 	int temp;

// 	temp = x;
// 	while (y > 1)
// 	{
// 		x = x * temp;
// 		y--;
// 	}
// 	return (x);
// }

// int get_int_len(int nbr)
// {
// 	int i;

// 	i = 0;
// 	while (nbr / 10 != 0)
// 	{
// 		nbr = nbr / 10;
// 		i++;
// 	}
// 	return (i);
// }
