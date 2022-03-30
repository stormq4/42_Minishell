# -*- Makefile -*-

## EXECUTABLE NAMES
EXEC_DIR := tests

F_NAME :=				lexer \
						parser

NAME :=					$(addprefix $(EXEC_DIR)/, $(F_NAME))

## INCLUDES
INC_UT := 				-I ../inc
UNIT_INC := 			-I ./inc

## UNITY DEFINES
UNITY_DEFINES 			:= -D UNITY_OUTPUT_COLOR

## LIBFT
LIBFT :=				../libft
LIBA :=					../libft/libft.a

## SRCS FILES
SRC_UT :=				src/parser_test.c \
						src/lexer_test.c

SRC_UNITC := 			unity/src/unity.c

_ := 					_test.c

## SANITIZE
SANITIZE := 			-fsanitize=address

## OBJECT FILES
OBJ_DIR :=				../obj
OBJ := 					$(addprefix $(OBJ_DIR)/, $(SRC_TEST:%.c=%.o))

## COMMANDS
test : $(NAME)
	@mkdir -p $(dir $@)
	@rm -rf $(EXEC_DIR)/lexer.dSYM $(EXEC_DIR)/parser.dSYM
	@./run_test.sh

$(NAME) : $(LIBA) $(OBJ)

fclean :
	@rm -rf $(EXEC_DIR)
	@echo $(RED) "Deleting TESTER Executable [OK]"

$(LIBA) :
	@$(MAKE) -C $(LIBFT) bonus

$(OBJ_DIR)/%.o : ../%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_UT) -c $< -o $@

$(EXEC_DIR)/% : src/%$(_)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OBJ) $(SRC_UNITC) $(UNIT_INC) $(UNITY_DEFINES) $(INC_UT) $(LIBA) $(READLINE) $(SANITIZE) $< -o $@
