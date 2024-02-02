NAME=scop
CXX=c++
OBJS_DIR=.obj
SRCS_DIR=sources
_SRCS=main.cpp\
		types/connection.cpp\
		types/screen.cpp\
		types/vec3.cpp
_OBJS=$(_SRCS:.cpp=.o)
OBJS=$(addprefix $(OBJS_DIR)/, $(_OBJS))
SRCS=$(addprefix $(SRCS_DIR)/, $(_SRCS))
CXXFLAGS= -Werror -Wall -Wextra -std=c++17
LDFLAGS= -I/usr/include/SDL2 -D_REENTRANT -lSDL2

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@ if !(test -d $(dir $@)); then mkdir -p $(dir $@); fi
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: fclean clean all
