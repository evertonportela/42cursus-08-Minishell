# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evportel <evportel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 20:15:50 by evportel          #+#    #+#              #
#    Updated: 2023/11/05 22:06:42 by evportel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS ********************************************************************* #
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
RESET	=	\033[0m

# FLAGS MANDATORY ************************************************************ #
NAME		=	minishell
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror -g3

SRC			=	main.c

OBJ			=	${SRC:.c=.o}
HEADER		=	-I./
READLINE	=	-lreadline
# LIBFT		=	-L ./libft -lft

# RULES MANDATORY ************************************************************ #
%.o: %.c
			@printf "${GREEN}Compilation Step: ${RESET}${notdir $<}\n"
			${CC} ${FLAGS} -c $< -o $@ ${HEADER}

all:		${NAME}

${NAME}:	${OBJ}
			@printf "${YELLOW}${NAME} - Connection Step - Object creation${RESET}\n"
			${CC} ${FLAGS} -o ${NAME} ${OBJ} ${HEADER} ${READLINE}
			@printf "${GREEN}${NAME} - Compiled successfully!${RESET}\n"

# CLEANING RULES ************************************************************* #
clean:
			rm -fr ${OBJ}
			@printf "${RED}${NAME} - Removed project objects${RESET}\n"

fclean:		clean
			rm -fr ${OBJ}
			@printf "${RED}${NAME} - Program removed${RESET}\n"

re:			fclean ${NAME}

.PHONY:		all clean fclean re ${NAME}