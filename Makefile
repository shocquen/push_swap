# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 09:28:22 by shocquen          #+#    #+#              #
#    Updated: 2021/11/29 12:54:23 by shocquen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
NAME =		libft.a

SRCS =	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \

SRCS_BNS =	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstadd_back.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \

INC =		libft.h
RM =		rm -rf
AR =		ar -rcs
OBJ =		$(SRCS:.c=.o)
BNS =	$(SRCS_BNS:.c=.o)
CFLAG =	-Wall -Wextra -Werror

all :		$(NAME)

%.o : %.c
			$(CC) $(CFLAG) $(INCFLAGS) -c $< -o $@

$(NAME) :	$(OBJ) $(INC)
			$(AR) $(NAME) $(OBJ)

bonus :	$(OBJ) $(BNS) $(INC)
			$(AR) $(NAME) $(OBJ) $(BNS)

clean :
			$(RM) $(OBJ) $(BNS)

fclean :	clean
			$(RM) $(NAME)

re : 		fclean all

.PHONY : 	all clean fclean re