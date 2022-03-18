# -*- Makefile -*-

NAME := 				test_1

INC_UT := 				-I ../inc
UNIT_INC := 			src/tester.h
UNITY_INC := 			-I./unity/src -I./unity/extras/fixture/src
UNITY_DEFINES 			:= -D UNITY_OUTPUT_COLOR -D UNITY_FIXTURE_NO_EXTRAS

UT_DIR := 				unit_test

MAIN := 				src/main.c

LIBFT :=				../libft
LIBA :=					../libft/libft.a

SRC :=					$(SRC_TEST) 

SRC_UT :=				main.c 

SRC_UNITC := 			unity/src/unity.c \
						unity/extras/fixture/src/unity_fixture.c

OBJ_DIR :=				../obj
OBJ_C := 				$(addprefix $(OBJ_DIR)/, $(SRC))
OBJ :=					$(OBJ_C:%.c=%.o)

OBJ_UTC := 				$(addprefix $(OBJ_DIR)/, $(SRC_UT) $(SRC_UNITC))
OBJ_UT :=				$(OBJ_UTC:%.c=%.o)

# OBJ_UNITC :=			$(addprefix $(OBJ_DIR)/, $(SRC_UNITC))
# OBJ_UNIT :=				$(OBJ_UNITC:%.c=%.o)

test : $(NAME)
	@./$(NAME)

$(LIBA) :
	@$(MAKE) -C $(LIBFT)
	@echo LIBFT!!!!

# echo :
# 	@echo this is src: $(SRC)
# 	@echo this is obj: $(OBJ_UNIT)

$(OBJ_DIR)/%.o : ../%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_UT) -c $< -o $@

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_UT) $(UNITY_DEFINES) $(UNITY_INC) -c $< -o $@

$(NAME) : $(LIBA) $(OBJ) $(OBJ_UT) 
	@echo $(CYAN)"Object files created for MINISHELL [OK]"
	@$(CC) $(CFLAGS) $(OBJ) $(OBJ_UT) $(INC_UT) $(LIBA) $(READLINE) -o $(NAME)
	@echo $(GREEN)"MINISHELL compiled [OK]"
