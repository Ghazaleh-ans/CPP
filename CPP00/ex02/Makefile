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
SUCCESS	= "✅"
BUILD	= "🔨"
Clean	= "🧹"

# Compiler
NAME = account
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Sources
SRCS = tests.cpp Account.cpp

# Objects
OBJS = $(SRCS:.cpp=.o)

# Headers
HEADERS = Account.hpp

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(BUILD) $(RED) "Compiling $(NAME)..." $(RESET)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo $(SUCCESS) $(GREEN) "Compiling $(NAME) FINISHED" $(RESET)

%.o: %.cpp $(HEADERS)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo $(CLEAN) $(YELLOW) "Cleaned!" $(RESET)

fclean: clean
	@rm -f $(NAME)
	@echo $(CLEAN) $(YELLOW) "Full Cleaned!" $(RESET)

re: fclean all

.PHONY: all clean fclean re
