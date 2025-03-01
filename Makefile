# -- Colors and formatting
RED				= \033[1;31m
YELLOW 			= \033[1;33m
ORANGE 			= \033[1;38;5;214m
GREEN 			= \033[1;32m
CYAN 			= \033[1;36m
RESET 			= \033[0m

CC				= cc
CFLAGS			=  -g #-Wall -Wextra -Werror #-pthread #-fsanitize=address,undefined 
MINILIB_FLAGS	= -Llib/minilibx-linux  -Lmlx -lmlx -lX11 -lXext -lm  #-lmlx_Linux -lX11 -lXext
LIB				= libcube3d.a
INCLUDE 		= inc/
SRC_DIR 		= src/
BONUS_DIR 		= bonus/
OBJ_DIR 		= obj/
TOTAL_FILES		= $(words $(OBJS_SRC))
COMPILED_FILES	= 0
OS				= $(shell uname)

MSG_MAC 		= "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%% ] $(ORANGE)Compiling [$<]... $(RESET)"
MSG_LINUX 		= "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))% ] $(ORANGE)Compiling [$<]... $(RESET)"


NAME			= cube3d
C_FUNCTIONS		= initialize/game_loop initialize/s_cube3d initialize/s_map initialize/window					\
																												\
																												\
				  exit/free																						\
																												\
																												\
				  map/count_lines map/cub_array map/open														\
				  parsing/map parsing/texture parsing/floor_ceiling



# -L./ -lminishell
VALGRIND		= valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes
LINK			= -L./ -lcube3d -L./lib/libft -lft $(MINILIB_FLAGS)
SRC_FILES 		= $(addprefix $(SRC_DIR), $(C_FUNCTIONS:=.c))
OBJS_SRC 		= $(addprefix $(OBJ_DIR), $(SRC_FILES:%.c=%.o))

# -- INCLUDES LIBRARIES
LIBFT_LIB = ./lib/libft/libft.a

.PHONY: 		all clean fclean re bonus

all:			$(NAME)

$(NAME):		$(LIBFT_LIB) $(LIB) main.o
				@make re -s -C ./lib/minilibx-linux/
				$(CC) $(CFLAGS) main.o $(LINK) -o $@
				@echo "$(GREEN)Executable '$(NAME)' created successfully!$(RESET) ✅"
# $(CC) $(CFLAGS) main.o -L./lib/libft -lft $(MINILIB_FLAGS) -o $@

$(LIBFT_LIB):
				@make -s -C lib/libft/

$(LIB):			$(OBJS_SRC)
				@ar rcs $@ $(OBJS_SRC)
				@echo "$(CYAN)library '$(RED)$(LIB)$(CYAN)' created successfully!$(RESET)"

$(OBJ_DIR)%.o:	%.c $(INCLUDE)
				@mkdir -p $(dir $@)
				$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
ifeq ($(OS), Darwin)
				@printf $(MSG_MAC)
else
				@echo -n $(MSG_LINUX)
endif
				@$(CC) $(CFLAGS) -c $< -I./$(INCLUDE) -o $@

main.o:			main.c inc/cube3d.h inc/definitions.h inc/error.h
				@$(CC) -c main.c $(CFLAGS) -I./$(INCLUDE) -o $@

clean:
				@printf "$(CYAN)Cleaning up *.o files...$(RESET)\b"
				@rm -rf $(OBJ_DIR)
				@rm -rf main.o
				@make clean -s -C ./lib/libft
				@echo " $(GREEN)Cleaned successfully.$(RESET) ✅"

fclean: 		clean
				@printf "$(CYAN)Cleaning up '$(RED)$(NAME)$(CYAN)' and *.a files...$(RESET)\b"
				@rm -f $(LIB)
				@make fclean -s -C ./lib/libft
				@rm -rf	$(NAME)
				@echo " $(GREEN)Cleaned successfully.$(RESET) ✅"

re: 			fclean all

bonus:			all

# TEST =			test_minishell

# $(TEST): 		$(LIBFT_LIB) $(LIB) $(HEADER_MINI)
# 				$(CC) $(LINK) -o test_minishell
# 				./test_minishell

# t: $(TEST)

r:
	@make -s
	@./$(NAME) ./map/ex1.cub

v:
	@make -s
	@$(VALGRIND) ./$(NAME) ./map/ex1.cub
