# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/15 13:25:38 by xamartin          #+#    #+#              #
#    Updated: 2020/04/15 19:00:29 by xamartin         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


.PHONY: all clean fclean re test no
.SECONDEXPANSION:

# VAR
NAME = scop
CC = gcc
RM = rm -f

# PATH
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
LIB_PATH = ./lib/
INC_PATH = ./includes/ $(LIB_PATH)libft/header/ $(LIB_PATH)glfw/include/

# FLAGS
GCC_FLGS = -Wall -Wextra -g3
GCC_LIBS = -lglfw -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo

# TESTS
PY = python3
TESTER = "data/tests/test_code.py"

# FILES
SRC_NAME =	main.c \
			error/handle_error_sdl.c \
			error/handle_error_parser.c \
			parser/reader.c \
			parser/launch_parser.c \
			parser/line_checker/check_obj.c \
			parser/line_checker/check_mtl.c \
			parser/line_checker/line_checker.c \
			parser/line_checker/basic_line_checker.c \
			parser/line_checker/advanced_obj_checker.c \
			parser/object/print_obj.c \
			parser/object/list_parser_to_obj.c \
			parser/object/definitions/parser_v.c \
			parser/object/definitions/parser_f_l_o_g_pass.c \
			parser/material/print_mtl.c \
			parser/material/list_parser_to_mtl.c \
			parser/material/definitions/parse_file.c \
			parser/material/definitions/parser_k.c \
			parser/material/definitions/parse_color.c \
			parser/material/definitions/parser_tf_d_s_ni.c \
			parser/material/definitions/parsing_texture_option.c \
			parser/material/definitions/parser_sharp_bump_decal_illum_pass.c \
			tools/char.c \
			tools/path.c \
			tools/ft_atof.c \
			tools/define_id.c \
			tools/list_parser.c \
			tools/length_parser.c \
			tools/pass_whitespace.c \
			tools/manage_addr.c \
			tools/spec_delete_obj.c \
			tools/details_delete_obj.c \
			tools/optional_argument.c \
			tools/init/init_obj.c \
			tools/init/init_ptr.c \
			tools/init/init_mtl.c \
			tools/init/init_gdata.c \
			tools/init/init_parser.c \
			tools/init/init_parser_option.c \
			tools/init/init_texture_option.c \
			render/launch_render.c \

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft glfw/src

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L$(LIB_PATH),$(LIB_NAME))

#RULES

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)libft -j
	$(CC) $(GCC_FLGS) $(LIB) -lft $(INC) $(OBJ) $(GCC_LIBS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(GCC_FLGS) $(INC) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIB_PATH)libft fclean
	rm -fv $(NAME)

re: fclean all

delete:
	@$(RM) $(OBJ)
	@$(RM) $(NAME)

no: delete all

test:
	@$(PY) $(TESTER)
