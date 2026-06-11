NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_PATH	= libft
LIBFT		= $(LIBFT_PATH)/libft.a

SRCS		= ft_printf.c ft_toolsf.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
