#include "main.h"

int	_isspace(char c)
{
	int		i;
	char	*space_table;

	space_table = "\f\t\n\v\r ";
	i = 0;
	while (space_table[i] != '\0')
	{
		if (c == space_table[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;
	int	minus_count;

	i = 0;
	minus_count = 0;
	result = 0;
	while (_isspace(str[i]) == 1)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus_count++;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	if (minus_count % 2 == 1 && minus_count != 0)
		return (-result);
	return (result);
}
