# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 17:42:40 by preed             #+#    #+#              #
#    Updated: 2022/07/19 15:19:19 by lgarrosh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

# for mac
# RL_DIR		= /Users/$(USER)/.brew/Cellar/readline/8.1.?

# for ubuntu
RL_DIR		= /usr/local/readline/8.1

CC			= cc
# for mac
# CFLAGS		= -Wall -Wextra -Werror -I $(RL_DIR)/include/
# FLAGS		=  $(CFLAGS) -lreadline -L $(RL_DIR)/lib/

# for ubuntu
CFLAGS		= -Wall -Wextra -Werror -I $(RL_DIR)/include/
FLAGS		=  $(CFLAGS) -lreadline -L $(RL_DIR)/lib/

LIBFT		= libft/libft.a
PIPEX		= pipex/pipex.a
INC			= includes/
HEADER		= minishell.h struct.h
HEADERS		= $(addprefix $(INC), $(HEADER))

LIB_DIR		= libft/
PIP_DIR		= pipex/
SRC_D		= src/
OBJ_D		= obj/

SRC_F 		=	$(addprefix src/main/, $(MAIN)) \
				$(addprefix src/env/, $(ENV)) \
				$(addprefix src/execution/, $(EXEC)) \
				$(addprefix src/tools/, $(TOOLS)) \

MAIN		= main.c

ENV			= env.c env_oper.c

EXEC		= executive.c

TOOLS		= free.c error.c ft_readline.c

OBJ_F 		=	$(subst $(SRC_D),$(OBJ_D),$(SRC_F:%.c=%.o)) 

$(OBJ_D)%.o: $(SRC_D)%.c
	$(CC) $(CFLAGS) -c $< -o $@  -I$(INC) -I$(LIB_DIR)$(INC) -I$(PIP_DIR)$(INC) 

.PHONY: all clean fclean re

all: makelib $(NAME)

$(OBJ_D):
		@mkdir -p $@
		@mkdir -p $(addprefix $@/, main env execution tools)

$(NAME): $(OBJ_D) $(OBJ_F) $(LIBFT) $(PIPEX) $(HEADERS) Makefile
	$(CC) $(FLAGS) $(OBJ_F) -o $(NAME) $(LIBFT) $(PIPEX) -I$(INC)

makelib:
	@make -C $(LIB_DIR) bonus --no-print-directory
	@make -C $(PIP_DIR) --no-print-directory

clean:
	@make -C $(LIB_DIR) clean --no-print-directory
	@make -C $(PIP_DIR) clean --no-print-directory
	rm -rfv $(OBJ_D)

fclean: clean
	@make -C $(LIB_DIR) fclean --no-print-directory
	@make -C $(PIP_DIR) fclean --no-print-directory
	rm -rfv $(NAME)

re: fclean all
