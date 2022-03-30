# -*- Makefile -*-

## Executable for minishell
NAME := minishell


## Flags and Compilers
export CFLAGS := 		-Wall -Wextra -Werror -g

ifdef sanitize

CFLAGS := 				-Wall -fsanitize=address -Wextra -g

endif

export READLINE := 		-lreadline -I/Volumes/Storage/cache/sde-quai/Library/Logs/Homebrew/readline
export CC := 			gcc


## Headerfiles
INC :=				-I ./inc


## Libft
LIBFT := 			libft
LIBA := 			libft/libft.a


## Source files

# directory
DIR_SRC :=			src


# Main directory with files
DIR_MAIN :=			minishell
MAIN :=				main.c

SRC_MAIN :=			$(addprefix $(DIR_SRC)/$(DIR_MAIN)/, $(MAIN))


# Minishell directory with files
DIR_MINISHELL :=	minishell
MINISHELL := 		free_shell.c 

SRC_MINISHELL :=	$(addprefix $(DIR_SRC)/$(DIR_MINISHELL)/, $(MINISHELL))


# Lexer directory with files
DIR_LEXER :=		lexer
LEXER :=			lexer.c \
					categorize_pipes.c \
					categorize_redirects.c \
					token_delete.c \
					categorize_words.c

SRC_LEXER :=		$(addprefix $(DIR_SRC)/$(DIR_LEXER)/, $(LEXER))

# Parser directory with files
DIR_PARSER :=		parser
PARSER :=			parser.c \
					parser_delete.c

SRC_PARSER :=		$(addprefix $(DIR_SRC)/$(DIR_PARSER)/, $(PARSER))

# Utils directory with files
DIR_UTILS :=		utils
UTILS := 			ft_strdup_len.c \
					ft_strlen_c.c \
					find_min.c

SRC_UTILS :=		$(addprefix $(DIR_SRC)/$(DIR_UTILS)/, $(UTILS))


# All Source Files in variable
SRC :=				$(SRC_UTILS) $(SRC_LEXER) $(SRC_MINISHELL) $(SRC_MAIN) $(SRC_PARSER)

export	SRC_TEST := $(SRC_UTILS) $(SRC_LEXER) $(SRC_MINISHELL) $(SRC_PARSER)

## Object files from source files
OBJ_DIR :=			obj
OBJ_C :=			$(addprefix $(OBJ_DIR)/, $(SRC))
OBJ :=				$(OBJ_C:%.c=%.o)

## Colors
export GREEN := 			"\033[1;32m"
export CYAN := 				"\033[1;36m"
export RED := 				"\033[1;31m"
export PURPLE := 			"\033[1;35m"

## Unit_test
UNIT_TEST := unit_test

## Commands
all : $(NAME)

run : all
	@./$(NAME)

drun : all
	@lldb $(NAME)

sanitize : fclean
	@$(MAKE) sanitize=1
	@echo $(PURPLE)"Compiled with sanitize=address [OK]"

test : fclean
	@$(MAKE) -C $(UNIT_TEST) test

$(LIBA) :
	@$(MAKE) -C $(LIBFT) bonus

$(NAME) : $(LIBA) $(OBJ)
	@echo $(CYAN)"Object files created for MINISHELL [OK]"
	@$(CC) $(CFLAGS) $(OBJ) $(INC) $(LIBA) $(READLINE) -o $(NAME)
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
	@$(MAKE) fclean -C $(UNIT_TEST)
	@rm -rf $(NAME)
	@echo $(RED) "Deleting MINISHELL Executable [OK]"

re : fclean all

.PHONY: all, clean, fclean, re
