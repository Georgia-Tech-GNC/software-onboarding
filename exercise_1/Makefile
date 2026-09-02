CC ?= gcc
CFLAGS := -std=c2x -Wall -Wpedantic -Wextra -Werror -Wstrict-prototypes -Wmissing-declarations
CFLAGS += -Wold-style-definition -Werror=vla -fsanitize=address

SRC = student.c tests/tests.c
INC = -I. -Itests/

.PHONY: test

test: 
	@$(CC) $(CFLAGS) $(SRC) $(INC) -o test_executable 
	-@./test_executable
	@rm ./test_executable
