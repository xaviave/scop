# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/19 14:20:54 by xamartin          #+#    #+#              #
#    Updated: 2020/06/24 13:09:35 by xamartin         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =\
	ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_islower\
	ft_isprint ft_isupper ft_itoa ft_lstadd ft_lstdel ft_lstdelone ft_lstiter\
	ft_lstmap ft_lstnew ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy\
	ft_memdel ft_memmove ft_memset ft_putchar ft_putchar_fd ft_putendl\
	ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_strcat\
	ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strdup ft_strequ\
	ft_striter ft_striteri ft_strjoin ft_strlcat ft_strlen ft_strmap ft_strmapi\
	ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew ft_strnstr ft_strrchr\
	ft_strrev ft_strsplit ft_strstr ft_strsub ft_strtolower ft_strtoupper\
	ft_strtrim ft_swap ft_tolower ft_toupper ft_lstpush ft_lstlen ft_del\
	ft_bubble_sort ft_merge_sort ft_strnjoin \
	get_next_line ft_atol ft_pow ft_strisdigit ft_strndup

SRCS = $(addprefix libft_files/, $(addsuffix .c, $(SRC)))

LIB_OBJ = $(addprefix libft_files/, $(addsuffix .o, $(SRC)))

CC = gcc

FLAGS = -Wall -Wextra -Werror -O2

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB_OBJ)
	@ar rcs $(NAME) $(LIB_OBJ)
	@echo "\033[32mLibft created.\033[0m"

./libft_files/%.o: ./libft_files/%.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@/bin/rm -f $(LIB_OBJ)
	@echo "\033[31mLibft objects deleted.\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[31mLibft binary deleted.\033[0m"

re: fclean all
