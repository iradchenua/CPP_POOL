NAME = convert

SRCS =  main.cpp \
		Type.cpp

OBJ = $(SRCS:%.cpp=%.o)

CC = clang++

FLAGS = -Wall -Wextra -Werror  -std=c++98

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
