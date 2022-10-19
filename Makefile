# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 16:46:08 by framos-p          #+#    #+#              #
#    Updated: 2022/10/19 14:43:40 by framos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER				=	server
CLIENT				=	client
CLIENT_BONUS		=	client_bonus
SERVER_BONUS		=	server_bonus

MyLib_DIR			=	lib/LIBFT
MyLib				=	$(MyLib_DIR)/libft.a
MyPrintf_DIR		=	lib/Printf
MyPrintf			=	$(MyPrintf_DIR)/libftprintf.a

SRCS				=	srcs/

CLIENT_SRCS			=	$(SRCS)client.c
CLIENT_OBJS			=	$(SRCS)client.o

SERVER_SRCS			=	$(SRCS)server.c
SERVER_OBJS			=	$(SRCS)server.o

CLIENT_BONUS_SRCS	=	$(SRCS)client_bonus.c
CLIENT_BONUS_OBJS	=	$(SRCS)client_bonus.o

SERVER_BONUS_SRCS	=	$(SRCS)server_bonus.c
SERVER_BONUS_OBJS	=	$(SRCS)server_bonus.o

CC				=	gcc
FLAGS			=	-g -Wall -Wextra -Werror
RM 				=	rm -rf

# Colors

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
RED 		=	\033[0;91m
YELLOW 		=	\033[0;93m
BLUE 		=	\033[0;94m


$(SRCS)%.o: $(SRCS)%.c Makefile
	$(CC) $(FLAGS) -c $< -o $@

all:
	@$(MAKE) -sC $(MyLib_DIR)
	@$(MAKE) -sC $(MyPrintf_DIR)
	@$(MAKE) $(SERVER)
	@$(MAKE) $(CLIENT)

bonus:
	@$(MAKE) -sC $(MyLib_DIR)
	@$(MAKE) -sC $(MyPrintf_DIR)
	@$(MAKE) $(SERVER_BONUS)
	@$(MAKE) $(CLIENT_BONUS)

$(SERVER):: $(SERVER_OBJS)
	@$(CC) $(FLAGS) $(SERVER_OBJS) $(MyLib) $(MyPrintf) -o $(SERVER)
	@echo "\n📥 $(BOLD_CYAN)Server ready!\n"

$(SERVER)::
	@echo "\n\t$(RED)$@ is up to date"

$(CLIENT):: $(CLIENT_OBJS)
	@$(CC) $(FLAGS) $(CLIENT_OBJS) $(MyLib) $(MyPrintf) -o $(CLIENT)
	@echo "\n📟 $(BOLD_PURPLE)Client ready!\n"

$(CLIENT)::
	@echo "\n\t$(RED)$@ is up to date"

$(SERVER_BONUS):: $(SERVER_BONUS_OBJS)
	@$(CC) $(FLAGS) $(SERVER_BONUS_OBJS) $(MyLib) $(MyPrintf) -o $(SERVER_BONUS)
	@echo "\n📥 $(BOLD_CYAN)Server_Bonus ready!\n"

$(CLIENT_BONUS):: $(CLIENT_BONUS_OBJS)
	@$(CC) $(FLAGS) $(CLIENT_BONUS_OBJS) $(MyLib) $(MyPrintf) -o $(CLIENT_BONUS)
	@echo "\n📥 $(BOLD_CYAN)Client_Bonus ready!\n"

$(SERVER_BONUS)::
	@echo "\n\t$(YELLOW)$@ is up to date"

$(CLIENT_BONUS)::
	@echo "\n\t$(YELLOW)$@ is up to date"

clean:
	@${RM} $(SERVER_OBJS) $(CLIENT_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)
	@make clean -sC $(MyLib_DIR) 
	@make clean -sC $(MyPrintf_DIR)
	@echo "\n💧 $(YELLOW)Clean: $(RED)Removed all the \".o\" files \n"

fclean: clean
	@$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@make fclean -sC $(MyLib_DIR) 
	@make fclean -sC $(MyPrintf_DIR)
	@echo "\n🧼 $(YELLOW)Fclean: $(BLUE)Removed the executables \n"

re:	fclean all

.PHONY: all clean fclean re bonus
