##
## PERSONAL PROJECT, 2019
## collatz
## File description:
## Makefile
##

SRC	=	src/error_help.c		\
		src/main_collatz.c		\

OBJ	=	$(SRC:.c=.o)

HEADER_PATH     =       include/

CC	=	@gcc

LIB     =       include/libmy.a

CFLAGS	=	-I $(HEADER_PATH) -Wall -Werror -Wextra --pedantic

NAME	=	collatz

.PHONY: clean fclean re collatz

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling \'$(NAME)\'
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo \'$(NAME)\' compiled successfully

clean:
	@rm -rf $(OBJ)
	@echo Cleaned .o for \'$(NAME)\'

fclean:	clean
	@rm -rf $(NAME)
	@echo Cleaned \'$(NAME)\'
	@rm -rf $(OUTPUTTXT)
	@echo Cleaned \'$(OUTPUTTXT)\'

re: fclean all
