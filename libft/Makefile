# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 09:28:22 by shocquen          #+#    #+#              #
#    Updated: 2022/01/05 14:41:06 by shocquen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
NAME =		libft.a

BASE = $(wildcard utils/*.c)
PRINTF = $(wildcard ft_printf/*.c)
GNL = $(wildcard get_next_line/*.c)

SRCS =	$(BASE) $(PRINTF) $(GNL)

INC =		../includes
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