NAME		=	pipex.a
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

HEADER_SRCS	=	pipex_bonus.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

BPATH_SRCS	=	pipex_bonus.c error_bonus.c here_doc_bonus.c\
				files_bonus.c free_bonus.c child_bonus.c
BPATH_DIR	=	bonus/
BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS))
OBJ_B		=	$(BPATH:.c=.o)

FUNC_SRCS	=	ft_strncmp.c ft_strdup.c ft_split.c ft_strjoin.c
FUNC_DIR	=	functions/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))\
				gnl/get_next_line_utils.c gnl/get_next_line.c
OBJ_F		=	$(FUNC:.c=.o)

%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@ -I$(HEADER_DIR)

all:			$(NAME)

$(NAME):		$(OBJ_F) $(OBJ_B)
				ar rcs $(NAME) $(OBJ_F) $(OBJ_B)

clean:
				$(RM) $(OBJ_F)
				$(RM) $(OBJ_B)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean bonus re
