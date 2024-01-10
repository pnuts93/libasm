NAME =		libasm.a

ASMC =		nasm
SRC_DIR =	src
SRC =		ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJ_DIR =	obj
OBJ =		$(SRC:%.s=%.o)
OBJECTS =	$(addprefix $(OBJ_DIR)/, $(OBJ))
ASMFLAGS =	-felf64

TEST_NAME = test_bin
CC =		gcc
TEST_DIR = test
TEST_SRC = main.c strlen.c strcpy.c strcmp.c write.c read.c strdup.c utils.c
TEST_OBJ = $(TEST_SRC:%.c=%.o)
TEST_OBJECTS = $(addprefix $(TEST_OBJ_DIR)/, $(TEST_OBJ))
TEST_OBJ_DIR = $(TEST_DIR)/obj
CFLAGS =	-Werror -Wall -Wextra -g -fno-builtin-strcmp
INC =		-I.
LDFLAGS =	-L. -lasm

all : $(NAME)

$(NAME) : $(addprefix $(OBJ_DIR)/, $(OBJ))
	ar -rcs $(NAME) $(OBJECTS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	@mkdir -p $(@D)
	$(ASMC) $(ASMFLAGS) $< -o $@

clean :
	rm -fr $(OBJ_DIR)
	rm -fr $(TEST_OBJ_DIR)

fclean : clean
	rm -f $(NAME)
	rm -f $(TEST_NAME)

re : fclean all

test : $(TEST_NAME)

$(TEST_NAME) : $(addprefix $(TEST_OBJ_DIR)/, $(TEST_OBJ))
	$(CC) $(CFLAGS) $(INC) $(TEST_OBJECTS) -o $(TEST_NAME) $(LDFLAGS)

$(TEST_OBJ_DIR)/%.o : $(TEST_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@