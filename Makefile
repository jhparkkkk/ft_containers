FT_NAME = ft_containers

STD_NAME = std_containers

CC = clang++

CLFAGS = -Wall -Wextra -Werror -std=c++98

INC = -I include

SRC =	main.cpp \
		
TEST =	${addprefix tests/, \
		UnitTestStack.cpp \
		} \

all: $(STD_NAME) $(FT_NAME)

$(STD_NAME): $(SRC) $(TEST)
	$(CC) $(CLFAGS) $(INC) -o $(STD_NAME) $(SRC) $(TEST)

$(FT_NAME): $(SRC) $(TEST)
	$(CC) -DFT $(CLFAGS) $(INC) -o $(FT_NAME) $(SRC) $(TEST)

clean:
	rm -rf *.o $(FT_NAME) $(STD_NAME) diff std_output ft_output

fclean: clean

re: fclean all

test:
	@rm -rf std_output | true
	@rm -rf ft_output | true
	@rm -rf diff | true
	@./test.sh

.PHONY:	all clean fclean re test 
