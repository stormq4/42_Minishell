# -*- Makefile -*-

NAME := test_1

INC_UT := -I ../inc

UNITY_INC := -D UNITY_OUTPUT_COLOR -D UNITY_FIXTURE_NO_EXTRAS

UT_DIR := unit_test

MAIN := 			main.c
# SRC_MAIN :=			$(addprefix $(UT_DIR)/, $(MAIN))

LIBFT :=			../libft
LIBA :=				../libft/libft.a

# LEXER :=			
SRC :=				$(SRC_TEST) 
# main.c

SRC_UT :=			main.c 

# OBJ := obj

OBJ_DIR :=		../obj
OBJ_C := 		$(addprefix $(OBJ_DIR)/, $(SRC))
OBJ :=			$(OBJ_C:%.c=%.o)

OBJ_UTC := 		$(addprefix $(OBJ_DIR)/, $(SRC_UT))
OBJ_UT :=		$(OBJ_UTC:%.c=%.o)

test : $(NAME)
	@./$(NAME)

$(LIBA) :
	@$(MAKE) -C $(LIBFT)
	@echo LIBFT!!!!

echo :
	@echo this is src: $(SRC)
	@echo this is obj: $(OBJ)

$(OBJ_DIR)/%.o : ../%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_UT) -c $< -o $@

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_UT) -c $< -o $@

$(NAME) : $(LIBA) $(OBJ) $(OBJ_UT)
	@echo $(CYAN)"Object files created for MINISHELL [OK]"
	@$(CC) $(CFLAGS) $(OBJ) $(OBJ_UT) $(INC) $(LIBA) $(READLINE) -o $(NAME)
	@echo $(GREEN)"MINISHELL compiled [OK]"
