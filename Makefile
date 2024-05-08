NAME_C = client

NAME_S = server

CFLAGS = -Wall -Wextra -Werror

CC = cc

SRC_C = client.c ft_atoi.c

SRC_S = server.c ft_atoi.c

OBJ_C = $(SRC_C:.c=.o)

OBJ_S = $(SRC_S:.c=.o)

all : $(NAME_C) $(NAME_S)

$(NAME_C) : $(OBJ_C)
	$(CC) $(OBJ_C) -o $(NAME_C)

$(NAME_S) : $(OBJ_S)
	$(CC) $(OBJ_S) -o $(NAME_S)

clean :
	rm -f $(OBJ_C) $(OBJ_S)

fclean : clean
	rm -f $(NAME_C) $(NAME_S)

re : fclean all