NAME = philo

NAME_BONUS = philob

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

SRC_BONUS = philo_bonus/philo_bonus_utils/ft_atoi.c \
		philo_bonus/philo_bonus_utils/ft_split.c \
		philo_bonus/philo_bonus_utils/ft_strjoin.c \
		philo_bonus/philo_bonus_utils/ft_substr.c \
		philo_bonus/philo_bonus_utils/funct_utils.c \
		philo_bonus/philo_bonus.c \
		philo_bonus/philo_bonus_init.c \
		philo_bonus/philo_bonus_routine.c \
		philo_bonus/philo_bonus_manage.c \
		philo_bonus/philo_bonus_errors.c \
		philo_bonus/bonus_time_manage.c \

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -pthread $(SRC) -o $(NAME)

philob: $(SRC_BONUS)
	$(CC) $(CFLAGS) -pthread $(SRC_BONUS) -o $(NAME_BONUS)

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re