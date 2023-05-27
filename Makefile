CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= push_swap
AR		= ar r
RM		= rm -f
SRCS	= push_swap.c
OBJS	= $(SRCS:.c=.o)
LIBNAME	= push_swap.h
MAKE = make
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
LIBFT_NAME = libft/libft.a
FT_PRINTF_NAME = ft_printf/libftprintf.a

all:	$(NAME)
$(NAME):	$(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(LIBFT_NAME) $(FT_PRINTF_NAME) $(OBJS) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT_NAME) $(FT_PRINTF_NAME) $(NAME)

re:		fclean all

.PHONY: all clean fclean re