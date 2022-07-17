# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 20:16:46 by preed             #+#    #+#              #
#    Updated: 2022/06/15 14:45:50 by lgarrosh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = libft.a

HEADER = libft.h
INC = includes/
SRCS_DIR = src/
OBJS_DIR = obj/

SRCS =	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c \
		ft_isascii.c	ft_isprint.c	ft_strlen.c \
		ft_memset.c		ft_bzero.c		ft_memcpy.c \
		ft_memmove.c	ft_strlcpy.c	ft_toupper.c \
		ft_tolower.c	ft_strchr.c		ft_strrchr.c \
		ft_strncmp.c	ft_memchr.c		ft_memcmp.c \
		ft_strnstr.c	ft_atoi.c		ft_calloc.c \
		ft_strdup.c		ft_strlcat.c \
		ft_substr.c		ft_strjoin.c	ft_strtrim.c \
		ft_split.c		ft_itoa.c		ft_strmapi.c \
		ft_striteri.c	ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c \

SRCS_B =	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c \
			ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c \
			ft_lstclear.c	ft_lstiter.c		ft_lstmap.c \

OBJS = $(addprefix $(OBJS_DIR),$(SRCS:%.c=%.o))

OBJS_B =  $(addprefix $(OBJS_DIR),$(SRCS_B:%.c=%.o))

CC = cc

RM = rm -rvf

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(INC)

$(NAME): $(OBJS_DIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: all
	@make OBJS="$(OBJS_B)" all

clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
