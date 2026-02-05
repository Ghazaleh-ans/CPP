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
NAME		= bureaucrat
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Sources
SRCS	= main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp

# Objects
OBJS	= $(SRCS:.cpp=.o)

#Headers
HEADERS	= Bureaucrat.hpp \
		AForm.hpp \
		ShrubberyCreationForm.hpp \
		RobotomyRequestForm.hpp \
		PresidentialPardonForm.hpp \
		Intern.hpp

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

cleanfiles:
	@rm -f *_shrubbery
	@echo $(CLEAN) $(YELLOW) "Runtime Outputs Cleaned!" $(RESET)

fclean: clean cleanfiles
	@rm -f $(NAME)
	@echo $(FCLEAN) $(YELLOW) "Full Cleaned!" $(RESET)

re: fclean all

.PHONY: all clean fclean cleanfiles re
