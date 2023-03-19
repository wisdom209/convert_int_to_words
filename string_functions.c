/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:13:47 by coder             #+#    #+#             */
/*   Updated: 2023/03/19 20:19:45 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*_strtok(char *s, const char *delim)
{
	static char	*olds;
	char		*token;

	if (s == NULL)
		s = olds;
	s += _strspn(s, delim);
	if (*s == '\0')
	{
		olds = s;
		return (NULL);
	}
	token = s;
	s = _strpbrk(token, delim);
	if (s == NULL)
		olds = _strchr(token, '\0');
	else
	{
		*s = '\0';
		olds = s + 1;
	}
	return (token);
}

size_t	_strspn(const char *s, const char *accept)
{
	const char	*p;
	const char	*a;
	size_t		count;

	count = 0;
	p = s;
	while (*p != '\0')
	{
		a = accept;
		while (*a != '\0')
		{
			if (*p == *a)
				break ;
			++a;
		}
		if (*a == '\0')
			return (count);
		++count;
		++p;
	}
	return (count);
}

char	*_strpbrk(const char *s, const char *accept)
{
	const char	*a;

	while (*s != '\0')
	{
		a = accept;
		while (*a != '\0')
			if (*a++ == *s)
				return ((char *)s);
		++s;
	}
	return (NULL);
}

char	*_strchr(char *str, char c)
{
	char	*p;

	p = str;
	if (*p == c)
		return (p);
	while (*p++)
	{
		if (*p == c)
			return (p);
	}
	return (NULL);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (src[i] != '\0')
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (dest == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
