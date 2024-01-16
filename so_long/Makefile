# [TARGET]
NAME            :=  so_long

# [COMPILATION FLAGS]
DEBUG           :=  -fsanitize=address -g3
DEBUG2          :=  -g
# CFLAGS          :=  -Wall -Wextra -Werror
CFLAGS          :=  -Wall -Wextra -Werror $(DEBUG)
# CFLAGS          :=  -Wall -Wextra -Werror $(DEBUG2)

# [MAINSTREAM DIR]
SRC_DIR         :=  ./srcs/
OBJS_DIR        :=  ./objs/
HEADER_DIR      :=  header

# [HEADER DIR FOR ARCHIVE]
AR_HEADER_DIR   :=  srcs/ar/header/
AR_HEADER_FILES :=  $(AR_HEADER_DIR)/libft.h \
					$(AR_HEADER_DIR)/ft_printf.h \
					$(AR_HEADER_DIR)/get_next_line.h

# [COLOR SETTINGS]
BLACK           :=  \033[0;30m
RED             :=  \033[0;31m
GREEN           :=  \033[0;32m
YELLOW          :=  \033[0;33m
BLUE            :=  \033[0;34m
PURPLE          :=  \033[0;35m
CYAN            :=  \033[0;36m
WHITE           :=  \033[0;37m
DEF_COLOR       :=  \033[0;39m
LF              :=  \e[1K\r

# [MLX DIR]
MLX_DIR			:= MiniLibX/

# # =========================== MANDATORY PART ================================ #

#################################################################################
######################## [MANDATORY directory] ##################################
#################################################################################

# +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ #
# [HEADER FILES]
HEADER_MANDATORY_DIR			:=  $(HEADER_DIR)/mandatory/
HEADER_FILES_MANDATORY			:=  $(HEADER_MANDATORY_DIR)const_var.h \
									$(HEADER_MANDATORY_DIR)class_functions.h \
									$(HEADER_MANDATORY_DIR)class_helper.h \
									$(HEADER_MANDATORY_DIR)include.h \
									$(HEADER_MANDATORY_DIR)structure.h

# [MANDATORY DEFAULT DIRECTORIES]
MANDATORY					:= $(SRC_DIR)mandatory/

# [MANDATORY DIRECTORIES]
DISPLAY_DIR					:= $(MANDATORY)display/
GRAPHICS_DIR				:= $(MANDATORY)graphics/
LOGIC_DIR					:= $(MANDATORY)logic/
MAIN_DIR					:= $(MANDATORY)main/
PARSE_DIR					:= $(MANDATORY)parse/
UTILS_DIR					:= $(MANDATORY)utils/

#[MANDATORY SRCS FILE CLASS]
SRCS_ERROR_MNG		:=	$(addprefix $(DISPLAY_DIR), \
						error_msg.c \
						display_msg.c)

SRCS_GRAPHICS		:=	$(addprefix $(GRAPHICS_DIR), \
						mlx_img.c \
						mlx_key_hook.c \
						mlx_utils.c)

SRCS_LOGIC			:= 	$(addprefix $(LOGIC_DIR), \
						map_logic.c \
						bfs.c \
						dfs.c)

SRCS_MAIN			:=	$(addprefix $(MAIN_DIR), \
						main.c)

SRCS_PARSE			:=	$(addprefix $(PARSE_DIR), \
						init.c \
						map_parse.c \
						map_parse2.c)

SRCS_UTILS			:=	$(addprefix $(UTILS_DIR), \
						dynamic_memory.c \
						calculations.c)

# [AGGREGATION OF ALL MANDATORY CLASSES]
SRCS				:=	$(SRCS_ERROR_MNG) \
						$(SRCS_GRAPHICS) \
						$(SRCS_LOGIC) \
						$(SRCS_MAIN) \
						$(SRCS_PARSE) \
						$(SRCS_UTILS)

# +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ #

# [MANDATORY OBJS DIRECTORY]
OBJS 				    := $(patsubst $(SRC_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

#################################################################################
#################################################################################
#################################################################################

# [LIBFT ARCHIVE DIRECTORY]
LIB_DIR 			    := ./srcs/ar/
LIB 				    := $(LIB_DIR)libft.a

# [PROGRESS BAR SETTING]
# [FILE DATA]
TOTAL_FILES 	        := $(words $(SRCS))
CURRENT_FILE 		    := 1

# [BAR DATA]
progress_bar		=	printf "\033[999C\e[?25l$(LF)$(RED)[ ♔ linking... ♔ ]$(DEF_COLOR) \
						$(YELLOW)Progress:$(DEF_COLOR) $(YELLOW) %s [%-49s]$(DEF_COLOR)" \
						"$(CURRENT_FILE)/$(TOTAL_FILES)" \
						"$(shell seq -s '>' \
						$$(echo "$(CURRENT_FILE) / $(TOTAL_FILES) * 50" | bc -l) \
						| sed 's/[0-9]//g')"; \
						printf "\033[s\n\033[K$(WHITE)   \
						✔︎ $(CYAN)Compiling... $<$(DEF_COLOR)\033[A";

# [MAKE ALL : MANDATORY RULE]
all: $(OBJS_DIR) $(NAME)

# [CREATING TARGET FILE + LIBFT ARCHIVE(libft.a)]
$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\n"
	@echo "$(GREEN)===============================================$(DEF_COLOR)"
	@echo "$(GREEN)|     🥳  [$(NAME)] compile success. 🥳     |$(DEF_COLOR)"
	@echo "$(GREEN)===============================================$(DEF_COLOR)"

# [CREATING OBJECT FILES]
$(OBJS): objs/%.o: srcs/%.c $(HEADER_FILES_MANDATORY) $(AR_HEADER_FILES)
	@mkdir -p $(@D)
	@$(call progress_bar)
	@$(CC) $(CFLAGS) -I$(HEADER_MANDATORY_DIR) -I$(AR_HEADER_DIR)  -c $< -o $@
	@$(eval CURRENT_FILE := $(shell expr $(CURRENT_FILE) + 1))

# [CREATING OBJECT DIRECTORY]
$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

# # ============================================================================= #

# # ============================== BONUS PART =================================== #
# #################################################################################
# ########################## [BONUS directory] ####################################
# #################################################################################

# # +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ #

# # [TARGET]
# BONUS_NAME 				:=	
# # [HEADER FILES]
# HEADER_BONUS_DIR			:=	$(HEADER_DIR)/BONUS/
# HEADER_FILES_BONUS			:=	$(HEADER_BONUS_DIR)helper.h \
# 								$(HEADER_BONUS_DIR)include.h \
# 								$(HEADER_BONUS_DIR)map.h

# # [BONUS DEFAULT DIRECTORIES]
# BONUS_DIR					:=	$(SRC_DIR)bonus/

# # [BONUS DIRECTORIES]
# BONUS_MAIN				:=	$(BONUS_DIR)main/

# #[BONUS SRCS FILE CLASS]
# SRCS_BONUS_MAIN			:=	$(addprefix $(BONUS_MAIN), \
# 								)

# #[AGGREGATION OF ALL BONUS CLASSES]
# SRCS_BONUS				:=	$(SRCS_BONUS_MAIN)

# # [BONUS OBJS DIRECTORY]
# OBJ_DIR_BONUS		  	:=	$(OBJS_DIR)bonus/

# # +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ #

# # [BONUS OBJS DIRECTORY]
# OBJS_BONUS				:=	$(patsubst $(SRC_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_BONUS))

# #################################################################################
# #################################################################################
# #################################################################################

# # [MAKE BONUS : BONUS RULE]
# bonus: $(OBJ_DIR_BONUS) $(BONUS_NAME)

# # [PROGRESS BAR SETTING]
# # [FILE DATA]
# TOTAL_FILES_BONUS			:=	$(words $(SRCS_BONUS))
# CURRENT_FILE_BONUS			:=	1

# # [BAR DATA]
# progress_bar2		=	printf "\033[999C\e[?25l$(LF)$(RED)[ ♔ linking... ♔ ]$(DEF_COLOR) \
# 						$(YELLOW)Progress:$(DEF_COLOR) $(YELLOW) %s [%-49s] \
# 						$(DEF_COLOR)" "$(CURRENT_FILE_BONUS)/$(TOTAL_FILES_BONUS)" \
# 						"$(shell seq -s '>' \
# 						$$(echo "$(CURRENT_FILE_BONUS) / $(TOTAL_FILES_BONUS) * 50" | bc -l) \
# 						| sed 's/[0-9]//g')"; \
# 						printf "\033[s\n\033[K$(WHITE)   \
# 						✔︎ $(CYAN)Compiling... $<$(DEF_COLOR)\033[A";

# # [CREATING BONUS OBJECT FILES]
# $(OBJS_BONUS): objs/%.o: srcs/%.c $(HEADER_FILES_BONUS)
# 	@mkdir -p $(@D)
# 	@$(call progress_bar2)
# 	@$(CC) $(CFLAGS) -I$(HEADER_BONUS_DIR) -c $< -o $@
# 	@$(eval CURRENT_FILE_BONUS := $(shell expr $(CURRENT_FILE_BONUS) + 1))

# # [CREATING BONUS TARGET FILE + LIBFT ARCHIVE(libft.a) -> if necessary]
# $(BONUS_NAME): $(OBJS_BONUS) $(LIB)
# 	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB) -o $(BONUS_NAME)
# 	@echo "\n"
# 	@echo "$(GREEN)===============================================$(DEF_COLOR)"
# 	@echo "$(GREEN)|  🎉  [$(BONUS_NAME)] compile success.  🎉 |$(DEF_COLOR)"
# 	@echo "$(GREEN)===============================================$(DEF_COLOR)"

# # [CREATING BONUS OBJECT DIRECTORY]
# $(OBJ_DIR_BONUS): $(OBJS_DIR)
# 	@mkdir $(OBJ_DIR_BONUS)

# # ============================================================================= #

# [LIBFT ARCHIVE FILE]

$(LIB): $(AR_HEADER_FILES)
# @sleep 0.5
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) -C $(MLX_DIR)

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r $(OBJ_DIR_BONUS)
	@rm -rf $(LIB_DIR)/objs
	@rm -rf $(LIB)
	@printf "$(LF)🚧 $(Yellow)Cleaning...🚨 $(White) $(OBJ_BO) $(OBJ) \n$(DEF_COLOR)"
	@rm -rf $(OBJ_DIR)
	@printf "$(LF)$(YELLOW)Cleanup complete.$(DEFAULT_COLOR)\n\n"
# @sleep 0.5

fclean: clean
	@printf "$(LF)🚧 $(Red)Cleaning...🚨 $(White)$(NAME)\n"
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@rm -rf $(LIB_DIR)/objs
	@rm -rf $(LIB)
	@echo "$(RED)Executable removed.$(DEFAULT_COLOR)\n"
	@echo "$(CYAN)Clearing terminal in [3 seconds]...$(DEFAULT_COLOR)"
# @sleep 1
	@clear

re: fclean
# @sleep 0.7
	@clear
	@printf "$(PURPLE) ♻️  REBUILD  ♻️\n\n$(DEF_COLOR)"
	@$(MAKE) all

.PHONY: all clean fclean re bonus
