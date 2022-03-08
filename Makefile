# -*- Makefile -*-
NAME := minishell

CFLAGS := -Wall -Wextra -Werror

CC := gcc

SRC := src/$(MINISHELL) 

INC := -I ./inc

LIBFT := libft

OBJS := ${SRC:%.c=%.o}

PIPEX := pipex

MINISHELL := 	minishell/main.c \
				minishell/free_shell.c

LEXER := 		lexer/lexer.c \
				lexer/lexer_lst.c \
				lexer/categorize_pipes.c \
				lexer/categorize_redirects \
				lexer/categorize_words.c 

all : $(NAME)

$(NAME) : $(LIBFT) $(SRC)
	@mkdir obj
	@$(CC) $(CFLAGS) $(INC) -o $@ $<

$(LIBFT) :
	$(MAKE) -C $(LIBFT)

