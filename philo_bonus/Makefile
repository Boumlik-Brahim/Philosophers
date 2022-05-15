NAME_BONUS = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_BONUS = philo_bonus_utils/ft_atoi_bonus.c \
		philo_bonus_utils/ft_split_bonus.c \
		philo_bonus_utils/ft_strjoin_bonus.c \
		philo_bonus_utils/ft_substr_bonus.c \
		philo_bonus_utils/funct_utils_bonus.c \
		philo_bonus.c \
		philo_bonus_init.c \
		philo_bonus_routine.c \
		philo_bonus_manage.c \
		philo_bonus_errors.c \
		bonus_time_manage.c

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(SRC_BONUS)
	$(CC) $(CFLAGS) -pthread $(SRC_BONUS) -o $(NAME_BONUS) 

clean:
	rm -f $(NAME_BONUS)

fclean:	clean
	rm -f $(NAME_BONUS)

re: fclean bonus

.PHONY: all clean fclean re