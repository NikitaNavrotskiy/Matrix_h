CC=gcc
FLAGS=-Wall -Werror -Wextra --std=c11

SRC=my*.c
NAME=my_matrix

TEST_EXEC=matrix_test
TEST_FLAGS=-lcheck -lm
TEST_SRC=test/*.c

CLANG_FILES=$(TEST_SRC) $(SRC) test/*.h *.h


all : clean $(NAME).a

$(NAME).a :
	$(CC) $(FLAGS) -c $(SRC)
	ar rcs $(NAME).a *.o
	ranlib $(NAME).a
	rm -f *.o

test : clean
	$(CC) $(FLAGS) $(SRC) $(TEST_SRC) -o $(TEST_EXEC) $(TEST_FLAGS)
	./$(TEST_EXEC)


clang : 
	clang-format -i $(CLANG_FILES)

gcov_report : clean
	$(CC) $(FLAGS) --coverage $(SRC) $(TEST_SRC) -o $(TEST_EXEC) $(TEST_FLAGS)
	./$(TEST_EXEC)
	lcov -t "$(TEST_EXEC)" -o matrix_gcov.info -c -d .
	genhtml -o report matrix_gcov.info
	open report/index.html
	google-chrome report/index.html


clean : 
	rm -f $(NAME).a
	rm -f *.o
	rm -f $(TEST_EXEC)
	rm -f *.gc*
	rm -f $(TEST_EXEC)* matrix_gcov.info
	rm -rf report
