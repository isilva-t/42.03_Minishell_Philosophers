# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 08:22:14 by isilva-t          #+#    #+#              #
#    Updated: 2024/11/15 08:39:05 by isilva-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############################
#          PAINTING
##############################
CLR_RMV = \033[0m
RED	    = \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
CYAN	= \033[1;36m
##############################
#          CONFIGS
##############################
NAME = philo
CC = cc
CFLAGS = -Iincludes
EFLAGS = -Wall -Wextra -Werror -g
FSAN_FLAG = -fsanitize=thread
RM	    = rm -rf
##############################
#          FILES
##############################
HEADER = philo.h
SRCS = \
	  00_main.c \
	  01_init.c \
	  11_first_args_check.c \
	  21_parse_data.c \
	  31_create_philos_mem.c \
	  35_align_forks.c \
	  41_let_the_game_begin.c \
	  42_set_start_time.c \
	  43_mtx_fts_all_tds_running.c \
	  44_mtx_fts_forks.c \
	  45_mtx_save_meal_time.c \
	  46_mtx_have_reached_max_meals.c \
	  49_monitor.c \
	  51_mtx_have_died_philo.c \
	  52_mtx_log.c \
	  59_mtx_fts_usleep_and_get_time.c \
	  61_stop_the_game.c \
	  71_mutex_init_and_destroy.c \
	  81_utils.c \
	  91_free_and_cleanup.c

OBJ_DIR = obj
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(EFLAGS) -c $< -o $@

%.o: %.c
	@$(CC) $(CFLAGS) $(EFLAGS) -c $< -o $@

##############################
#       GENERAL RULES
##############################

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
	@$(CC) $(CFLAGS) $(EFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created[0m ✅"

.PHONY: clean
clean:
	@ $(RM) -f $(OBJ_DIR)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✅"

.PHONY: fclean
fclean: clean
	@ $(RM) $(NAME) $(NAME_BONUS)
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✅"

.PHONY: re
re : fclean all

##############################
#       HELPER RULES
##############################

.PHONY: ph
ph:	re
	@echo -n "./philo "; read args; ./philo $$args

###############
.PHONY: sanitize
sanitize: EFLAGS += $(FSAN_FLAG)
sanitize: $(NAME)

.PHONY: sa
sanitize: EFLAGS += $(FSAN_FLAG)
sanitize: $(NAME)

.PHONY: sa
sa:	fclean	sanitize
	@echo -n "./philo "; read args; ./philo $$args

###############
.PHONY: tab
tab: CFLAGS += -D TAB=1
tab: $(NAME)

.PHONY: tab
tab:	fclean	sanitize
	@echo -n "./philo "; read args; ./philo $$args

###############

.PHONY: norm
norm:
	@norminette | grep -E 'Error:|rror!'

#############################
