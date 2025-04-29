# Colors and formatting
RED				= \033[1;31m
YELLOW 			= \033[1;33m
ORANGE 			= \033[1;38;5;214m
GREEN 			= \033[1;32m
CYAN 			= \033[1;36m
RESET 			= \033[0m
UP				= "\033[A"
CUT				= "\033[K"


CC				= cc
CFLAGS			= -Wall -Wextra -Werror
# LIB				= libft.a
NAME			= libft.a
LIB_DIR 		= inc/
SRC_DIR 		= src/
MANDATORY_DIR	= mandatory/
BONUS_DIR 		= bonus/
UPD_DIR			= new_functions/
OBJ_DIR 		= obj/
TOTAL_FILES 	= $(words $(SRC_FILES) $(BONUS_FILES))
COMPILED_FILES 	= 0
OS 				= $(shell uname)
MAIN_SRC		= main.c

CFUNCTIONS		= ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint		\
					ft_memchr ft_memcpy ft_memmove ft_memset ft_strchr ft_strdup ft_strlcpy ft_strlen	\
					ft_strncmp ft_strnstr ft_strrchr ft_tolower ft_toupper ft_strjoin ft_strtrim		\
					ft_substr ft_split ft_striteri ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_strmapi	\
					ft_itoa ft_memcmp ft_putstr_fd ft_strlcat 											\
			
UPD_SRC			=  ft_itoa_iter ft_linelen ft_nbrlen ft_strcmp ft_lstduplicate ft_lstidx ft_lstvalue	\
					ft_free_split ft_strcpy ft_strcat ft_append_and_free free_split	get_next_line		\
					ft_printf ft_putchar ft_putstr  array_length char_cmp ft_strstr is_str_longer		\
					is_greater split_by_tokens sort_arrays_by_length ft_strncpy remove_substring		\
					ft_strcmps ft_strstr_any find_string_match free_pointers ft_printf_fd				\
					all_same_char get_last_node get_offset insert_string truncate_range					\
					truncate_character ft_strjoin_char ft_atol ft_isspaces all_spaces init_prev			\
					split_metadata contains_char

BONUS			= ft_lstnew ft_lstadd_front ft_lstsize ft_lstadd_back ft_lstmap ft_lstiter ft_lstlast 	\
					ft_lstdelone ft_lstclear															\

#Source and Object files
SRC_FILES 		= $(addprefix $(SRC_DIR)/$(MANDATORY_DIR), $(CFUNCTIONS:=.c)) 	\
					$(addprefix $(SRC_DIR)$(UPD_DIR), $(UPD_SRC:=.c))			\
					# $(addprefix $(SRC_DIR)$(BONUS_DIR), $(BONUS:=.c))	

# BONUS_FILES		= $(addprefix $(BONUS_DIR), $(BONUS:=.c))

OBJS_SRC		= $(addprefix $(OBJ_DIR), $(SRC_FILES:%.c=%.o))
# OBJS_BONUS		= $(addprefix $(OBJ_DIR), $(BONUS_FILES:%.c=%.o))


# ifeq ($(OS), Darwin)
# PRINT_CMD = printf
# MSG = "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%% ] $(ORANGE)Compiling [$1]... $(RESET)"
# else
# PRINT_CMD = echo -n
# MSG = "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))% ] $(ORANGE)Compiling [$1]... $(RESET)"
# endif

PRINT_CMD = printf
MSG = "[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%% ] $(ORANGE)Compiling [$1]... $(RESET)"

# Function to print the compilation message
define print_compile_msg
	$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
	@$(PRINT_CMD) "%105s\r"
	@$(PRINT_CMD) $(UP) $(CUT)
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
	@if [ -f "$(NAME)" ]; then \
		$(PRINT_CMD) "$(ORANGE)Removing '$(YELLOW)$(NAME)$(ORANGE)' library...$(RESET) "; \
		rm -f $(NAME); \
		$(PRINT_CMD) "$(GREEN)Removed successfully!$(RESET) ✅\n"; \
	fi
endef

all: 			$(NAME)
	
$(NAME):		$(OBJS_SRC)
				@ar rcs $@ $^
				@echo "$(CYAN)library '$(YELLOW)$(NAME)$(CYAN)' created successfully!$(RESET)\n"


$(OBJ_DIR)%.o: 	%.c
				@mkdir -p $(dir $@)
				$(call print_compile_msg,$<)
				@$(CC) $(CFLAGS) -c -I./$(LIB_DIR) $< -o $@
	
clean:
				$(call clean_func)

fclean: 		clean
				$(call fclean_func)

re: 			clean fclean all bonus

#Targets that doesn't take into consideration for execution that matches its name.
.PHONY:			all clean fclean re bonus