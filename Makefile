# -*- Makefile -*-
NAME := minishell

CFLAGS := -Wall -Wextra -Werror

CC := gcc

SRC := src/$(MINISHELL) 

INC := -I ./inc

LIBFT := libft

OBJS := ${SRC:%.c=%.o}

PIPEX := pipex

MINISHELL := minishell/main.c 

all : $(NAME)

$(NAME) : $(LIBFT) $(SRC)
	@mkdir obj
	@$(CC) $(CFLAGS) $(INC) -o $@ $<

$(LIBFT) :
	$(MAKE) -C $(LIBFT)

