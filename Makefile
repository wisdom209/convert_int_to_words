all:
	cc -g -Wall -Werror -Wextra *.c -o rush-02
fclean:
	rm -f *.o rush-02
