NAME = philo

SRCS= src/philo.c src/routine.c src/init.c src/ft_utils.c 

CC = cc
CFLAGS =  -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	@rm -f $(NAME)

fclean:clean

re: clean all

.PHONY : all clean fclean re

