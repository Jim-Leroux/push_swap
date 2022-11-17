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


.PHONY: all clean fclean re
