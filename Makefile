# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataouaf <ataouaf@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 02:07:15 by ataouaf           #+#    #+#              #
#    Updated: 2023/01/17 02:07:18 by ataouaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = ./src
OBJECTS = ./obj
INCLUDES = ./inc

SRCS = print_c_d.c ft_printf.c ft_atoi.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
CINCLUDES = -I $(INCLUDES)

OBJS = $(addprefix $(OBJECTS)/, $(SRCS:.c=.o))

RM = rm -rf

BLACK		:=	"\033[1;30m"
RED			:=	"\033[1;31m"
GREEN		:=	"\033[1;32m"
CYAN		:=	"\033[1;35m"
BLUE		:=	"\033[1;36m"
WHITE		:=	"\033[1;37m"
EOC			:=	"\033[0;0m"

all : server client

${OBJECTS}/%.o : ${SOURCES}/%.c
	@mkdir -p $(dir $@)
	@echo "● Compilation de "$(BLUE)"${notdir $<}"$(EOC)"."
	@$(CC) $(CFLAGS) -o $@ -c $< $(CINCLUDES)

server : $(OBJS) $(OBJECTS)/server.o
	@echo $(RED)"● Compilation du server..."$(EOC)
	@$(CC) $(CFLAGS) $(CINCLUDES) -o server $(OBJS) $(OBJECTS)/server.o

client : $(OBJS) $(OBJECTS)/client.o
	@echo $(CYAN)"● Compilation du client..."$(EOC)
	@$(CC) $(CFLAGS) $(CINCLUDES) -o client $(OBJS) $(OBJECTS)/client.o

bonus : server_bonus client_bonus

server_bonus : $(OBJS) $(OBJECTS)/server_bonus.o
	@echo $(RED)"● Compilation du server (bonus)..."$(EOC)
	@$(CC) $(CFLAGS) $(CINCLUDES) -o server $(OBJS) $(OBJECTS)/server_bonus.o

client_bonus : $(OBJS) $(OBJECTS)/client_bonus.o
	@echo $(CYAN)"● Compilation du client (bonus)..."$(EOC)
	@$(CC) $(CFLAGS) $(CINCLUDES) -o client $(OBJS) $(OBJECTS)/client_bonus.o


clean :
	@echo ${GREEN}"● Supression des fichiers binaires (.o)..."$(EOC)
	@$(RM) $(OBJECTS)

fclean : clean
	@echo ${GREEN}"● Supression des executables et librairies..."$(EOC)
	@$(RM) server client

re : fclean all

.PHONY : all bonus clean fclean re