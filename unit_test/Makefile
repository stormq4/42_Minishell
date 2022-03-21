# -*- Makefile -*-

## EXECUTABLE
NAME := 				../tester

## INCLUDES
INC_UT := 				-I ../inc
UNIT_INC := 			-I ./inc 

## UNITY DEFINES
UNITY_DEFINES 			:= -D UNITY_OUTPUT_COLOR 

## LIBFT
LIBFT :=				../libft
LIBA :=					../libft/libft.a

## SRCS FILES
SRC :=					$(SRC_TEST) 
SRC_UT :=				src/main.c \
						src/lexer_test.c
SRC_UNITC := 			unity/src/unity.c

## SANITIZE
SANITIZE := -fsanitize=address

## OBJECT FILES
OBJ_DIR :=				../obj
OBJ_C := 				$(addprefix $(OBJ_DIR)/, $(SRC))
OBJ :=					$(OBJ_C:%.c=%.o)

OBJ_UTC := 				$(addprefix $(OBJ_DIR)/, $(SRC_UT) $(SRC_UNITC))
OBJ_UT :=				$(OBJ_UTC:%.c=%.o)

## COMMANDS
test : $(NAME)
	@./$(NAME)

fclean :
	@rm -rf $(NAME)
	@echo $(RED) "Deleting TESTER Executable [OK]"

$(LIBA) :
	@$(MAKE) -C $(LIBFT)

$(OBJ_DIR)/%.o : ../%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_UT) -c $< -o $@

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_UT) $(UNITY_DEFINES) $(UNIT_INC) -c $< -o $@

$(NAME) : $(LIBA) $(OBJ) $(OBJ_UT) 
	@echo $(CYAN)"Object files created for MINISHELL [OK]"
	@$(CC) $(CFLAGS) $(OBJ) $(OBJ_UT) $(UNIT_INC) $(INC_UT) $(LIBA) $(READLINE) $(SANITIZE) -o $(NAME) 
	@echo $(GREEN)"TESTER compiled [OK]"
