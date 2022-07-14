# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gopal <gopal@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 00:12:58 by gopal             #+#    #+#              #
#    Updated: 2022/06/16 03:13:15 by gopal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS		=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	\
				ft_isascii.c	ft_isprint.c	ft_strlen.c		\
				ft_memset.c		ft_bzero.c		ft_memcpy.c		\
				ft_memmove.c	ft_toupper.c	ft_tolower.c	\
				ft_toupper.c	ft_tolower.c	ft_strchr.c		\
				ft_strrchr.c	ft_strncmp.c	ft_memchr.c		\
				ft_memcmp.c		ft_strnstr.c	ft_strlcat.c	\
				ft_strlcpy.c 	ft_strdup.c		ft_atoi.c		\
				ft_calloc.c		ft_strcmp.c						\
				ft_substr.c		ft_strjoin.c ft_putchar_fd.c	\
				ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	\
				ft_strtrim.c	ft_split.c		ft_itoa.c		\
				ft_strmapi.c	ft_striteri.c	

SRCS_B		= 	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	\
				ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c	\
				ft_lstclear.c	ft_lstiter.c		ft_lstmap.c		\
				ft_lst_pop.c

HEADER		= -I inc

SRCS_DIR	= src/
OBJS		= $(addprefix $(SRCS_DIR), $(SRCS:%.c=%.o))
OBJS_B		= $(OBJS) $(addprefix $(SRCS_DIR), $(SRCS_B:%.c=%.o))

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g

all:		$(NAME)

$(NAME):	$(OBJS_B)
			@ar rc $(NAME) $?
			@ranlib $(NAME)

%.o		:	%.c 
			gcc $(CFLAGS) $(HEADER) -c $< -o $@

bonus:		$(OBJS_B)
			@ar rcs $(NAME) $(OBJS_B)
			
clean:		
			@rm -f $(OBJS) $(OBJS_B)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
