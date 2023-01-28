NAME=	push_swap
NAMEB=	checker
cc=	cc
CFLAGS=	-Wall -Wextra -Werror

AF=    check.c   \
ft_split.c    \
rules.c    \
rules2.c    \
rules3.c    \
sort.c    \
utils1.c    \
utils2.c	\
utils3.c	\
utils4.c	\
check_min_max.c \
push_swap.c	\

bonus= bonus/check_bonus.c \
bonus/get_next_line_utils.c	\
bonus/get_next_line.c \
bonus/split_bonus.c \
bonus/rules_bonus.c\
bonus/checker_bonus.c\
bonus/utils1.c\
bonus/rules2_bonus.c\
bonus/rules3_bonus.c\

OBJ=    $(AF:.c=.o)

BONUS=	$(bonus:.c=.o)

all:    $(NAME)

$(NAME):    $(OBJ)
	$(cc) $(CFLAGS) $(OBJ) -o $(NAME)

bonus :  $(BONUS)
	$(cc) $(CFLAGS) $(BONUS) -o $(NAMEB)

clean:
	rm -f $(OBJ) $(BONUS)

fclean:    clean
	rm -f $(NAME) $(NAMEB)

re: fclean all
