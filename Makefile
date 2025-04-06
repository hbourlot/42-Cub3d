# -- Colors and formatting
RED				= \033[1;31m
YELLOW 			= \033[1;33m
ORANGE 			= \033[1;38;5;214m
GREEN 			= \033[1;32m
CYAN 			= \033[1;36m
RESET 			= \033[0m

CC				= cc
CFLAGS			= -g -Wall #-Wextra -Werror 
MINILIB_FLAGS	= -Llib/minilibx-linux  -Lmlx -lmlx -lX11 -lXext -lm  #-lmlx_Linux -lX11 -lXext
LIB				= libcube3d.a
INCLUDE 		= inc/
HEADERS			= inc/cub3d.h inc/definitions.h inc/error.h ./lib/libft/inc/libft.h ./lib/raycasting/inc/raycasting.h
SRC_DIR 		= src/
BONUS_DIR 		= bonus/
OBJ_DIR 		= obj/
TOTAL_FILES		= $(shell echo $$(($(words $(OBJS_SRC)) + 1)))
COMPILED_FILES	= 0
OS				= $(shell uname)

NAME			= cub3D
C_FUNCTIONS		= init/game_loop init/init_s_cub3d init/init_s_map 											\
				  init/init_window init/init_game init/init_s_player init/init_s_sprites						\
				  																								\
				  utils/key_hook																				\
																												\
				  exit/free																						\
				  draw/draw_pixel draw/dda draw/raycaster draw/get_texture												\
																												\
				  map/count_lines map/cub_array map/open														\
				  map/parsing/map map/parsing/texture map/parsing/floor_ceiling									\
				  map/parsing/name map/parsing/utils  map/parse													\
				  																								\
				player/locate_spawn_point player/player_movement												\



# -L./ -lminishell
VALGRIND		= valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes
LINK			= -L./lib/libft -lft -L./lib/raycasting -lraycasting $(MINILIB_FLAGS)

SRC_FILES 		= $(addprefix $(SRC_DIR), $(C_FUNCTIONS:=.c))
OBJS_SRC 		= $(addprefix $(OBJ_DIR), $(SRC_FILES:%.c=%.o))

# -- INCLUDES LIBRARIES
LIBFT_LIB 		= ./lib/libft/libft.a
RAYCASTING_LIB  = ./lib/raycasting/libraycasting.a 
MINILIBX_LIB	= ./lib/minilibx-linux/libmlx.a


ifeq ($(OS), Darwin)
	PRINT_CMD = printf
	MSG = "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%% ] $(ORANGE)Compiling [$1]... $(RESET)"
else
	PRINT_CMD = echo -n
	MSG = "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))% ] $(ORANGE)Compiling [$1]... $(RESET)"
endif

# Function to print the compilation message
define print_compile_msg
	$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
	@$(PRINT_CMD) $(MSG)
endef

define clean_func
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(PRINT_CMD) "$(ORANGE)Removing '$(OBJ_DIR)' directory and main.o...$(RESET) "; \
		rm -rf $(OBJ_DIR); \
		rm -rf main.o; \
		$(PRINT_CMD) "$(GREEN)Removed successfully!$(RESET) ✅\n"; \
	fi
endef

define fclean_func
	@if [ -f "$(LIB)" ]; then \
		$(PRINT_CMD) "$(ORANGE)Removing '$(YELLOW)$(LIB)$(ORANGE)' library...$(RESET) "; \
		rm -f $(LIB); \
		$(PRINT_CMD) "$(GREEN)Removed successfully!$(RESET) ✅\n"; \
	fi
	@if [ -f "$(NAME)" ]; then \
		$(PRINT_CMD) "$(ORANGE)Removing '$(RED)$(NAME)$(ORANGE)' executable...$(RESET) "; \
		rm -f $(NAME); \
		$(PRINT_CMD) "$(GREEN)Removed successfully!$(RESET) ✅\n"; \
	fi
endef

# .PHONY: 		all clean fclean re bonus


all:			$(NAME)

$(MINILIBX_LIB):
				make -s -C ./lib/minilibx-linux/

$(NAME): 		$(MINILIBX) $(LIBFT_LIB) $(RAYCASTING_LIB) $(LIB) $(HEADERS)
				@$(CC) $(CFLAGS) $(LIB) $(LINK) -o $(NAME)
				@echo "$(GREEN)Executable '$(RED)$(NAME)$(GREEN)' created successfully!$(RESET) ✅"

$(LIBFT_LIB):
				@make -s -C lib/libft/

$(RAYCASTING_LIB):
				@make -s -C ./lib/raycasting/

$(LIB):			$(OBJS_SRC) main.o
				@ar rcs $@ $(OBJS_SRC) main.o
				@echo "$(CYAN)library '$(YELLOW)$(LIB)$(CYAN)' created successfully!$(RESET)"

$(OBJ_DIR)%.o:	%.c $(INCLUDE)
				@mkdir -p $(dir $@)
				$(call print_compile_msg, $<)
				@$(CC) $(CFLAGS) -c $< -I./$(INCLUDE) -o $@

main.o:			main.c $(INCLUDE)#inc/cube3d.h inc/definitions.h inc/error.h
				$(call print_compile_msg, $<)
				@$(CC) -c main.c $(CFLAGS) -I./$(INCLUDE) -o $@

clean:
				@make clean -s -C ./lib/libft
				@make clean -s -C ./lib/raycasting
				$(call clean_func)

fclean: 		clean
				@make fclean -s -C ./lib/libft
				@make fclean -s -C ./lib/raycasting
				@$(call fclean_func)

re: 			fclean all

bonus:			all

r:
	@make -s
	@./$(NAME) ./map/basic.cub

v:
	@make -s
	@$(VALGRIND) ./$(NAME) ./map/basic.cub
