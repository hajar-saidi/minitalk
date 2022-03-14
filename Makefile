# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsaidi <hsaidi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 19:05:48 by hsaidi            #+#    #+#              #
#    Updated: 2022/03/14 22:38:20 by hsaidi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client
CC = gcc
FLAGS = -Wall -Wextra -Werror
SERVER_SRCS = server.c ft_utils.c
CLIENT_SRCS = ft_utils.c\
				client.c \
				ft_atoi.c\

NAME = minitalk

$(NAME) : $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME) :
	$(CC) $(FLAGS) -o $(SERVER_NAME) $(SERVER_SRCS)
$(CLIENT_NAME) :
	$(CC) $(FLAGS) -o $(CLIENT_NAME) $(CLIENT_SRCS)
all : $(NAME)

clean :
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re