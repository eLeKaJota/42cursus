LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =	ft_printf.c srcs/ft_print_args.c srcs/ft_allocs.c srcs/ft_get_infos.c \
		srcs/ft_flags.c srcs/ft_print_nums.c srcs/ft_itoa_u.c srcs/ft_print_utils.c \

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp $(LIBFT) $(NAME)
	$(CC) $(FLAGS) -I. $(SRCS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS)
	$(MAKE) bonus -C ./libft
	cp $(LIBFT) $(NAME)
	$(CC) $(FLAGS) -I. $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
