CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibft -lft

SRCS = push_swap.c \
		swap.c \
		push.c \
		rotate.c \

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