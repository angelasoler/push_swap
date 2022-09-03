ifneq (,$(findstring xterm,${TERM}))
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	RESET := $(shell tput -Txterm sgr0)
	ARGS_5 := $(shell seq 5 | shuf | tr '\n' ' ')
	ARGS_3 := $(shell seq 3 | shuf | tr '\n' ' ')
	ARGS_100 := $(shell seq 100 | shuf | tr '\n' ' ')
	ARGS_500 := $(shell seq 500 | shuf | tr '\n' ' ')
endif

define GIT =
	git add .
	git status
	read -p "${YELLOW}Commit Message:${RESET}" commit_message
	read -p "${YELLOW}Branch:${RESET}" branch
	git commit -m "$$commit_message"
	git push origin $$branch
endef

define TESTS =
	echo "ordering 3 args with "
	./push_swap ${ARGS_3} | wc -l
	./push_swap ${ARGS_3} | ./checker_linux ${ARGS_3}
	echo "ordering 5 args with "
	./push_swap ${ARGS_5} | wc -l
	./push_swap ${ARGS_5} | ./checker_linux ${ARGS_5}
	echo "ordering 100 args with "
	./push_swap ${ARGS_100} | wc -l
	./push_swap ${ARGS_100} | ./checker_linux ${ARGS_100}
	echo "ordering 500 args with "
	./push_swap ${ARGS_500} | wc -l
	./push_swap ${ARGS_500} | ./checker_linux ${ARGS_500}
endef

NAME = push_swap

CC = cc

WFLAGS = -Wall -Werror -Wextra

LIBFT = libft.a

SRC =	push_swap.c \
		push_swap_utils.c \
		push_swap_operations.c \
		push_swap_stack_alloc.c

OBJ = $(SRC:.c=.o)

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

test:
	@${TESTS}

.PONHY: re fclean clean all

.ONESHELL: