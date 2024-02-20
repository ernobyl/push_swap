CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibft -lft

SRCS = push_swap.c \
		swap.c \
		push.c \
		rotate.c \
		do_operations.c \
		do_more_operations.c \
		do_even_more_operations.c \
		advanced_operations.c \
		error_handling.c \
		populating_stacks.c \
		sorting.c \
		sort_utils.c \
		sort_utils_2.c \
		scan_stack.c \
		scan_stack_b.c \



NAME = push_swap

${NAME}: ${SRCS}
	make -C libft
	${CC} ${CFLAGS} ${SRCS} ${LDFLAGS} -o ${NAME}

all: ${NAME}

clean:
	make clean -C libft

fclean: clean
	rm -f ${NAME}
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re