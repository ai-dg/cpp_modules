SRC += main.cpp Contact.cpp PhoneBook.cpp
OBJ = $(SRC:.cpp=.o)
NAME = phonebook

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -I./ -std=c++98

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
