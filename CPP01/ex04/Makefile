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
SKALL	= ☠️

# Compiler
NAME		= replace
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Sources
SRCS	= main.cpp FileReplacer.cpp

# Objects
OBJS	= $(SRCS:.cpp=.o)

#Headers
HEADERS	= FileReplacer.hpp


all: $(NAME)

$(NAME): $(OBJS)
	@echo $(BUILD) $(RED) "Compiling $(NAME)..." $(RESET)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo $(SUCCESS) $(GREEN) "Compiling $(NAME) FINISHED" $(RESET)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo $(CLEAN) $(YELLOW) "Cleaned!" $(RESET)

fclean: clean
	@rm -f $(NAME)
	@echo $(FCLEAN) $(YELLOW) "Full Cleaned!" $(RESET)

re: fclean all

test: $(NAME)
	@echo $(BLUE)"Creating test files..."$(RESET)
	@echo "Hello world!\nThis is a test.\nHello again!" > test.txt
	@echo $(BLUE)"Test file created: test.txt" $(RESET)
	@echo $(YELLOW)"Test file content:" $(RESET)
	@cat test.txt
	@echo $(GREEN)"Running tests..." $(RESET)
	@echo $(RED)"Test 1: Replace 'Hello' with 'Hi'" $(RESET)
	./$(NAME) test.txt "Hello" "Hi"
	@echo $(YELLOW)"Content of test.txt.replace:" $(RESET)
	@cat test.txt.replace
	@echo $(RED)"\nTest 2: Replace 'test' with 'example'" $(RESET)
	./$(NAME) test.txt "test" "example"
	@echo $(YELLOW)"Content of test.txt.replace:" $(RESET)
	@cat test.txt.replace
	@echo $(RED) "\nTest 3: Error handling - file doesn't exist" $(RESET)
	./$(NAME) nonexistent.txt "a" "b" || true
	@echo $(RED)"\nTest 4: Error handling - wrong arguments" $(RESET)
	./$(NAME) || true

.PHONY: all clean fclean re test
