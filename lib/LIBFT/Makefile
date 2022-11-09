# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 14:24:13 by framos-p          #+#    #+#              #
#    Updated: 2022/11/07 14:03:41 by framos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_strchr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strlen.c \
				ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strdup.c \
				ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_calloc.c ft_memchr.c \
				ft_memcmp.c ft_strnstr.c ft_atoi.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c\
				 
OBJS		=	$(SRCS:%.c=%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

# Colors

NO_COLOR	=	\033[0m
DEF_COLOR 	= \033[0;39m
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m


%.o: %.c
		@${CC} ${CFLAGS} -I./ -c $< -o $@
		#@printf "\r                                                                           "
		@printf "\r🔧 $(GRAY)${CC} ${CFLAGS} -I./ -c $< -o $@$(DEF_COLOR)"

all: 
	@echo "🎯 $(YELLOW)Starting $(WHITE)[${NAME}] $(YELLOW)compilation..$(DEF_COLOR)"
	@Make ${NAME}
	@echo "\n🔰 $(GREEN)${NAME} done!\n$(DEF_COLOR)"

${NAME}:${OBJS} libft.h Makefile
		@ar -crs ${NAME} ${OBJS} 
		@echo "\n🔗 $(CYAN) ar -crs ${NAME} ${OBJS}$(DEF_COLOR)"
		
clean:
		@${RM} ${OBJS}
		@echo "$(MAGENTA)🚽 Cleaned ${NAME}$(DEF_COLOR)"

fclean:	clean
		@${RM} ${NAME} 
		@echo "$(MAGENTA)🚽 Cleaned ${NAME}$(DEF_COLOR)"
re:		fclean all

.PHONY: fclean, all, clean, re
