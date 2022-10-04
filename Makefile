SRC =	srcs/builtins/cd.c \
		srcs/builtins/echo.c \
		srcs/builtins/env.c \
		srcs/builtins/export.c \
		srcs/builtins/pwd.c \
		srcs/builtins/unset.c \
		srcs/builtins/builtins.c \
		srcs/main.c \

OBJS =	srcs/builtins/cd.o \
		srcs/builtins/echo.o \
		srcs/builtins/env.o \
		srcs/builtins/export.o \
		srcs/builtins/pwd.o \
		srcs/builtins/unset.o \
		srcs/builtins/builtins.o \
		srcs/main.o \

NAME = minishell

CC = gcc

INC = include/

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra

LIBFLAGS = -L libft -lft

all : ${NAME}

bonus : ${NAME_BONUS}

objs/%.o : srcs/%.c
	mkdir -p ./objs
	$(CC) $(CFLAGS) -I${INC} -c $< -o $@

%.o : %.c
	$(CC) $(CFLAGS) -I${INC} -c $< -o $@

${NAME} : ${OBJS} $(LIB)
	make -C ./libft
	$(CC) $(CFLAGS) ${OBJS} -D LINUX ${LIBFLAGS} -o ${NAME}

clean:
		$(RM) ${OBJS}
		$(RM) ./objs
		make clean -C ./libft

fclean: clean
		$(RM) $(NAME)
		$(RM) ./libft/libft.a

re:	fclean all