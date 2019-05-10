# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcase <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 11:31:10 by tcase             #+#    #+#              #
#    Updated: 2019/05/10 14:17:46 by tcase            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc
FLAGS= -Wall -Werror -Wextra

SRC_DIR=./src
LIB_DIR=./libft
INC_DIR=./includes
OBJ_DIR =./obj

SRC_NAME=ft_printf.c ft_parse_format.c ft_print_result.c \
		 ft_print_string.c ft_printf_digit.c ft_printf_unsigned_number.c \
		 ft_printf_signed_number.c
LIB_NAME=ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
		 ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
		 ft_lstnew.c ft_memalloc.c ft_memccpy.c \
		 ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
		 ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
		 ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
		 ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c \
		 ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
		 ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
		 ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
		 ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
		 ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
		 ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
		 ft_toupper.c ft_lstdelone.c ft_lstdel.c \
		 ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstsize.c \
		 ft_strclen.c ft_nbrlen.c ft_strtoupper.c ft_swap.c \
		 ft_putwchar.c

INC_NAME=ft_printf.h
OBJ_NAME=$(SRC_NAME:.c=.o)
LBO_NAME=$(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_DIR)/, $(LIB_NAME))
INC = $(addprefix $(INC_DIR)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
LBO = $(addprefix $(OBJ_DIR)/, $(LBO_NAME))

all: $(NAME)

$(NAME) : $(OBJ) $(LBO)
	ar rc $(NAME) $(OBJ) $(LBO)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -o $@ -c $<

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	$(CC) -o $@ -c $<

clean:
		rm -f $(OBJ) $(LBO) 

fclean: clean
		rm -f $(NAME)

test: all
	gcc -o test main.c $(NAME) $(FLAGS)  && ./test

vtest: all
	gcc -o test main.c $(NAME) $(FLAGS)  && valgrind ./test

norme:
	norminette $(SRC) $(LIB) $(INC)

re:	fclean all
