##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	my_put_nbr.c				\
		my_strcpy.c					\
		my_putchar.c				\
		my_showstr.c				\
		my_isneg.c					\
		my_sort_int_array.c			\
		my_str_isupper.c			\
		my_strcmp.c					\
		my_showmem.c				\
		my_strstr.c					\
		my_revstr.c					\
		my_find_prime_sup.c			\
		my_strcapitalize.c			\
		my_strncpy.c				\
		my_str_isalpha.c			\
		my_strcat.c					\
		my_compute_square_root.c	\
		my_is_prime.c				\
		my_str_isnum.c				\
		my_getnbr.c					\
		my_strupcase.c				\
		my_str_islower.c			\
		my_strlen.c					\
		my_putstr.c					\
		my_strncmp.c				\
		my_str_isprintable.c		\
		my_strncat.c				\
		my_compute_power_rec.c		\
		my_strlowcase.c				\
		my_str_to_word_array.c		\
		my_free_word_array.c		\
		my_array_len.c				\
		my_strdup.c					\
		my_swap.c					\
		my_strdup.c					\
		my_strdup_char.c			\
		my_find_char.c				\
		convert_base.c				\
		my_putnbr_base.c			\
		my_getnbr_base.c			\
		my_put_in_list.c			\
		my_append_to_list.c			\
		my_list.c					\
		my_list_to_str.c			\
		my_concat_str_list.c		\
		my_list_size.c				\
		my_free_list.c				\
		my_concat_list.c			\
		my_rev_list.c				\
		my_node.c					\
		my_delete_node.c			\
		my_nbr_to_str.c				\
		my_nbr_len.c				\
		open_file.c					\
		get_next_line.c

CFLAGS	=	-I. -Wall -Wextra -Werror

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) clean

$(NAME):	$(OBJ)
	ar rc $(NAME) *.o
	mv $(NAME) ../
	mkdir -p ../../include
	cp my*.h ../../include

clean:
	rm -f *.o
