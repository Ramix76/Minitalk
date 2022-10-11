# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 16:46:08 by framos-p          #+#    #+#              #
#    Updated: 2022/10/11 14:48:31 by framos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER			=	srcs/server.c

CLIENT			=	srcs/client.c

MyLib_DIR		=	lib/LIBFT
MyLib			=	$(MyLib_DIR)/libft.a
MyPrintf_DIR	=	lib/Printf
MyPrintf		=	$(MyPrintf_DIR)/libftprintf.a

OBJS_DIR		=	objs/
CLIENT_SRCS		=	$(CLIENT)
CLIENT_OBJS		=	$(CLIENT_SRCS:.c=.o)
SERVER_SRCS		=	$(SERVER)
SERVER_OBJS		=	$(SERVER_SRCS:.c=.o)
OBJS			=	$(CLIENT_OBJS) $(SERVER_OBJS)
CC				=	gcc
CFLAGS			=	-g -Wall -Wextra -Werror
RM 				=	rm -rf
AR				=	ar rcs

SERVER_NAME		=	server
CLIENT_NAME		=	client

# Colors

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
RED 		=	\033[0;91m
YELLOW 		=	\033[0;93m
BLUE 		=	\033[0;94m


%.o:%.c
	$({CC) $(FLAGS) -c $< -o $@

all: server client

LIBFT:
	@make -sC $(MyLib_DIR)

PRINTF:
	@make -sC $(MyPrintf_DIR)

server: LIBFT PRINTF $(SERVER_OBJS)
	@$(CC) $(FLAGS) $(SERVER) $(MyLib) $(MyPrintf) -o $(SERVER_NAME)
	@echo "\n📥 $(BOLD_CYAN)Server ready!\n"

client: LIBFT PRINTF $(CLIENT_OBJS)
	#@$(CC) $(FLAGS) $(CLIENT_OBJS) $(MyLib) $(MyPrintf) -o $(CLIENT_NAME)
	@echo "\n📟 $(BOLD_PURPLE)Client ready!\n"

clean:
	@${RM} $(OBJS)
	@make clean -sC $(MyLib_DIR) 
	@make clean -sC $(MyPrintf_DIR)
	@echo "\n💧 $(YELLOW)Clean: $(RED)Removed all the \".o\" files \n"

fclean: clean
	@$(RM) $(SERVER_NAME) $(CLIENT_NAME)
	@make fclean -sC $(MyLib_DIR) 
	@make fclean -sC $(MyPrintf_DIR)
	@echo "\n🧼 $(YELLOW)Fclean: $(BLUE)Removed the executables \n"

re:	fclean all

.PHONY: all clean fclean re
