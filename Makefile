NAME	=	binary

REP	=	.

SRC	=	$(REP)/$(wildcard *.c)

RM	=	rm -rfv

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra #-Werror
# CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-O0 -g3
CFLAGS	+=	-I./include
CFLAGS	+=	-std=gnu99

LDFLAGS	+=	-L./usr/include/SDL
LDFLAGS	+=	-lSDL -lSDL_image -lSDL_ttf

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
