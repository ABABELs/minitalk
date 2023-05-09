# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabel <aabel@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 11:37:47 by aabel             #+#    #+#              #
#    Updated: 2023/05/04 14:58:08 by aabel            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := client

SRCS_CLIENT =	src/client.c \

SRCS_SERVER =	src/server.c \

OBJS_CLIENT = $(SRCS_CLIENT:%.c=%.o)
OBJS_SERVER = $(SRCS_SERVER:%.c=%.o)


CC = GCC
RM = rm -f
CLFAGS = -Wall -Wextra -Werror

LIBFT_DIR = inc/libft_printf/libft.a

all: $(NAME)

$(NAME): $(OBJS_CLIENT) $(OBJS_SERVER)
		@make -C inc/libft_printf
		@$(CC) -o client $(OBJS_CLIENT) $(LIBFT_DIR)
		@$(CC) -o server $(OBJS_SERVER) $(LIBFT_DIR)

clean:
		@make -C inc/libft_printf clean
		@$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
		@$(RM) server
		@$(RM) client

re: fclean all

.PHONY: all clean fclean re bonus