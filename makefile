NAME 	=	ft_select

SRC 	=	init.c main.c init_term.c display.c ft_select.c deal_keys.c stock_av.c\
		arrow.c\

INC		=	ft_select.h

OBJ_DIR =	obj 

OBJ		=	$(SRC:.c=.o)

CC		=	clang -I /usr/local/include

CFLAGS	+=	-Wall -Wextra #-Werror

PINK	=	\033[35;5;108m
PURPLE	=	\033[38;5;141m
MAGENTA	=	\033[38;5;177m
END		=	\033[0m

$(NAME):	lib $(OBJ)
	@$(CC) $(CFLAGS) ${SRC} ./libft/libft.a -ltermcap -o $(NAME)
	@echo "${PINK}FT_SELECT IS READY ✓${END}"

all:		$(NAME)

lib:
	@$(MAKE) -C libft
	@echo "${MAGENTA}LIBRARY COMPILED ✓${END}"

$(OBJ):		$(INC)

clean:
	@/bin/rm -rf $(OBJ)
	@make -C ./libft/ clean
	@echo "${PURPLE}clean objs ✗${END}"

fclean:		clean
	@/bin/rm -rf $(NAME)
	@make -C ./libft/ fclean
	@echo "${PURPLE}clean $(NAME) ✗${END}"

re:		fclean all

.PHONY: all clean fclean re
