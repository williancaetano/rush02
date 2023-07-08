NAME    = rush02
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -g
RM      = rm -f

SRC     = main.c \
			aux_lib.c \
			get_next_line.c \
			get_next_line_utils.c \
			utils.c \
			utils2.c \
			utils3.c \
			utils4.c \
			print_utils.c \
			print_utils2.c \
			ft_put_str.c \
			frees.c \
			ft_split.c			

OBJS    = $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) ${OBJS} -o ${NAME}

all:    $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) 

re:     fclean all

.PHONY: all clean fclean re