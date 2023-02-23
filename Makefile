FT_NAME = ft_containers

STD_NAME = std_containers

BENCHMARK = time

CC = c++

CLFAGS = -Wall -Wextra -Werror -std=c++98
#-g3 -fsanitize=address


INC = -I include

SRC =	main.cpp \

TIME_SRC =	${addprefix tests/, \
			benchmark.cpp\
			} \ 
		
TEST =	${addprefix tests/vector/, \
		UnitTestVector.cpp \
		testVectorConstructors.cpp \
		testVectorModifiers.cpp \
		testVectorCapacity.cpp \
		} \
# ${addprefix tests/, \
# 		iterator_traits.cpp \
# 		reverse_iterator.cpp \
# 		type_traits.cpp \
# 		algorithm.cpp \
# 		utility.cpp \
# 		}\
# 		${addprefix tests/stack/, \
# 		UnitTestStack.cpp \
# 		testStackConstructors.cpp \
# 		testStackOperators.cpp \
# 		} \

all: $(STD_NAME) $(FT_NAME)

time:
	c++ -o benchmark ./tests/benchmark.cpp
	./benchmark

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
	@./testOuputs.sh

.PHONY:	all clean fclean re test 
