# all, install, uninstall, clean, dvi, dist, test, gcov_report.
GCC=gcc -g
CFALGS=-Wall -Werror -Wextra -std=c11
SOURCES=*.c
TESTS_SOURCES=*.c
OBJECTS=$(SOURCES:.c=.o)

ifeq ($(shell uname), Linux)
	CHECKFLAGS=-lcheck -lm -lpthread -lrt -lsubunit
else
	CHECKFLAGS=-lcheck -lm -lpthread
endif

all: clean 

test: clean
	$(GCC) $(CFALGS) tests/$(TESTS_SOURCES) s21_smart_calc.a $(CHECKFLAGS) -o s21_smart_calc
	./s21_smart_calc

gcov_report: clean
	$(GCC) $(CFALGS) tests/$(TESTS_SOURCES) $(SOURCES) $(CHECKFLAGS) -fprofile-arcs -ftest-coverage -lgcov -o s21_smart_calc
	./s21_smart_calc
	lcov -t "./s21_smart_calc" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html

clean:
	rm -rf s21_smart_calc $(OBJECTS) a.out *.gcno *.gcda report report.info *.dSYM

valgrind: clean test
	valgrind --tool=memcheck --leak-check=yes  ./s21_smart_calc

clang:
	clang-format -n -style=google $(SOURCES) *.h tests/*.c tests/*.h

main: clean
	$(GCC) $(CFALGS) $(SOURCES) -o s21_smart_calc
	./s21_smart_calc
