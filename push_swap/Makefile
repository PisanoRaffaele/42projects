NAME = push_swap
CC = gcc -g
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
BONUS = checker
SRC_DIR = /

SRC_1 = push_swap.c \

SRC_2 =	applier.c \
		checks.c \
		counter.c \
		op1.c \
		op2.c \
		sort.c \
		stack_utils1.c \
		stack_utils2.c \
		utils.c \

BONUS_SRC = bonus/bonus.c \
			bonus/bonus_utils.c \

GETNEXTLINE = getnextline/get_next_line.c \
			  getnextline/get_next_line_utils.c

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

BONUS_OBJ = ${BONUS_SRC:.c=.o}
GETNEXTLINE_OBJ = ${GETNEXTLINE:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}

${BONUS}: ${OBJ_2} ${BONUS_OBJ} ${GETNEXTLINE_OBJ}
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} ${GETNEXTLINE_OBJ} -o bonus/${BONUS} ${INCLUDE}

all: ${NAME} ${BONUS}

bonus: ${BONUS}

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus
