SRC += megaphone.cpp
OBJ = $(SRC:.cpp=.o)
NAME = megaphone

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME)

all : $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
