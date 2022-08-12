NAME = ../libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =	ft_itoa.c \
		ft_atoi.c \
		ft_printf.c \
		ft_strlen.c \
		ft_toupper.c \
		ft_lstnew.c \
		ft_lstmap.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstsize.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_printf_int_convs.c \
		ft_printf_other_convs.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -r $(NAME) $(OBJ)

%.o: %.c ../includes/libft.h 
	@$(CC) $(CFLAGS) -c $< -I../includes -o $@

re: fclean all

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf *.o
