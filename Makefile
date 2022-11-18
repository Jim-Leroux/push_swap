#####################################################################
## ARGUMENTS


NAME		= push_swap
CFLAGS		= -Wall -Werror -Wextra
CC		= gcc


#####################################################################
## SOURCES

SRC_FILES	= main.c\
		push_swap.c\
		push_swap_utils_1.c\
		push_swap_utils_2.c\
		push_swap_utils_3.c\
		push_swap_utils_4.c\
		push_swap_utils_5.c\
		push_swap_utils_6.c\
		push_swap_utils_7.c\
		push_swap_parsing.c

#OBJ_FILES	= $(addsuffix .o, $(SRC_FILES))


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
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test5:		$(NAME)
		$(eval ARG = $(shell shuf -i 0-50 -n 5))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test100:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-1000 -n 100))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test500:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-2000 -n 500))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re
