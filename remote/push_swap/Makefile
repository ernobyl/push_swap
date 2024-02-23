CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibft -lft

SRCS = push_swap.c \
		error_handling.c \
		sorting.c \
		operations/swap.c \
		operations/push.c \
		operations/rotate.c \
		operations/do_operations.c \
		operations/do_more_operations.c \
		operations/do_even_more_operations.c \
		operations/advanced_operations.c \
		utilities/populating_stacks.c \
		utilities/sort_utils.c \
		utilities/sort_utils_2.c \
		utilities/scan_stack.c \
		utilities/scan_stack_b.c \

OBJS = ${SRCS:.c=.o}

NAME = push_swap

${NAME}: ${OBJS}
	make -C libft
	${CC} ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}
	make clean -C libft

fclean: clean
	rm -f ${NAME}
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re