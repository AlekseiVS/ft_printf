# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 13:39:43 by osokoliu          #+#    #+#              #
#    Updated: 2018/03/17 18:01:45 by osokoliu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILE_C = ft_printf.c ft_search_1.c ft_search.c ft_print_c.c ft_print_s.c \
ft_strlen.c ft_strchr.c ft_strsub.c ft_isdigit.c ft_itoa.c \
ft_atoi.c ft_strdup.c ft_strnew.c \
ft_memalloc.c ft_bzero.c ft_left_right.c \
ft_print_d_i.c ft_initialization.c ft_itoa_base.c ft_print_u.c \
ft_print_d_i_2.c ft_print_u_2.c ft_print_o.c ft_print_o_2.c \
ft_print_x_p.c ft_print_x_p_2.c ft_strjoin.c ft_toupper.c \
ft_string_formation_p.c ft_print_c_s.c ft_putstr.c ft_strdel.c \
ft_memdel.c ft_print_d_i_3.c ft_print_x_p_3.c

FILE_O = $(FILE_C:.c=.o)

GCC = gcc -Wall -Wextra -Werror -c -o

all: $(NAME)

$(NAME): $(FILE_O)
	ar rc $(NAME) $(FILE_O)

%.o: %.c
	$(GCC) $@ $<

clean:
	rm -f $(FILE_O)

fclean: clean
	rm -f $(NAME)

re: fclean all