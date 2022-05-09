NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = philo_mandatory/philo_utils/ft_atoi.c \
		philo_mandatory/philo_utils/ft_split.c \
		philo_mandatory/philo_utils/ft_strjoin.c \
		philo_mandatory/philo_utils/ft_substr.c \
		philo_mandatory/philo_utils/funct_utils.c \
		philo_mandatory/philo.c \
		philo_mandatory/philo_init.c \
		philo_mandatory/philo_errors.c \
		philo_mandatory/philo_manage.c \
		philo_mandatory/time_manage.c \
		philo_mandatory/philo_routine.c \


all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -pthread $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re