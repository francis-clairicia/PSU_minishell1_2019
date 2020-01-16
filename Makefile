##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

MAIN		=	main.c

SRC_DIR		=	src

SRC			=	$(SRC_DIR)/minishell.c					\
				$(SRC_DIR)/print_command_prompt.c		\
				$(SRC_DIR)/get_path_to_executable.c		\
				$(SRC_DIR)/find_binary_in_path.c		\
				$(SRC_DIR)/find_var_env.c				\
				$(SRC_DIR)/get_var_value.c				\
				$(SRC_DIR)/create_variable.c			\
				$(SRC_DIR)/join_path.c					\
				$(SRC_DIR)/error.c						\
				$(SRC_DIR)/sigint_handler.c				\
				$(SRC_DIR)/builtin_functions.c			\
				$(SRC_DIR)/cd_builtin_command.c			\
				$(SRC_DIR)/env_builtin_command.c		\
				$(SRC_DIR)/exit_builtin_command.c		\
				$(SRC_DIR)/setenv_builtin_command.c		\
				$(SRC_DIR)/unsetenv_builtin_command.c

CFLAGS		=	-I./include/ -Wall -Wextra

LIB			=	-L./lib -lmy

OBJ			=	$(MAIN:.c=.o) $(SRC:.c=.o)

NAME		=	mysh

all:	$(NAME)

lib:
	make -s -C ./lib/my

$(NAME):	lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB)
	rm -f $(OBJ)

tests_run:	lib
	@find . -name "*.gc*" -delete
	gcc -o unit_tests $(SRC) tests/*.c $(LIB) $(CFLAGS) --coverage -lcriterion
	./unit_tests
	rm -f unit_tests test*.gc*
	mkdir -p coverage
	mv *.gc* coverage/

debug:	lib
	gcc -g -o $(NAME) $(MAIN) $(SRC) lib/my/*.c $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f unit_tests *.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all lib tests_run debug clean fclean re
