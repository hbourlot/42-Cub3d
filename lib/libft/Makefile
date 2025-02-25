# Colors and formatting
RED				=\033[1;31m
YELLOW 			= \033[1;33m
ORANGE 			= \033[1;38;5;214m
GREEN 			= \033[1;32m
CYAN 			= \033[1;36m
RESET 			= \033[0m

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
LIB				= libft.a
LIB_DIR 		= inc/
SRC_DIR 		= src/
MANDATORY_DIR	= mandatory/
BONUS_DIR 		= bonus/
UPD_DIR			= new_functions/
OBJ_DIR 		= obj/
TOTAL_FILES 	= $(words $(SRC_FILES) $(BONUS_FILES))
COMPILED_FILES 	= 0
OS 				= $(shell uname)
MAC_MSG			= "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(( $(COMPILED_FILES) * 100 / $(TOTAL_FILES) ))%% ] $(ORANGE)Compiling [$<]... $(RESET)"
LINUX_MSG       = "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(( $(COMPILED_FILES) * 100 / $(TOTAL_FILES) ))% ] $(ORANGE)Compiling [$<]... $(RESET)"

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
					truncate_character ft_strjoin_char ft_atol ft_isspaces all_spaces init_prev

BONUS			= ft_lstnew ft_lstadd_front ft_lstsize ft_lstadd_back ft_lstmap ft_lstiter ft_lstlast 	\
					ft_lstdelone ft_lstclear															\

#Source and Object files
SRC_FILES 		= $(addprefix $(SRC_DIR)/$(MANDATORY_DIR), $(CFUNCTIONS:=.c)) 	\
					$(addprefix $(SRC_DIR)$(UPD_DIR), $(UPD_SRC:=.c))			\
					# $(addprefix $(SRC_DIR)$(BONUS_DIR), $(BONUS:=.c))	

# BONUS_FILES		= $(addprefix $(BONUS_DIR), $(BONUS:=.c))

OBJS_SRC		= $(addprefix $(OBJ_DIR), $(SRC_FILES:%.c=%.o))
# OBJS_BONUS		= $(addprefix $(OBJ_DIR), $(BONUS_FILES:%.c=%.o))


#Targets that doesn't take into consideration for execution that matches its name.
.PHONY:			all clean fclean re bonus

all: 			$(LIB)
	
$(LIB):			$(OBJS_SRC)
				@ar rcs $@ $^
				@echo "$(CYAN)library '$(GREEN)$(LIB)$(CYAN)' created successfully!$(RESET)"

# bonus: 			$(OBJS_SRC) $(OBJS_BONUS)
# 				@ar rcs $(LIB) $^

$(OBJ_DIR)%.o: 	%.c
				@mkdir -p $(dir $@)
				$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
ifeq ($(OS), Darwin)
				@printf $(MAC_MSG)
else
				@echo -n $(LINUX_MSG)
endif
				@$(CC) $(CFLAGS) -c -I./$(LIB_DIR) $< -o $@
	
clean:
				@rm -rf $(OBJ_DIR)

fclean: 		clean
				@rm -f $(LIB)

re: 			clean fclean all bonus

