/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:48:03 by bbarney           #+#    #+#             */
/*   Updated: 2023/03/19 20:43:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] == ' ' && str[i + 1] == ' '))
			write(1, &str[i], 1);
		i++;
	}
}

void	print_hundred_thousands(int count, int arg, struct s_words *wordarr)
{
	print_to_words(arg / 1000, wordarr, count);
	_putstr(" ");
	_putstr(find_in_dictionary(count, 1000, wordarr));
	if (arg % 100000 != 0)
	{
		if ((arg % 1000) < 100)
			_putstr(" and ");
		else
			_putstr(" ");
		print_to_words((arg % 1000), wordarr, count);
	}
}

void	print_millions(int count, int arg, struct s_words *wordarr)
{
	print_to_words(arg / 1000000, wordarr, count);
	_putstr(" ");
	_putstr(find_in_dictionary(count, 1000000, wordarr));
	if (arg % 1000000 != 0)
	{
		if ((arg % 1000000) < 100)
			_putstr(" and ");
		else
			_putstr(" ");
		print_to_words((arg % 1000000), wordarr, count);
	}
}

void	print_billions(int count, int arg, struct s_words *wordarr)
{
	print_to_words(arg / 1000000000, wordarr, count);
	_putstr(" ");
	_putstr(find_in_dictionary(count, 1000000000, wordarr));
	if (arg % 1000000 != 0)
	{
		if ((arg % 1000000000) < 100)
			_putstr("and ");
		else
			_putstr(" ");
		print_to_words((arg % 1000000000), wordarr, count);
	}
}

void	print_to_words(int arg, struct s_words *wordarr, int count)
{
	if (arg <= 20)
		print_first_nineteen(count, arg, wordarr);
	else if (arg > 20 && arg < 100)
		print_tens(count, arg, wordarr);
	else if (arg >= 100 && arg < 1000)
		print_hundreds(count, arg, wordarr);
	else if (arg >= 1000 && arg < 10000)
		print_thousands(count, arg, wordarr);
	else if (arg >= 10000 && arg < 100000)
		print_ten_thousands(count, arg, wordarr);
	else if (arg >= 100000 && arg < 1000000)
		print_hundred_thousands(count, arg, wordarr);
	else if (arg >= 1000000 && arg < 1000000000)
		print_millions(count, arg, wordarr);
	else if (arg >= 1000000000 && arg <= 2147483647)
		print_billions(count, arg, wordarr);
	else
		write(1, "error", 5);
}
