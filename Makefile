NAME_LIB		=	libft.a

HEADER_NAME		=	minitalk.h
NAME_C			=	client
NAME_S			=	server
NAME_B_C		=	client_bonus
NAME_B_S		=	server_bonus

INC_DIR			=	./includes/
INC_LIB			=	./libft/
SRC_DIR			=	./sources/
OBJ_DIR			=	./obj/

SRC_NAME_C		=	client.c utils.c
SRC_NAME_S		=	server.c
SRC_NAME_B_C	=	client_bonus.c utils.c
SRC_NAME_B_S	=	server_bonus.c

HEADER			=	$(addprefix $(INC_DIR), $(HEADER_NAME))

SRC_C			=	$(addprefix $(SRC_DIR), $(SRC_NAME_C))
SRC_S			=	$(addprefix $(SRC_DIR), $(SRC_NAME_S))
SRC_B_C			=	$(addprefix $(SRC_DIR), $(SRC_NAME_B_C))
SRC_B_S			=	$(addprefix $(SRC_DIR), $(SRC_NAME_B_S))
OBJ_C			=	$(addprefix $(OBJ_DIR), $(SRC_NAME_C:.c=.o))
OBJ_S			=	$(addprefix $(OBJ_DIR), $(SRC_NAME_S:.c=.o))
OBJ_B_C			=	$(addprefix $(OBJ_DIR), $(SRC_NAME_B_C:.c=.o))
OBJ_B_S			=	$(addprefix $(OBJ_DIR), $(SRC_NAME_B_S:.c=.o))

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
GCC_LIBFT		=	-L ./libft/ -l ft

all: $(NAME_C) $(NAME_S)

$(NAME_C): $(OBJ_DIR) $(OBJ_C) $(NAME_LIB) $(HEADER)
	$(CC) $(GCC_LIBFT) $(addprefix -I, $(INC_DIR)) $(OBJ_C) $(FLAGS) -o $(NAME_C)

$(NAME_S): $(OBJ_DIR) $(OBJ_S) $(NAME_LIB) $(HEADER)
	$(CC) $(GCC_LIBFT) $(addprefix -I, $(INC_DIR)) $(OBJ_S) $(FLAGS) -o $(NAME_S)

$(OBJ_DIR):
	@mkdir -p obj

$(NAME_LIB):
	@make -C libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) -c -I $(INC_DIR) -I $(INC_LIB_FT) $(FLAGS) $< -o $@

bonus: $(NAME_B_C) $(NAME_B_S)

$(NAME_B_C): $(OBJ_DIR) $(OBJ_B_C) $(NAME_LIB) $(HEADER)
	$(CC) $(GCC_LIBFT) $(addprefix -I, $(INC_DIR)) $(OBJ_B_C) $(FLAGS) -o $(NAME_B_C)

$(NAME_B_S): $(OBJ_DIR) $(OBJ_B_S) $(NAME_LIB) $(HEADER)
	$(CC) $(GCC_LIBFT) $(addprefix -I, $(INC_DIR)) $(OBJ_B_S) $(FLAGS) -o $(NAME_B_S)

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME_S) $(NAME_C) $(NAME_B_C) $(NAME_B_S)
	@make fclean -C libft/

re: fclean all