# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evportel <evportel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 10:41:40 by evportel          #+#    #+#              #
#    Updated: 2023/11/12 17:29:41 by evportel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS ********************************************************************* #
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
RESET	=	\033[0m

SOURCES			= ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c\
				ft_isprint.c	ft_memset.c		ft_strlen.c		ft_bzero.c\
				ft_memcpy.c		ft_memmove.c	ft_strlcpy.c	ft_strlcat.c\
				ft_toupper.c	ft_tolower.c	ft_strchr.c		ft_strrchr.c\
				ft_strncmp.c	ft_memchr.c		ft_memcmp.c		ft_strnstr.c\
				ft_atoi.c		ft_calloc.c		ft_strdup.c		ft_substr.c\
				ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_itoa.c\
				ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c\
				ft_strtok.c		ft_strpbrk.c \
				ft_lstnew_bonus.c			ft_lstadd_front_bonus.c\
				ft_lstsize_bonus.c			ft_lstlast_bonus.c\
				ft_lstadd_back_bonus.c		ft_putendl_fd.c	ft_putnbr_fd.c\
				ft_printf.c					ft_printf_utils_1.c\
				ft_printf_utils_2.c\

OBJECTS			= $(SOURCES:%.c=%.o)


OBJECTS_BONUS	= $(SOURCES_BONUS:%.c=%.o)

NAME			= libft.a
CC				= cc
FLAGS			= -Wall -Wextra -Werror
RM				= rm -f

# MAKE
all:			$(NAME)

$(NAME):		$(OBJECTS)
				ar -rcs $(NAME) $(OBJECTS)

%.o:			%.c
				@$(CC) $(FLAGS) -I ./ -c $< -o $@

clean:
				$(RM) $(OBJECTS)
				@printf "${RED}${NAME} - Removed project objects${RESET}\n"

fclean:			clean
				@$(RM) $(NAME)
				@printf "${RED}${NAME} - Program removed${RESET}\n"

re: fclean all

.PHONY: re fclean clean all
