NAME = push_swap

CC = cc

WFLAGS = -Wall -Werror -Wextra

LIBFT = libft.a

SRC =	push_swap.c \
		push_swap_utils.c \
		push_swap_operations.c \
		push_swap_stack_alloc.c

OBJ = $(SRC:.c=.o)

define GIT =
	git add .
	read -p "commit message:" commit_message
	read -p "branch:" branch
	git commit -m "$$commit_message"
	git push origin $$branch
endef

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(WFLAGS) $(OBJ) -g3 -L ./ -lft -o $(NAME)

%.o: %.c
	$(CC) $(WFLAGS) -g3 -c $< -o $@

$(LIBFT):
	make -C libft

re: fclean all

fclean: clean
	@rm -rf $(NAME)

clean:
	@rm -rf *.o

fclean_libft: fclean
	@make fclean -C libft

commit: fclean_libft
	@$(GIT)

.PONHY: re fclean clean all

.ONESHELL: