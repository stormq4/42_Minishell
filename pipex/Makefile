# -*- Makefile -*-

NAME := pipex

CFLAGS := -Wall -Wextra -Werror

CC := gcc

SRCS :=		src/pipex.c \
			src/fork_pipe.c \
			src/execute.c

HEADFILES := pipex.h

LIBFT := libft/libft.a

all : $(NAME)

$(NAME) : $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ 

$(LIBFT) : 
	$(MAKE) -C libft

clean : 
	$(MAKE) clean -C libft

fclean :
	$(MAKE) fclean -C libft
	rm pipex

re : fclean all

.PHONY : all, clean, flcean, re
