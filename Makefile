# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 09:28:22 by shocquen          #+#    #+#              #
#    Updated: 2021/12/18 13:00:49 by shocquen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
NAME =		libft.a

BASE = $(wildcard base/*.c)
PRINTF = $(wildcard ft_printf/*.c)

SRCS =	$(BASE) $(PRINTF)

INC =		includes
RM =		rm -rf
AR =		ar -rcs
OBJ =		$(SRCS:.c=.o)
CFLAG =	-Wall -Wextra -Werror

all :		$(NAME)

%.o : %.c
			$(CC) $(CFLAG) -I $(INC) -c $< -o $@

$(NAME) :	$(OBJ)
			$(AR) $(NAME) $(OBJ)

clean :
			$(RM) $(OBJ)

fclean :	clean
			$(RM) $(NAME)

re : 		fclean all

.PHONY : 	all clean fclean re