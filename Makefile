#####################################################################
## ARGUMENTS

NAME		= push_swap
NAME_BONUS	= checker
CFLAGS		= -Wall -Werror -Wextra
CC		= gcc

#####################################################################
## SOURCES

SRC_FILES	= src/main.c\
		src/push_swap.c\
		src/push_swap_utils_1.c\
		src/push_swap_utils_2.c\
		src/push_swap_utils_3.c\
		src/push_swap_utils_4.c\
		src/push_swap_utils_5.c\
		src/push_swap_utils_6.c\
		src/push_swap_utils_7.c\
		src/push_swap_utils_8.c\
		src/push_swap_parsing.c

SRC_FILES_BONUS	= src_bonus/main.c\
				src_bonus/get_next_line.c\
				src_bonus/get_next_line_utils.c\
				src/push_swap_utils_1.c\
				src/push_swap_utils_2.c\
				src/push_swap_utils_3.c\
				src/push_swap_utils_4.c\
				src/push_swap_utils_5.c\
				src/push_swap_utils_6.c\
				src/push_swap_utils_7.c\
				src/push_swap_utils_8.c\
				src/push_swap_parsing.c\
				src/push_swap.c

#####################################################################
## RULES

all: ${NAME}

${NAME}: ${SRC_FILES}
	${CC} ${SRC_FILES} -g -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

test3:		$(NAME)
		$(eval ARG = $(shell shuf -i 0-50 -n 3))
		./push_swap $(ARG) | valgrind --leak-check=full --show-leak-kinds=all ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test5:		$(NAME)
		$(eval ARG = $(shell shuf -i 0-50 -n 5))
		./push_swap $(ARG) | valgrind --leak-check=full --show-leak-kinds=all ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test100:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-1000 -n 100))
		./push_swap $(ARG) | valgrind --leak-check=full --show-leak-kinds=all ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test500:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-2000 -n 500))
		./push_swap $(ARG) | valgrind --leak-check=full --show-leak-kinds=all ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${SRC_FILES_BONUS}
	${CC} ${SRC_FILES_BONUS} -g -o ${NAME_BONUS}

.PHONY: all clean fclean re
