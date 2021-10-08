MAKEFLAGS += -s

NAME_SERVER = server
NAME_CLIENT = client

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

LIBFT = -Llibft -lft

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

SANITIZE = -fsanitiza=address -g3

all: pre $(NAME_SERVER) $(NAME_CLIENT)
		@echo Cosas compiladas. \¡Disfruta!.

$(NAME_SERVER): $(OBJS_SERVER)
			@$(CC) $(FLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
			@$(CC) $(FLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

pre:
		@echo Compilando cosas.... \!\!Espera!!.
		@$(MAKE) -C ./libft

clean:
		@$(MAKE) clean -C ./libft
		@rm -rf $(OBJS_SERVER)
		@rm -rf $(OBJS_CLIENT)
		@echo Cosas .o borradas.

fclean: clean
		@rm -rf $(NAME_SERVER)
		@rm -rf $(NAME_CLIENT)
		@echo Cosas ejecutables también borradas.

re: fclean all