# -- Colors and formatting
RED             = \033[1;31m
YELLOW          = \033[1;33m
ORANGE          = \033[1;38;5;214m
GREEN           = \033[1;32m
CYAN            = \033[1;36m
RESET           = \033[0m
UP              = "\033[A"
CUT             = "\033[K"
PRINT_CMD       = printf

# -- Directories
INCLUDE         = inc/
SRC_DIR         = src/
OBJ_DIR         = obj/
BONUS_DIR       = bonus/

# -- Headers
HEADERS         = $(shell find $(INCLUDE) -name "*.h")

# -- Source Files
C_FUNCTIONS     = core/game_loop core/init_game core/init_images core/init_ray core/init_s_cub3d \
                  core/init_s_dda core/init_s_door core/init_s_player core/init_s_sprites core/init_window \
                  core/free_game \
                  gameplay/handle_player_collision gameplay/player_movement gameplay/set_player_spawn \
                  gameplay/find_door \
                  graphics/cast_ray graphics/cast_ray_door graphics/clear_main_img graphics/create_rgb \
                  graphics/draw_line graphics/draw_map graphics/fill_s_ray graphics/get_texture \
                  graphics/perform_dda_loop graphics/put_pixel_img graphics/raycaster \
                  helpers/debug helpers/signal_hook \
                  parsing/count_lines parsing/cub_array parsing/map_range parsing/open parsing/parse_s_map \
                  parsing/parse_map parsing/parse_texture parsing/parse_fc parsing/check_unique_textures \
                  parsing/invalid_file_name parsing/map_reachability \
                  main

SRC_FILES       = $(addprefix $(SRC_DIR), $(C_FUNCTIONS:=.c))
OBJS_SRC        = $(addprefix $(OBJ_DIR)/, $(C_FUNCTIONS:=.o))

# -- Compilation
NAME            = cub3D
CC              = cc
CFLAGS          = -g -Wall -Wextra -Werror
TOTAL_FILES     = $(words $(SRC_FILES))
COMPILED_FILES  = 0
LEN             = 0

# -- Libraries
LIBFT_LIB       = lib/libft/libft.a
MINILIBX_LIB    = lib/minilibx-linux/libmlx.a
LIB             = libcube3d.a
MINILIB_FLAGS   = -Llib/minilibx-linux -lmlx -lX11 -lXext -lm
LINK            = -Llib/libft -lft $(MINILIB_FLAGS)

# -- Debug / Valgrind
VALGRIND        = valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes

# -- Compilation Message
MSG = "[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%% ] $(ORANGE)Compiling [$1]...$(RESET)"

# -- Function to print the compilation message
define print_compile_msg
	$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
	$(eval LEN = $(shell echo -n $(MSG) | wc -c))
	@$(PRINT_CMD) "$$(printf '%*s\r' $(LEN) '')"
	@$(PRINT_CMD) $(MSG)
	@if [ $(COMPILED_FILES) -ne $(TOTAL_FILES) ]; then \
		$(PRINT_CMD) "\r" $(CUT) \
		$(PRINT_CMD) $(UP) $(CUT); \
	fi
endef

# -- Cleaning Functions
define clean_func
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(PRINT_CMD) "$(ORANGE)Removing '$(OBJ_DIR)' directory and main.o...$(RESET) "; \
		rm -rf $(OBJ_DIR); \
		rm -f main.o; \
		$(PRINT_CMD) "$(GREEN)Removed successfully!$(RESET) ✅\n"; \
	fi
endef

define fclean_func
	@if [ -f "$(LIB)" ]; then \
		$(PRINT_CMD) "$(ORANGE)Removing library '$(YELLOW)$(LIB)$(ORANGE)'...$(RESET) "; \
		rm -f $(LIB); \
		$(PRINT_CMD) "$(GREEN)Library removed successfully!$(RESET) ✅\n"; \
	fi
	@if [ -f "$(NAME)" ]; then \
		$(PRINT_CMD) "$(ORANGE)Removing executable '$(RED)$(NAME)$(ORANGE)'...$(RESET) "; \
		rm -f $(NAME); \
		$(PRINT_CMD) "$(GREEN)Executable removed successfully!$(RESET) ✅\n"; \
	fi
endef

# -- Targets
all: $(NAME)

$(NAME): $(MINILIBX_LIB) $(LIBFT_LIB) $(LIB) $(HEADERS)
	@$(CC) $(CFLAGS) $(LIB) $(LINK) -o $(NAME)
	@echo "$(GREEN)Executable '$(RED)$(NAME)$(GREEN)' created successfully!$(RESET) ✅"

$(LIB): $(OBJS_SRC)
	@ar rcs $@ $(OBJS_SRC)
	@echo "$(CYAN)Library '$(YELLOW)$(LIB)$(CYAN)' created successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(call print_compile_msg,$<)
	@$(CC) $(CFLAGS) -c $< -I$(INCLUDE) -o $@

$(LIBFT_LIB):
	@make -s -C lib/libft/

$(MINILIBX_LIB):
	@make -s -C lib/minilibx-linux/

clean:
	@make clean -s -C lib/libft
	$(call clean_func)

fclean: clean
	@make fclean -s -C lib/libft
	$(call fclean_func)

re: fclean all

bonus: all

# -- Shortcuts
r:
	@make -s
	@./$(NAME) ./maps/ex1.cub

v:
	@make -s
	@$(VALGRIND) ./$(NAME) ./maps/ex1.cub

fc: fclean
c: clean

# -- Mark phony targets
.PHONY: all clean fclean re bonus r v fc c