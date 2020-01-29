# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 11:30:42 by jpoulvel          #+#    #+#              #
#    Updated: 2020/01/28 19:10:33 by jpoulvel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	free_list.c \
	   free_tab.c \
	   ft_bzero.c \
	   ft_sqrt.c \
	   ft_itoa.c \
	   ft_lstadd.c \
	   ft_lstnew.c \
	   ft_memcpy.c \
	   ft_putchar.c \
	   ft_putchar_fd.c \
	   ft_putendl.c \
	   ft_putendl_fd.c \
	   ft_putstr.c \
	   ft_putstr_fd.c \
	   ft_strchr.c \
	   ft_strcpy.c \
	   ft_strdel.c \
	   ft_strdup.c \
	   ft_strjoin.c \
	   ft_strlen.c \
	   ft_strnew.c \
	   ft_strsub.c \
	   ft_countwords.c \
	   get_next_line.c \
	   ft_abs.c \

OBJ = $(SRCS:.c=.o)

INCL = libft.h

FLAGS = -Wall -Wextra -Werror -I $(INCL)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	@gcc -c $(FLAGS) $< -o $@

clean: 
	@rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
