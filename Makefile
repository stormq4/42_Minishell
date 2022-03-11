# -*- Makefile -*-

## Executable for minishell
NAME := minishell

## Flags and compilers
CFLAGS := -Wall -Wextra -Werror
READLINE := -lreadline -I/Volumes/Storage/cache/sde-quai/Library/Logs/Homebrew/readline
CC := gcc

## Headerfiles
INC := -I ./inc

## Libft
LIBFT := libft
LIBA := libft/libft.a

## Source directory
DIR_SRC :=			src

# Main directory with files
DIR_MAIN :=			minishell
MAIN :=				main.c
SRC_MAIN :=			$(addprefix $(DIR_SRC)/$(DIR_MAIN)/, $(MAIN))

# Minishell directory with files
MINISHELL := 		free_shell.c \
					initialize_structs.c
DIR_MINISHELL :=	minishell
SRC_MINISHELL :=	$(addprefix $(DIR_SRC)/$(DIR_MINISHELL)/, $(MINISHELL))

# Lexer directory with files
LEXER :=			lexer.c \
					lexer_lst.c \
					categorize_pipes.c \
					categorize_redirects.c \
					categorize_words.c
DIR_LEXER :=		lexer
SRC_LEXER :=		$(addprefix $(DIR_SRC)/$(DIR_LEXER)/, $(LEXER))

# Utils directory with files
UTILS := 			ft_strdup_len.c \
					ft_strlen_c.c
DIR_UTILS :=		utils
SRC_UTILS :=		$(addprefix $(DIR_SRC)/$(DIR_UTILS)/, $(UTILS))

# All Source Files with files
SRC :=				$(SRC_UTILS) $(SRC_LEXER) $(SRC_MINISHELL) $(SRC_MAIN)

## Object files from source files
OBJ_DIR := obj
OBJ_C :=				$(addprefix $(OBJ_DIR)/, $(SRC))
OBJ :=					$(OBJ_C:%.c=%.o)

## Colors
GREEN := "\033[1;32m"
CYAN := "\033[1;36m"
RED := "\033[0;31m"

all : $(NAME)

echo:
	@echo $(SRC)
	@echo $(OBJ)

$(LIBA) :
	$(MAKE) -C $(LIBFT)

$(NAME) : $(LIBA) $(OBJ)
	@echo $(CYAN)"Object files created for MINISHELL [OK]"
	@$(CC) $(OBJ) $(INC) $(LIBA) $(READLINE) -o $(NAME)
	@echo $(GREEN)"MINISHELL compiled [OK]"

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	@rm -rf obj
	@echo $(RED) "Deleting object files from MINISHELL [OK]"
	@$(MAKE) clean -C $(LIBFT)

fclean : clean
	@$(MAKE) fclean -C $(LIBFT)
	@rm $(NAME)
	@echo $(RED) "Deleting MINISHELL Executable [OK]"

re : fclean all

.PHONY: all, clean, fclean, re


# O_MAIN_PATH := $(OBJ_DIR)/$(DIR_SRC)/$(DIR_MAIN)
# O_MINISHELL_PATH := $(OBJ_DIR)/$(DIR_SRC)/$(DIR_MINISHELL)
# O_LEXER_PATH := $(OBJ_DIR)/$(DIR_SRC)/$(DIR_LEXER)
# O_UTILS_PATH := $(OBJ_DIR)/$(DIR_SRC)/$(DIR_UTILS)

# OBJ_MAIN := $(MAIN:%.c=$(O_MAIN_PATH)/%.o)
# OBJ_MINISHELL := $(MINISHELL:%.c=$(O_MINISHELL_PATH)/%.o)
# OBJ_LEXER := $(LEXER:%.c=$(O_LEXER_PATH)/%.o)
# OBJ_UTILS := $(UTILS:%.c=$(O_UTILS_PATH)/%.o)
# OBJ := $(OBJ_MAIN) $(OBJ_MINISHELL) $(OBJ_LEXER) $(OBJ_UTILS)


# $(O_UTILS_PATH)/%.o : $(DIR_SRC)/$(DIR_UTILS)/%.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# $(O_MAIN_PATH)/%.o : $(DIR_SRC)/$(DIR_MAIN)/%.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# $(O_MINISHELL_PATH)/%.o : $(DIR_SRC)/$(DIR_MINISHELL)/%.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# $(O_LEXER_PATH)/%.o : $(DIR_SRC)/$(DIR_LEXER)/%.c 
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(INC) -c $< -o $@