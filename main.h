#ifndef __main_h__
#define __main_h__

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define BUFFER_SIZE 1024

struct s_words
{
	int key;
	char *value;
};

int _strlen(char *str);
char *trim_spaces(char *str);
char **split_string(char **str_array);
char *find_in_dictionary(int count, int arg, struct s_words *word_arr);
int _pow(int x, int y);
int get_int_len(int nbr);
void print_to_words(int arg, struct s_words *wordarr, int count);

int ft_atoi(char *str);
int _isspace(char c);

void print_first_nineteen(int count, int arg, struct s_words *wordarr);
void print_tens(int count, int arg, struct s_words *wordarr);
void print_hundreds(int count, int arg, struct s_words *wordarr);
void print_thousands(int count, int arg, struct s_words *wordarr);
void print_ten_thousands(int count, int arg, struct s_words *wordarr);
void print_hundred_thousands(int count, int arg, struct s_words *wordarr);
void print_millions(int count, int arg, struct s_words *wordarr);
void print_billions(int count, int arg, struct s_words *wordarr);
struct s_words *get_wordarr(int count, char **str_array);
#endif
