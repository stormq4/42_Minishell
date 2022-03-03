#						~ Makefile ~						#
NAME := minishell

CFLAGS := -Wall -Wextra -Werror

CC := gcc

LIBFT := libft

PIPEX := pipex





all : $(NAME)

$(NAME) : $(LIBFT) #$(PIPEX) 

$(LIBFT) :
	$(MAKE) -C $(LIBFT)

