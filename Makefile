##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		+=		src/main.c				\
				src/exec_cmd.c			\
				src/check_end.c			\
				src/trottle.c			\
				src/wheels_dir.c		\

NAME	=		ai

OBJ		=		$(SRC:.c=.o)

CFLAGS	+=		-L lib/my -lmy -lm -I include/ -Wextra -Wall

DFLAGS	+=		-g

ECHO	+=		echo -e

all:		$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@$(ECHO) '\033[01;34m---------------\033[01;34m->\033[01;32mAll compiled\033[01;34m<-\033[01;34m---------------\033[01;00m'

clean:
	rm	-f 	$(OBJ)
	make clean -C lib/my
	@$(ECHO) '\033[01;31m-----------------\033[01;31m->\033[01;33mAll clean\033[01;31m<-\033[01;31m----------------\033[01;00m'

fclean: clean
	rm 	-f 	$(NAME)
	make fclean -C lib/my
	@$(ECHO) '\033[01;36m---------------\033[01;36m->\033[01;36mBinary clean\033[01;36m<-\033[01;36m---------------\033[01;00m'

re:	fclean	all

valgrind: re
	valgrind ./$(NAME)
	rm 	-f 	$(NAME)
	make fclean -C lib/my

debug: fclean all
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(DFLAGS)
	@$(ECHO) '\033[01;34m---------------\033[01;34m->\033[01;32mAll compiled on debug mode\033[01;34m<-\033[01;34m---------------\033[01;00m'
