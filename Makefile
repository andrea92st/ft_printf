NAME = libftprintf.a

CC = gcc 

FLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c

RM = rm -f  
...
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)