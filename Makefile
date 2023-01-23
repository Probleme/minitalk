# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 02:07:15 by ataouaf           #+#    #+#              #
#    Updated: 2023/01/22 23:06:15 by ataouaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = ./src
OBJECTS = ./obj
INCLUDES = ./inc

SRCS = print_c_d.c ft_printf.c ft_atoi.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(addprefix $(OBJECTS)/, $(SRCS:.c=.o))

RM = rm -rf

all : server client

${OBJECTS}/%.o : ${SOURCES}/%.c ${INCLUDES}/minitalk.h $(INCLUDES)/minitalk_bonus.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $< 

server : $(OBJS) $(OBJECTS)/server.o
	$(CC) $(CFLAGS)  -o server $(OBJS) $(OBJECTS)/server.o

client : $(OBJS) $(OBJECTS)/client.o
	$(CC) $(CFLAGS) -o client $(OBJS) $(OBJECTS)/client.o

bonus : server_bonus client_bonus

server_bonus : $(OBJS) $(OBJECTS)/server_bonus.o
	$(CC) $(CFLAGS) -o server $(OBJS) $(OBJECTS)/server_bonus.o

client_bonus : $(OBJS) $(OBJECTS)/client_bonus.o
	$(CC) $(CFLAGS) -o client $(OBJS) $(OBJECTS)/client_bonus.o

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) server client

re : fclean all

.PHONY : all bonus clean fclean re client_bonus server_bonus client server