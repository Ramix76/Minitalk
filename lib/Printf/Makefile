# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 12:04:32 by framos-p          #+#    #+#              #
#    Updated: 2022/11/07 14:02:34 by framos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

INCLUDE	=	includes
SRCS_DIR =   srcs/
OBJS_DIR	=	objs/
CC      =   gcc
CFLAGS  =   -g -Wall -Wextra -Werror -I
RM      =   rm -f
AR		=	ar rcs

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRCS_FILES	=	ft_printf ft_functions_types ft_lower_upper ft_put_functions ft_unsigned_itoa 
SRCS 		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS 		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
DEPS		=	$(addprefix $(OBJS_DIR), $(addsuffix .d, $(SRCS_FILES)))
OBJF		=	.cache_exists

all:
	@${MAKE} ${NAME}


-include ${DEPS}
${NAME}:${OBJS} ${INCLUDE}/ft_printf.h
	${AR} ${NAME} ${OBJS}
	@echo "$(GREEN)libprintf compiled!$(DEF_COLOR)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJF)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

${OBJF}:
	@mkdir -p ${OBJS_DIR}

clean:
	@$(RM) -rf $(OBJS_DIR)
	@echo "$(BLUE)libprintf objects files cleaned!$(DEF_COLOR)"

fclean:	clean
	@$(RM) -f $(NAME)
	@echo "$(CYAN)libprintf executable files cleaned!$(DEF_COLOR)"

re:	fclean 
	@$(MAKE)
	@echo "$(GREEN)Cleaned and rebuilt everything for libprintf!$(DEF_COLOR)"

norm:
	@norminette ${SRCS} ${INCLUDE} | grep -v Norme -B1 || true;

.PHONY: fclean, all, clean, re
