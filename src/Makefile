CC=gcc
CFLAGS=-std=c11 -Wall -Wextra #-Werror
TFLAGS=-lcheck -lm -lpthread -lsubunit
CGFLAGS=-fprofile-arcs -ftest-coverage --coverage -O0

all: clean s21_math.a test gcov_report

s21_math.a: s21_math.h
	$(CC) $(CFLAGS) -c s21_*.c
	ar -rcs s21_math.a s21_*.o s21_math.h

test:
	$(CC) $(CFLAGS) -c  $(CGFLAGS) s21_*.c
	ar -rcs libs21_math.a s21_*.o s21_math.h
	$(CC) $(CFLAGS) ./s21_test/test.c -L. -ls21_math -o ./s21_test/test $(TFLAGS) $(CGFLAGS)
	./s21_test/test
	-rm -rf ./s21_test/*.gc*

style_fix:
	clang-format --style=Google -i s21_*.c s21_*.h ./s21_test/test.c

style_check:
	clang-format --style=Google -n s21_*.c s21_*.h ./s21_test/test.c

memory_leaks_check:
	CK_FORK=no leaks -atExit -- ./s21_test/test
	# CK_FORK=no valgrind --leak-check=full --track-origins=yes -s ./s21_test/test

gcov_report:
	gcov s21*.c
	lcov -t . -o ./report/report.info -c -d .
	genhtml -o report ./report/report.info
	open ./report/index.html

clean:
	rm -rf *.o *.a *.gc* ./s21_test/test ./s21_test/test.gc* ./s21_test/coverage* ./s21_test/*info ./report/*
