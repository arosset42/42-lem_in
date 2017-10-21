# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arosset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/23 14:08:14 by arosset           #+#    #+#              #
#    Updated: 2017/06/23 14:08:17 by arosset          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME			= 	lem-in

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror -g

LIB_PATH		= 	./libft/
LIB				=	./libft/libft.a
LIB_LINK		=	./libft/libft.a

INC_PATH		= 	./includes
SRC_PATH		=	./src
SRC_NAME 		= 	main_lem_in.c error.c  ft_list_lem_in.c parser.c \
					ft_utility.c init.c ft_check.c ft_search.c\
					ft_free.c ft_graph.c ft_search_list.c ft_algo.c\
					ft_print.c ft_print_ant.c 
OBJ_PATH		=	./obj

OBJ_NAME		=	$(SRC_NAME:.c=.o)
INC_NAME		=	lem_in.h

OBJ 			= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

# COLORS
RESET			=	"\033[00m"
RED				=	"\033[31m"
GREEN			=	"\033[32m"
YELLOW			=	"\033[33m"
BLUE			= 	"\033[34m"
PURPLE			=	"\033[35m"

# MESSAGE
SUCCESS			=	$(GREEN)SUCCESS$(RESET)
OK				=	$(PURPLE)OK$(RESET)
DELETE			=	$(RED)DELETE$(RESET)
DELETE_LIB		=	$(RED)DELETE LIB$(RESET)
TEST 			= 	$(YELLOW)DEBUT TEST$(RESET)


all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(LIB_LINK) $(FLAGS) $(OBJ)  -o $@
	@echo "Exec =>"$(YELLOW) $(NAME) $(RESET): $(SUCCESS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<
	@echo "Obj" [ $< ] $(OK)


$(LIB):
	@make -C $(LIB_PATH)

clean:
	@rm -rf $(OBJ) $(OBJ_PATH)
	@echo $(DELETE) : $(OBJ) $(OBJ_PATH)
	@make -C $(LIB_PATH) clean
	@echo $(DELETE_LIB) : Obj Libft
	#@make -C $(LIB_MLX) clean
	#@echo $(DELETE_LIB) : Obj MLX


fclean: clean
	@rm -rf $(NAME)
	@echo $(DELETE) : $(NAME)
	#@make -C $(LIB_PATH) fclean
	#@echo $(DELETE_LIB) : Lib

re: fclean all
