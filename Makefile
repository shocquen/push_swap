# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 09:28:22 by shocquen          #+#    #+#              #
#    Updated: 2022/01/18 18:15:42 by shocquen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define sign
	@clear
	@tput setaf 1
	@tput bold

	@sleep .1
	@echo "$(shell tput cup 0 0)..%%%%...%%..%%...%%%%....%%%%....%%%%%...%%%%...%%%%%%..%%..%%."	
	@sleep .2

	@echo "$(shell tput cup 0 0).....%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%......%%..%%."
	@echo "$(shell tput cup 1 0)..%%%%...%%..%%...%%%%....%%%%....%%%%%...%%%%...%%%%%%..%%..%%."	
	@sleep .15

	@echo "$(shell tput cup 0 0)..%%%%...%%%%%%..%%..%%..%%......%%.%%%..%%..%%..%%%%....%%.%%%."
	@echo "$(shell tput cup 1 0).....%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%......%%..%%."
	@echo "$(shell tput cup 2 0)..%%%%...%%..%%...%%%%....%%%%....%%%%%...%%%%...%%%%%%..%%..%%."	
	@sleep .2

	@echo "$(shell tput cup 0 0).%%......%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%......%%%.%%."
	@echo "$(shell tput cup 1 0)..%%%%...%%%%%%..%%..%%..%%......%%.%%%..%%..%%..%%%%....%%.%%%."
	@echo "$(shell tput cup 2 0).....%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%......%%..%%."
	@echo "$(shell tput cup 3 0)..%%%%...%%..%%...%%%%....%%%%....%%%%%...%%%%...%%%%%%..%%..%%."	
	@sleep .2

	@echo "$(shell tput cup 0 0)..%%%%...%%..%%...%%%%....%%%%....%%%%...%%..%%..%%%%%%..%%..%%."
	@echo "$(shell tput cup 1 0).%%......%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%......%%%.%%."
	@echo "$(shell tput cup 2 0)..%%%%...%%%%%%..%%..%%..%%......%%.%%%..%%..%%..%%%%....%%.%%%."
	@echo "$(shell tput cup 3 0).....%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%......%%..%%."
	@echo "$(shell tput cup 4 0)..%%%%...%%..%%...%%%%....%%%%....%%%%%...%%%%...%%%%%%..%%..%%."	
	@sleep .1

	@tput sgr0
endef

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
	sort_5.c \
	sort_4.c \
	sort_100.c \
	show.c \
	gets.c

OBJS		= $(SRCS:.c=.o)

INC		= ./includes

LIBS	=	./libft/libft.a

NAME		= push_swap
RM			= rm -f
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

${NAME}:	signe $(addprefix obj/, $(OBJS))
			$(call building,libft)
			$(call finishing,$(NAME))
			@echo "Use $(shell tput setaf 7)./push_swap <args...>$(shell tput sgr0)"

obj/%.o: src/%.c
			@mkdir -p $(@D)
			$(call compiling,$<,$@,0)


all:	$(NAME)

clean:	
			$(call cleaning,libft,clean)
			$(call removing,$(addprefix obj/, $(OBJS)))

fclean:		clean
			$(call cleaning,libft,fclean)
			$(call removing,$(NAME))

re:			fclean all

signe:
			$(call sign)
			@echo

.PHONY : 	all clean fclean re signe
