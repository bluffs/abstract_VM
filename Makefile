.PHONY : clean, fclean, re, $(NAME)

CC = g++ -std=c++11

OPTION = -c

FLAG = #-Wall -Werror -Wextra

NAME = abstract_vm

SRC = main.cpp Container.cpp Factory.cpp Program.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
		@$(CC) $(FLAG) -o $(NAME) $(OBJ)

$(OBJ): $(SRC)
		@$(CC) $(FLAG) $(OPTION) $(SRC)

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME)

re: fclean all
