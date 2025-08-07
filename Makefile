NAME = philo

SRCS= src/philo.c src/routine.c src/init.c src/ft_utils.c 

CC = cc
CFLAGS =  -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean 
			@rm -f $(NAME)

re: clean all

.PHONY : all clean fclean re

