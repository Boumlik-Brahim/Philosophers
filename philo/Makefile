NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = philo_utils/ft_atoi.c \
	philo_utils/ft_strtrim.c \
	philo_utils/ft_substr.c \
	philo_utils/funct_utils.c \
	philo.c \
	philo_init.c \
	philo_errors.c \
	philo_manage.c \
	time_manage.c \
	philo_routine.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -pthread $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re