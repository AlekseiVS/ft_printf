#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 13:39:43 by osokoliu          #+#    #+#              #
#    Updated: 2017/12/05 17:41:10 by osokoliu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

FILE_C = ft_printf.c ft_search.1.1.c ft_search.2.c ft_print_c.c ft_print_s.c \
ft_strlen.c ft_strchr.c ft_strsub.c ft_isdigit.c ft_itoa.c \
ft_atoi.c ft_abs.c ft_strdup.c ft_strnew.c \
ft_memalloc.c ft_bzero.c ft_left_right.c \
ft_print_d_i_D.c ft_initialization.c ft_itoa_base.c ft_print_u_U.c \
ft_print_d_i_D_2.c ft_print_u_U_2.c ft_print_o_O.c ft_print_o_O_2.c \
ft_print_x_X_p.c ft_print_x_X_p_2.c ft_strjoin.c ft_toupper.c \
ft_string_formation_p.c ft_print_C_S.c ft_putstr.c ft_strdel.c \
ft_memdel.c

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