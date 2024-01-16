NAME := so_long
BONUS_NAME := so_long_bonus
PROJECT := SO_LONG
PROJECT_BONUS := SO_LONG_BONUS
CFLAGS := -Wall -Wextra -Werror

# [directories]
SRC_DIR := ./srcs/
OBJS_DIR := ./objs/
HEADER_DIR := header

# [Colors for visual effects]
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
DEF_COLOR = \033[0;39m
LF = \e[1K\r

MAIN_DIR := $(SRC_DIR)mandatory/main/

# OBJ_DIR_BONUS := $(OBJS_DIR)bonus/
BONUS_DIR := $(SRC_DIR)bonus/

SRCS_MAIN := $(addprefix $(MAIN_DIR), \
              main.c)

SRCS := $(SRCS_MAIN)

# [DO NOT EDIT THE LINE BELOW]
# [only comment or uncomment]
LIB_DIR := ./srcs/ar/
LIB := $(LIB_DIR)libft.a

# [MANDATORY SECTION]
# [creating object file directories according to the source file directories]
OBJS := $(patsubst $(SRC_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

# [Header file dependencies]
HEADER_FILES_MANDATORY := $(HEADER_DIR)/$(PROJECT).h

# [Progress bar]
TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE := 1
progress_bar = printf "\033[999C\e[?25l$(LF)$(RED)[ ♔ linking... ♔ ]$(DEF_COLOR) $(YELLOW)Progress:$(DEF_COLOR) $(YELLOW) %s [%-49s]$(DEF_COLOR)" "$(CURRENT_FILE)/$(TOTAL_FILES)" "$(shell seq -s '>' $$(echo "$(CURRENT_FILE) / $(TOTAL_FILES) * 50" | bc -l) | sed 's/[0-9]//g')"; \
			   printf "\033[s\n\033[K$(WHITE)   ✔︎ $(CYAN)Compiling... $<$(DEF_COLOR)\033[A";

# [compiling part]
all: $(OBJS_DIR) $(NAME)

$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "\n"
	@echo "$(GREEN)===============================================$(DEF_COLOR)"
	@echo "$(GREEN)|     🥳  [$(PROJECT)] compile success. 🥳     |$(DEF_COLOR)"
	@echo "$(GREEN)===============================================$(DEF_COLOR)"

$(OBJS): objs/%.o: srcs/%.c $(HEADER_FILES_MANDATORY)
	@mkdir -p $(@D)
	@$(call progress_bar)
	@$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@
	@$(eval CURRENT_FILE := $(shell expr $(CURRENT_FILE) + 1))
	@sleep 0.001

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

# # [BONUS SECTION]
# # [creating object file directories according to the source file directories]
# OBJS_BONUS  := $(patsubst $(SRC_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_BONUS))

# # [Header file dependencies]
# HEADER_FILES_BONUS     := $(HEADER_DIR)/$(PROJECT_BONUS).h

# # [Progress bar]
# TOTAL_FILES_BONUS := $(words $(SRCS_BONUS))
# CURRENT_FILE_BONUS := 1
# progress_bar2 = printf "\033[999C\e[?25l$(LF)$(RED)[ ♔ linking... ♔ ]$(DEF_COLOR) $(YELLOW)Progress:$(DEF_COLOR) $(YELLOW) %s [%-49s]$(DEF_COLOR)" "$(CURRENT_FILE_BONUS)/$(TOTAL_FILES_BONUS)" "$(shell seq -s '>' $$(echo "$(CURRENT_FILE_BONUS) / $(TOTAL_FILES_BONUS) * 50" | bc -l) | sed 's/[0-9]//g')"; \
# 			   printf "\033[s\n\033[K$(WHITE)   ✔︎ $(CYAN)Compiling... $<$(DEF_COLOR)\033[A";

# # [compiling part]
# bonus: $(OBJ_DIR_BONUS) $(BONUS_NAME)

# $(OBJS_BONUS): objs/%.o: srcs/%.c $(HEADER_FILES_BONUS)
# 	@mkdir -p $(@D)
# 	@$(call progress_bar2)
# 	@$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@
# 	@$(eval CURRENT_FILE_BONUS := $(shell expr $(CURRENT_FILE_BONUS) + 1))
# 	@sleep 0.001

# $(BONUS_NAME): $(OBJS_BONUS) $(LIB)
# 	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB) -o $(BONUS_NAME)
# 	@echo "\n"
# 	@echo "$(GREEN)===============================================$(DEF_COLOR)"
# 	@echo "$(GREEN)|  🎉  [$(PROJECT) bonus] compile success.  🎉 |$(DEF_COLOR)"
# 	@echo "$(GREEN)===============================================$(DEF_COLOR)"

# $(OBJ_DIR_BONUS): $(OBJS_DIR)
# 	@mkdir $(OBJ_DIR_BONUS)

# $(OBJ_DIR_BONUS)/%.o: $(BONUS_DIR)%.c
# 	@mkdir -p $(@D)
# 	@$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

# applying libft archive
$(LIB):
	@sleep 1
	@$(MAKE) -C $(LIB_DIR)

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r $(OBJ_DIR_BONUS)
	@rm -rf $(LIB_DIR)/objs
	@rm -rf $(LIB)
	@printf "$(LF)🚧 $(Yellow)Cleaning...🚨 $(White) $(OBJ_BO) $(OBJ) \n$(DEF_COLOR)"
	@rm -rf $(OBJ_DIR)
	@printf "$(LF)$(YELLOW)Cleanup complete.$(DEFAULT_COLOR)\n\n"
	@sleep 0.5

fclean: clean
	@printf "$(LF)🚧 $(Red)Cleaning...🚨 $(White)$(NAME)\n"
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@rm -rf $(LIB_DIR)/objs
	@rm -rf $(LIB)
	@echo "$(RED)Executable removed.$(DEFAULT_COLOR)\n"
	@echo "$(CYAN)Clearing terminal in [3 seconds]...$(DEFAULT_COLOR)"
	@sleep 1
	@clear

re: fclean
	@sleep 1
	@clear
	@printf "$(PURPLE) ♻️  REBUILD  ♻️\n\n$(DEF_COLOR)"
	@$(MAKE) all

.PHONY: all clean fclean re bonus
