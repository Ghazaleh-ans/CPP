# Colors
RESET	= "\033[0m"
BLACK	= "\033[30m"
RED		= "\033[31m"
GREEN	= "\033[32m"
YELLOW	= "\033[33m"
BLUE	= "\033[34m"
MAGENTA	= "\033[35m"
CYAN	= "\033[36m"
WHITE	= "\033[37m"

# Emojis
SUCCESS	= ✅
BUILD	= 🔨
CLEAN	= 🧹
FCLEAN	= 🧼

# Compiler
NAME		= thinkingAnimals
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Sources
SRCS	= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

# Objects
OBJS	= $(SRCS:.cpp=.o)

#Headers
HEADERS	= Animal.hpp Dog.hpp Cat.hpp Brain.hpp


all: $(NAME)

$(NAME): $(OBJS)
	@echo $(BUILD) $(RED) "Compiling $(NAME)..." $(RESET)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo $(SUCCESS) $(GREEN) "Compiling $(NAME) FINISHED" $(RESET)

%.o: %.cpp $(HEADERS) $(SRCS)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo $(CLEAN) $(YELLOW) "Cleaned!" $(RESET)

fclean: clean
	@rm -f $(NAME)
	@echo $(FCLEAN) $(YELLOW) "Full Cleaned!" $(RESET)

re: fclean all

.PHONY: all clean fclean re