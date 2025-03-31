NAME = libftprintf.a

CC = gcc 

FLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c conv2hexp.c conv2int.c conv2u.c conv2str.c ft_putchar.c

AR = ar rcs

OBJS = $(SRCS:.c=.o)

RM = rm -f

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)
	
$(NAME): $(OBJS)
	$(AR) $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean 
	$(RM) $(NAME)

re: fclean all
