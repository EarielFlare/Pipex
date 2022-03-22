# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 18:51:58 by cgregory          #+#    #+#              #
#    Updated: 2022/03/18 20:02:47 by cgregory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
NAME_BONUS		=	./src_bonus/pipex_bonus
LIBFT_DIR		=	./libft/
LIBFT_NAME		=	$(LIBFT_DIR)libft.a

SRC_MAIN_DIR	=	./src_main/
SRC_MAIN		=	main.c		errors.c	childs.c	free.c
OBJ_MAIN		=	$(addprefix $(SRC_MAIN_DIR), $(SRC_MAIN:%.c=%.o))

SRC_BONUS_DIR	=	./src_bonus/
SRC_BONUS		=	main.c		errors.c	childs.c	free.c\
					files.c		here_doc.c	get_next_line.c
OBJ_BONUS		=	$(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS:%.c=%.o))

HDR_DIR			=	./inc/
HDR_MAIN		=	pipex.h		pipex_bonus.h
HDR				=	$(addprefix $(HDR_DIR), $(HDR_MAIN))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
NOPR			=	--no-print-directory -C
RM				=	rm -rf
.PHONY			:	all clean fclean re bonus
all				:	$(LIBFT_NAME) $(NAME)
bonus			:	$(LIBFT_NAME) $(NAME_BONUS)
$(LIBFT_NAME)	:	
					@make $(NOPR) $(LIBFT_DIR)
$(NAME)			:	$(OBJ_MAIN) $(LIBFT_NAME) $(HDR)
					@$(RM) $(OBJ_BONUS)
					@$(CC) $(OBJ_MAIN) $(LIBFT_NAME) -o $(NAME)
					@echo "$(BLUE)$(NAME) created!$(DEFAULT)"
$(NAME_BONUS)	:	$(OBJ_BONUS) $(LIBFT_NAME) $(HDR)
					@$(RM) $(OBJ_MAIN)
					@$(CC) $(OBJ_BONUS) $(LIBFT_NAME) -o $(NAME)
					@touch $(NAME_BONUS)
					@echo "$(BLUE)$(NAME) created!$(DEFAULT)"
%.o:				%.c $(HDR) Makefile
					@$(CC) $(CFLAGS) -I$(HDR_DIR) -I$(LIBFT_DIR) -c $< -o $@
clean			:	
					@$(RM) $(OBJ_MAIN)
					@$(RM) $(OBJ_FUNC)
					@$(RM) $(OBJ_BONUS)
					@make clean $(NOPR) $(LIBFT_DIR)
					@echo "$(YELLOW)object files deleted!$(DEFAULT)"
fclean			:	clean
					@$(RM) $(NAME)
					@$(RM) $(NAME_BONUS)
					@make fclean $(NOPR) $(LIBFT_DIR)
					@echo "$(RED)all files deleted!$(DEFAULT)"
re				:	fclean all

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
DEFAULT = \033[0m
