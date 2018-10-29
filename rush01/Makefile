NAME = ft_gkrellm

SRCS =  src/HardwareInfoModule.cpp \
		src/HostInfoModule.cpp \
		src/NcursesMonitor.cpp \
		src/NetworkInfoModule.cpp \
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
