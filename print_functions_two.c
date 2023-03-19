#include "main.h"

void print_hundred_thousands(int count, int arg, struct s_words *wordarr)
{
	print_to_words(arg / 1000, wordarr, count);
	printf(" ");
	printf("%s ", find_in_dictionary(count, 1000, wordarr));
	if (arg % 100000 != 0)
	{
		if ((arg % 100000) < 100)
			printf("and ");
		print_to_words((arg % 1000), wordarr, count);
	}
}

void print_millions(int count, int arg, struct s_words *wordarr)
{
	print_to_words(arg / 1000000, wordarr, count);
	printf(" ");
	printf("%s ", find_in_dictionary(count, 1000000, wordarr));
	if (arg % 1000000 != 0)
	{
		if ((arg % 1000000) < 100)
			printf("and ");
		print_to_words((arg % 1000000), wordarr, count);
	}
}

void print_billions(int count, int arg, struct s_words *wordarr)
{
	print_to_words(arg / 1000000000, wordarr, count);
	printf(" ");
	printf("%s ", find_in_dictionary(count, 1000000000, wordarr));
	if (arg % 1000000 != 0)
	{
		if ((arg % 1000000000) < 100)
			printf("and ");
		print_to_words((arg % 1000000000), wordarr, count);
	}
}

void print_to_words(int arg, struct s_words *wordarr, int count)
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
	else if (arg >= 1000000000)
		print_billions(count, arg, wordarr);
}
