# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgregory <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 19:34:04 by cgregory          #+#    #+#              #
#    Updated: 2021/10/20 22:04:43 by cgregory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
HDRDIR		=	./
HEADER		=	$(HDRDIR)libft.h
SRCS		=	ft_bzero.c		ft_calloc.c\
				ft_split.c		ft_strlcpy.c	ft_strlen.c\
				ft_strncmp.c	ft_substr.c		ft_strjoin.c
OBJ			=	$(SRCS:%.c=%.o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
.PHONY		:	all	bonus clean	fclean re
all			:	$(NAME)
$(NAME)		:	$(OBJ) $(HEADER)
				@ar rcs $(NAME) $?
%.o			:	%.c $(HEADER)
				@$(CC) $(CFLAGS) -I$(HDRDIR) -c $< -o $@
clean		:	
				@$(RM) $(OBJ)
fclean		:	clean
				@$(RM) $(NAME)
re			:	fclean all
