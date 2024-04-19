# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 15:50:24 by nholbroo          #+#    #+#              #
#    Updated: 2024/04/19 13:30:50 by nholbroo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-g -Wall -Wextra -Werror
SRC=src/ft_printf/ft_printf.c \
src/ft_printf/ft_putchar.c \
src/ft_printf/ft_puthexa_lower.c \
src/ft_printf/ft_puthexa_upper.c \
src/ft_printf/ft_putnbr.c \
src/ft_printf/ft_putpercent.c \
src/ft_printf/ft_putptr.c \
src/ft_printf/ft_putstr.c \
src/ft_printf/ft_putuint.c \
src/ft_printf/ft_strlen.c \
src/game/build_elements_in_window.c \
src/game/build_map_in_window.c \
src/game/close_hook_cross.c \
src/game/errors.c \
src/game/finish_game.c \
src/game/init_game.c \
src/game/init_images.c \
src/game/init_map_in_window.c \
src/game/init_struct.c \
src/game/key_hook.c \
src/game/move_player.c \
src/game/run_game.c \
src/get_next_line/get_next_line_utils.c \
src/get_next_line/get_next_line.c \
src/standard_functions/count_array_length.c \
src/standard_functions/free_functions.c \
src/standard_functions/ft_strdup.c \
src/validate_map/check_map/check_map.c \
src/validate_map/check_map/map_check_characters.c \
src/validate_map/check_map/map_check_size.c \
src/validate_map/check_map/map_parse_lines.c \
src/validate_map/check_map_path/check_map_path.c \
src/validate_map/check_map_path/path_check_initializations.c \
src/validate_map/map_errors.c \
src/validate_map/validate_map.c \
src/so_long.c \

OBJ=$(patsubst src/%, build/%, $(SRC:.c=.o))
NAME=so_long

MLX_DIR= minilibx-linux
MLX_INC= $(MLX_DIR)
MLX_LIB= -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

all: mlx $(NAME)

# Cloning minilibx repository if the directory doesn't exist and making minilibx
mlx:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@make -C $(MLX_DIR)

# Compiling the object files, including minilibx and making an executable.
$(NAME): build $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -Iinc -I$(MLX_INC) $(MLX_LIB) -o $(NAME)

# Making a build directory to store the object files if the build directory
# doesn't exist.
build:
	@mkdir -p build

# Making the subdirectories in the build-directory, and compiling the source files,
# making them object files.
build/%.o: src/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling \e[1;32m$(notdir $<)\e[0m"
	@$(CC) $(CFLAGS) -Iinc -c $< -o $@

# Cleans up all the object files, but not the build-directory or the 
# subdirectories inside.
clean:
	@rm -f build/*.o
	@rm -f build/*/*.o
	@echo "\e[1;32mAll my object files removed\e[0m"

# Cleans up the minilibx directory
clean_mlx:
	@rm -rf $(MLX_DIR)
	@echo "\e[1;32mMinilibx directory removed\e[0m"

# Cleans up all object files and the build-directory, and removes the executable.
fclean: clean clean_mlx
	@rm -rf build
	@rm -f $(NAME)
	@echo "\e[1;32mBuild directory and executable removed\e[0m"

# Cleans up everything and compiles everything again.
re: fclean all

.PHONY: all clean fclean re mlx
