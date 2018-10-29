NAME = mindopen

SRCS =  src/AInstruction.cpp \
		src/Close.cpp \
		src/Down.cpp \
		src/Get.cpp \
		src/Next.cpp \
		src/Open.cpp \
		src/Prev.cpp \
		src/Show.cpp \
		src/Up.cpp \
		src/main.cpp


INCLUDES = -I includes/

OBJ = $(SRCS:%.cpp=%.o)

CC = clang++

LIBS = -lncurses

FLAGS = -Wall -Wextra -Werror $(INCLUDES)

%.o: %.cpp
	$(CC) -c -o $@ $< $(FLAGS)

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re
