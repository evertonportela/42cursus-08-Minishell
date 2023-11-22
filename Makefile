# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evportel <evportel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 20:15:50 by evportel          #+#    #+#              #
#    Updated: 2023/11/20 20:51:13 by evportel         ###   ########.fr        #
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

SRC			=	${addprefix src/, main.c} \
				${addprefix src/analyzer/, ft_analyzer_command.c} \
				${addprefix src/executor/, ft_exec_command.c} \
				${addprefix src/utils/, ft_clean_mult_allocations.c} \
				${addprefix src/utils/, ft_get_local_user.c} \
				${addprefix src/utils/, ft_minishell_error.c}

OBJ			=	${SRC:.c=.o}
HEADER		=	-I./
READLINE	=	-lreadline
LIBFT		=	-L ./libft -lft

# RULES MANDATORY ************************************************************ #
%.o: %.c
			@printf "${GREEN}Compilation Step: ${RESET}${notdir $<}\n"
			${CC} ${FLAGS} ${HEADER} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJ} | mylibft
			@printf "${YELLOW}${NAME} - Connection Step - Object creation${RESET}\n"
			${CC} ${FLAGS} -o ${NAME} ${OBJ} ${LIBFT} ${HEADER} ${READLINE}
			@printf "${GREEN}${NAME} - Compiled successfully!${RESET}\n"

mylibft:
			make -j42 -C ./libft/ --no-print-directory

# CLEANING RULES ************************************************************* #
clean:
			@make clean -C ./libft/
			rm -fr ${OBJ}
			@printf "${RED}${NAME} - Removed project objects${RESET}\n"

fclean:		clean
			@make fclean -C ./libft/
			rm -fr ${NAME}
			@printf "${RED}${NAME} - Program removed${RESET}\n"

re:			fclean ${NAME}

# VALGRIND ******************************************************************* #
val:		
			valgrind --leak-check=full ./${NAME}
#			valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes --trace-children-skip='*/bin/*,*/sbin/*' --suppressions=./readline.supp -q ./$(NAME)

.PHONY:		all clean fclean re mylibft val