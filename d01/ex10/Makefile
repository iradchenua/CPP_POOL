NAME = cato9tails

SRCS =  main.cpp

OBJ = $(SRCS:%.cpp=%.o)

CC = clang++

FLAGS = -Wall -Wextra -Werror

%.o: %.cpp
	$(CC) -c -o $@ $< $(FLAGS)

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re
