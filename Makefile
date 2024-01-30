NAME=scop
CXX=c++
OBJS_DIR=.obj
SRCS_DIR=sources
_SRCS=main.cpp
_OBJS=$(_SRCS:.cpp=.o)
OBJS=$(addprefix $(OBJS_DIR)/, $(_OBJS))
SRCS=$(addprefix $(SRCS_DIR)/, $(_SRCS))
CXXFLAGS= -Werror -Wall -Wextra
LDFLAGS= -I/usr/include/SDL2 -D_REENTRANT -lSDL2

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(NAME) $(SRCS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	if !(test -d $(OBJS_DIR)); then mkdir -p $(OBJS_DIR); fi
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean fclean re

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
