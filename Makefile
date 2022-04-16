NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = philo_mandatory/philosophers.c \
		philo_mandatory/philo_utils.c \
		philo_mandatory/philo_errors.c \

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -pthread $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re