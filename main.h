/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:15:02 by bbarney           #+#    #+#             */
/*   Updated: 2023/03/19 20:06:16 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFFER_SIZE 1024

struct s_words
{
	int		key;
	char	*value;
};

int				_strlen(char *str);
char			*trim_spaces(char *str);
char			**split_string(char **str_array, char *ref_dict);
char			*find_in_dictionary(int count, int arg, \
				struct s_words *word_arr);
void			print_to_words(int arg, struct s_words *wordarr, \
				int count);
int				ft_atoi(char *str);
int				_isspace(char c);

void			print_first_nineteen(int count, int arg, \
				struct s_words *wordarr);
void			print_tens(int count, int arg, struct s_words *wordarr);
void			print_hundreds(int count, int arg, struct s_words *wordarr);
void			print_thousands(int count, int arg, struct s_words *wordarr);
void			print_ten_thousands(int count, int arg, \
				struct s_words *wordarr);
void			print_hundred_thousands(int count, int arg, \
				struct s_words *wordarr);
void			print_millions(int count, int arg, struct s_words *wordarr);
void			print_billions(int count, int arg, struct s_words *wordarr);
struct	s_words	*get_wordarr(int count, char **str_array);
void			_putstr(char *str);
int				arr_count(char **str_array);
void			handle_value_printing(int arg, char *ref_dict);
int				contains_delimiter(char *str);
void			free_str_arr(char **str_array);
int				is_valid_int(char *str);
size_t			_strspn(const char *s, const char *accept);
char			*_strpbrk(const char *s, const char *accept);
char			*_strchr(char *str, char c);
char			*ft_strdup(char *src);
char			*_strtok(char *s, const char *delim);
#endif
