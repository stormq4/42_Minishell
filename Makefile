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

INLCUDES =			builtins.h \
					executor.h \
					expander.h \
					lexer.h \
					libft.h \
					minishell.h \
					parser.h \
					utils.h 

INLCUDES := 		$(addprefix inc/, $(INLCUDES))

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
MINISHELL := 		free_shell.c \
					run_shell.c

SRC_MINISHELL :=	$(addprefix $(DIR_SRC)/$(DIR_MINISHELL)/, $(MINISHELL))


# Lexer directory with files
DIR_LEXER :=		lexer
LEXER :=			lexer.c \
					categorize_pipes.c \
					categorize_redirects.c \
					token_delete.c \
					categorize_words.c \
					char_actions.c

SRC_LEXER :=		$(addprefix $(DIR_SRC)/$(DIR_LEXER)/, $(LEXER))

# Parser directory with files
DIR_PARSER :=		parser
PARSER :=			parser.c \
					parser_delete.c \
					append_redirect.c \
					append_word.c

SRC_PARSER :=		$(addprefix $(DIR_SRC)/$(DIR_PARSER)/, $(PARSER))

# Executor directory with files
DIR_EXECUTOR :=		executor
EXECUTOR :=			executor.c \
					heredoc.c \
					in_out_fd.c \
					execute_cmd.c \
					forks.c 

SRC_EXECUTOR :=		$(addprefix $(DIR_SRC)/$(DIR_EXECUTOR)/, $(EXECUTOR))


# Expander directory with files
DIR_EXPANDER :=		expander
EXPANDER :=			expander.c \
					envfunctions.c \
					envfunction2.c \
					utils.c \
					split.c \
					errcode.c \
					free_split.c\
					expand_specials.c

SRC_EXPANDER :=		$(addprefix $(DIR_SRC)/$(DIR_EXPANDER)/, $(EXPANDER))

# Utils directory with files
DIR_UTILS :=		utils
UTILS := 			ft_strdup_len.c \
					ft_strlen_c.c \
					find_min.c \
					ft_lstlen.c \
					exit_error.c \
					find_paths.c \
					signals.c \
					adjust_shlvl.c \
					malloc_env.c \
					adjust_location.c \
					expander_utils.c \
					export_utils.c

SRC_UTILS :=		$(addprefix $(DIR_SRC)/$(DIR_UTILS)/, $(UTILS))

# builtins director with files
DIR_BUILTINS :=		built-ins
BUILTINS :=			echo.c\
					pwd.c \
					builtins.c \
					exit.c \
					env.c \
					cd.c \
					export.c \
					exportutils.c \
					unset.c 

SRC_BUILTINS :=		$(addprefix $(DIR_SRC)/$(DIR_BUILTINS)/, $(BUILTINS))

# All Source Files in variable
SRC :=				$(SRC_UTILS) $(SRC_LEXER) $(SRC_MINISHELL) $(SRC_MAIN) $(SRC_PARSER) $(SRC_EXECUTOR) $(SRC_EXPANDER) $(SRC_BUILTINS)

export	SRC_TEST := $(SRC_UTILS) $(SRC_LEXER) $(SRC_MINISHELL) $(SRC_PARSER) $(SRC_EXECUTOR) $(SRC_EXPANDER) $(SRC_BUILTINS)

## Object files from source files
OBJ_DIR :=			obj
OBJ_C :=			$(addprefix $(OBJ_DIR)/, $(SRC))
OBJ :=				$(OBJ_C:%.c=%.o)

## Colors
export GREEN := 			"\033[1;32m"
export CYAN := 				"\033[1;36m"
export RED := 				"\033[1;31m"
export PURPLE := 			"\033[1;35m"
export END :=				"\033[0m" 

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
	@echo $(PURPLE)"Compiled with sanitize=address [OK]"$(END)

utest : fclean
	@rm -rf $(NAME)
	@$(MAKE) -C $(UNIT_TEST) test

itest : $(NAME)
	@$(MAKE) -C integration_test test

$(LIBA) :
	@$(MAKE) -C $(LIBFT) bonus

$(NAME) : $(LIBA) $(OBJ) $(INLCUDES)
	@echo $(CYAN)"Object files created for MINISHELL [OK]"$(END)
	$(CC) $(CFLAGS) $(INC) $(READLINE) $(LIBA) $(OBJ) -o $(NAME)
	@echo $(GREEN)"MINISHELL compiled [OK]"$(END)

$(OBJ_DIR)/%.o : %.c $(INLCUDES)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	@rm -rf obj
	@echo $(RED)"Deleting object files from MINISHELL [OK]"$(END)
	@$(MAKE) clean -C $(LIBFT)

fclean : clean
	@$(MAKE) fclean -C $(LIBFT)
	@$(MAKE) fclean -C $(UNIT_TEST)
	@rm -rf $(NAME)
	@echo $(RED)"Deleting MINISHELL Executable [OK]"$(END)

re : fclean all

.PHONY: all, clean, fclean, re
