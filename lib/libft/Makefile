# -- Colors and Formatting
RED             = \033[1;31m
YELLOW          = \033[1;33m
ORANGE          = \033[1;38;5;214m
GREEN           = \033[1;32m
CYAN            = \033[1;36m
RESET           = \033[0m
UP              = "\033[A"
CUT             = "\033[K"
PRINT_CMD       = printf

# -- Compiler & Flags
CC              = cc
CFLAGS          = -Wall -Wextra -Werror

# -- Project Info
NAME            = libft.a
LIB_DIR         = inc/
SRC_DIR         = src/
MANDATORY_DIR   = mandatory/
BONUS_DIR       = bonus/
UPD_DIR         = new/
OBJ_DIR         = obj/

# -- Source Files
CFUNCTIONS      = ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint \
                  ft_memchr ft_memcpy ft_memmove ft_memset ft_strchr ft_strdup ft_strlcpy ft_strlen \
                  ft_strncmp ft_strnstr ft_strrchr ft_tolower ft_toupper ft_strjoin ft_strtrim \
                  ft_substr ft_split ft_striteri ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_strmapi \
                  ft_itoa ft_memcmp ft_putstr_fd ft_strlcat

UPD_SRC         = ft_itoa_iter ft_linelen ft_nbrlen ft_strcmp ft_lstduplicate ft_lstidx ft_lstvalue \
                  ft_free_split ft_strcpy ft_strcat ft_append_and_free free_split get_next_line \
                  ft_printf ft_putchar ft_putstr array_length char_cmp ft_strstr is_str_longer \
                  is_greater split_by_tokens sort_arrays_by_length ft_strncpy remove_substring \
                  ft_strcmps ft_strstr_any find_string_match free_pointers ft_printf_fd \
                  all_same_char get_last_node get_offset insert_string truncate_range \
                  truncate_character ft_strjoin_char ft_atol ft_isspaces all_spaces init_prev \
                  split_metadata contains_char

BONUS           = ft_lstnew ft_lstadd_front ft_lstsize ft_lstadd_back ft_lstmap ft_lstiter ft_lstlast \
                  ft_lstdelone ft_lstclear

# -- Object and Source Lists
SRC_FILES       = $(addprefix $(SRC_DIR)$(MANDATORY_DIR), $(CFUNCTIONS:=.c)) \
                  $(addprefix $(SRC_DIR)$(UPD_DIR), $(UPD_SRC:=.c))

OBJS_SRC        = $(addprefix $(OBJ_DIR), $(SRC_FILES:%.c=%.o))

# -- Compilation Tracking
COMPILED_FILES  = 0
LEN             = 0
TOTAL_FILES     = $(words $(SRC_FILES))

# -- Message Formatting
MSG             = "[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%% ] $(ORANGE)Compiling [$1]...$(RESET)"

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
	@if [ -f "$(NAME)" ]; then \
		$(PRINT_CMD) "$(ORANGE)Removing '$(YELLOW)$(NAME)$(ORANGE)' library...$(RESET) "; \
		rm -f $(NAME); \
		$(PRINT_CMD) "$(GREEN)Removed successfully!$(RESET) ✅\n"; \
	fi
endef

# -- Targets
all: $(NAME)

$(NAME): $(OBJS_SRC)
	@ar rcs $@ $^
	@echo "$(CYAN)Library '$(YELLOW)$(NAME)$(CYAN)' created successfully!$(RESET) ✅"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(call print_compile_msg,$<)
	@$(CC) $(CFLAGS) -c -I$(LIB_DIR) $< -o $@

clean:
	$(call clean_func)

fclean: clean
	$(call fclean_func)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
