#include "main.h"

void print_first_nineteen(int count, int arg, struct s_words *wordarr)
{
	char	*str;
	
	str = find_in_dictionary(count, arg, wordarr);
	_putstr(str);
}

void print_tens(int count, int arg, struct s_words *wordarr)
{
	_putstr(find_in_dictionary(count, arg - (arg % 10), wordarr));
	if (arg % 10 != 0)
	{
		_putstr(" ");
		print_first_nineteen(count, arg % 10, wordarr);
	}
}

void print_hundreds(int count, int arg, struct s_words *wordarr)
{
	_putstr(find_in_dictionary(count, (arg - (arg % 100)) / 100, wordarr));
	_putstr(" ");
	_putstr(find_in_dictionary(count, 100, wordarr));
	if (arg % 100 != 0)
	{
		_putstr(" and ");
		if (arg % 100 <= 20)
			print_first_nineteen(count, arg % 100, wordarr);
		else
			print_tens(count, arg % 100, wordarr);
	}
}

void print_thousands(int count, int arg, struct s_words *wordarr)
{
	_putstr(find_in_dictionary(count, (arg - (arg % 1000)) / 1000, wordarr));
	_putstr(" ");
	_putstr(find_in_dictionary(count, 1000, wordarr));
	if (arg % 1000 != 0)
	{
		if ((arg % 1000) < 100)
			_putstr(" and ");
		else
			_putstr(" ");
		print_to_words(arg % 1000, wordarr, count);
	}
}

void print_ten_thousands(int count, int arg, struct s_words *wordarr)
{
	print_to_words(arg / 1000, wordarr, count);
	_putstr(" ");
	_putstr(find_in_dictionary(count, 1000, wordarr));
	if (arg % 10000 != 0)
	{
		if ((arg % 1000) < 100)
			_putstr(" and ");
		else
			_putstr(" ");
		print_to_words((arg % 1000), wordarr, count);
	}
}
