# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 09:28:22 by shocquen          #+#    #+#              #
#    Updated: 2022/01/05 16:11:26 by shocquen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define building
	@echo "$(shell tput setaf 6)Building $1 $(shell tput sgr0)"
	@make -C $1 > /dev/null 2> /dev/null
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define compiling
	@echo "$(shell tput bold)$(shell tput setaf 3)Compiling $1 $(shell tput sgr0)"
	@$(CC) $(CFLAGS) -I$(INC) -c $1 -o $2
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define finishing
	@echo "$(shell tput bold)$(shell tput setaf 2)Compiling $1 $(shell tput sgr0)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -I$(INC) -o $(NAME)
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define cleaning
	@echo "$(shell tput bold)$(shell tput setaf 8)Cleaning $1 $(shell tput sgr0)"
	@make $2 -sC $1 > /dev/null
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define removing
	@echo "$(shell tput bold)$(shell tput setaf 8)Removing $1 $(shell tput sgr0)"
	@$(RM) $1 > /dev/null
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

SRCS		= $(wildcard src/*.c)

OBJS		= $(SRCS:.c=.o)

INC		= ./includes

LIBS	=	./libft/libft.a

NAME		= push_swap
RM			= rm -f
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

%.o : %.c
			$(call compiling,$<,$(<:.c=.o),0)

${NAME}:	$(OBJS)
			$(call building,libft)
			$(call finishing,$(NAME))

all:		$(NAME)

clean:	
			$(call cleaning,libft,clean)
			$(call removing,$(OBJS))

fclean:		clean
			$(call cleaning,libft,fclean)
			$(call removing,push_swap)

re:			fclean all
