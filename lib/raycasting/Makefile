# Colors and formatting
RED				=\033[1;31m
YELLOW 			= \033[1;33m
ORANGE 			= \033[1;38;5;214m
GREEN 			= \033[1;32m
CYAN 			= \033[1;36m
RESET 			= \033[0m

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
NAME			= libraycasting.a
INCLUDE 		= inc/
SRC_DIR 		= src/
OBJ_DIR 		= obj/
TOTAL_FILES		= $(shell echo $$(($(words $(OBJS_SRC)))))

COMPILED_FILES 	= 0
OS 				= $(shell uname)

C_FUNCTIONS		= add cross dot identify_matrix magnitude multiply_matrix_vector normalize \
					rotation_matrix_z subtract translation_matrix
			
#Source and Object files
SRC_FILES 		= $(addprefix $(SRC_DIR), $(C_FUNCTIONS:=.c))

OBJS_SRC		= $(addprefix $(OBJ_DIR), $(SRC_FILES:%.c=%.o))



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
		$(PRINT_CMD) "$(ORANGE)Removing '$(OBJ_DIR)' directory...$(RESET) "; \
		rm -rf $(OBJ_DIR); \
		rm -rf main.o; \
		$(PRINT_CMD) "$(GREEN)Removed successfully!$(RESET) ✅\n"; \
	fi
endef

define fclean_func
	@if [ -f "$(NAME)" ]; then \
		$(PRINT_CMD) "$(ORANGE)Removing '$(YELLOW)$(NAME)$(ORANGE)' library...$(RESET) "; \
		rm -f $(NAME); \
		$(PRINT_CMD) "$(GREEN)Removed successfully!$(RESET) ✅\n"; \
	fi
endef

all: 			$(NAME)
	
$(NAME):		$(OBJS_SRC)
				@ar rcs $@ $^
				@echo "$(CYAN)library '$(YELLOW)$(NAME)$(CYAN)' created successfully!$(RESET)"

$(OBJ_DIR)%.o: 	%.c $(INCLUDE)
				@mkdir -p $(dir $@)
				$(call print_compile_msg, $<)
				@$(CC) $(CFLAGS) -c -I./$(INCLUDE) $< -o $@

clean:
				$(call clean_func)

fclean: 		clean
				$(call fclean_func)

re: 			clean fclean all bonus

#Targets that doesn't take into consideration for execution that matches its name.
.PHONY:			all clean fclean re bonus
