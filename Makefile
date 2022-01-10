# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 09:28:22 by shocquen          #+#    #+#              #
#    Updated: 2022/01/10 17:03:35 by shocquen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define building
	@echo "$(shell tput setaf 6)Building $1 $(shell tput sgr0)\c"
	@make -C $1 > /dev/null 2> /dev/null
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define compiling
	@echo "$(shell tput bold)$(shell tput setaf 3)Compiling $1 $(shell tput sgr0)\c"
	@$(CC) $(CFLAGS) -I$(INC) -c $1 -o $2
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define finishing
	@echo "$(shell tput bold)$(shell tput setaf 2)Compiling $1 $(shell tput sgr0)\c"
	@$(CC) $(CFLAGS) $(addprefix obj/, $(OBJS)) $(LIBS) -I$(INC) -o $(NAME)
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define cleaning
	@echo "$(shell tput bold)$(shell tput setaf 8)Cleaning $1 $(shell tput sgr0)\c"
	@make $2 -sC $1 > /dev/null
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define removing
	@echo "$(shell tput bold)$(shell tput setaf 8)Removing $1 $(shell tput sgr0)\c"
	@$(RM) $1  > /dev/null 
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

SRCS		= actions.c \
	push_swap.c \
	checks.c \
	sort.c \
	sort_3.c \
	sort_5.c

OBJS		= $(SRCS:.c=.o)

INC		= ./includes

LIBS	=	./libft/libft.a

NAME		= push_swap
RM			= rm -f
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

${NAME}:	$(addprefix obj/, $(OBJS))
			$(call building,libft)
			$(call finishing,$(NAME))

obj/%.o: src/%.c
			@mkdir -p $(@D)
			$(call compiling,$<,$@,0)


all:		$(NAME)

clean:	
			$(call cleaning,libft,clean)
			$(call removing,$(addprefix obj/, $(OBJS)))

fclean:		clean
			$(call cleaning,libft,fclean)
			$(call removing,$(NAME))

re:			fclean all

.PHONY : 	all clean fclean re
