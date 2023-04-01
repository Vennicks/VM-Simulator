NAME	= abstractVM

CC	= g++

RM	= rm -f

SRCS	= ./Src/Factory.cpp \
		  ./Src/CoreCalculs.cpp \
		  ./Src/CoreOperation.cpp \
		  ./Src/Parser.cpp \
		  ./Src/Types/BigDecimal.cpp \
		  ./Src/Types/Double.cpp \
		  ./Src/Types/Float.cpp \
		  ./Src/Types/Int8.cpp \
		  ./Src/Types/Int16.cpp \
		  ./Src/Types/Int32.cpp \
		  ./Src/main.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./Includes/pp
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
