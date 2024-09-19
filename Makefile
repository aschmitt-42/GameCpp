NAME        = Game

CC          = c++
FLAGS       = -Wall -Wextra -Werror -std=c++17
RM          = rm -rf

OBJDIR      = .objfiles
SRCDIR      = src/
INCDIR      = inc/
RAYLIB_LIB  = inc/raylib/src/libraylib.a


FILES       = Player  main  Game  Ball 

SRC         = $(addprefix $(SRCDIR)/, $(FILES:=.cpp))
OBJ         = $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER      = $(INCDIR)Game.hpp $(INCDIR)Player.hpp $(INCDIR)Ball.hpp 

MAKE_LIB = $(MAKE) -C $(INCDIR)raylib/src

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(MAKE_LIB) PLATFORM=PLATFORM_DESKTOP 
	@$(CC) $(OBJ) $(RAYLIB_LIB) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)%.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(LIBFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)
	$(MAKE_LIB) clean


fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
