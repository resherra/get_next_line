CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
NAME = utils.a

all: ${NAME}

${NAME}: ${OBJ}
	ar -rcs ${NAME} ${OBJ}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf utils.a a.out

re: fclean all

main:
	${CC} ${CFLAGS} main.c get_next_line.c
