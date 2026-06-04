NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ft_cmp.c ft_fd.c ft_is.c ft_mapiteri.c ft_mem.c ft_mllc.c ft_split.c ft_tools.c ft_trim.c ft_lstadd.c ft_lstdelone.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re