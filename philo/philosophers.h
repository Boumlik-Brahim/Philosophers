/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:11:12 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/09 16:00:56 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>

# define DIE	0

typedef struct s_philo
{
	int				id;
	long int		last_time_eat;
	int				nmbroftm_philo_eat;
	pthread_t		thread;
	pthread_mutex_t	fork_mutex;
	struct s_data	*shared_data;
}	t_philo;

typedef struct s_data
{
	int				nbr_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nmbroftm_each_philo_eat;
	int				philo_state;
	long int		start_time;
	int				all_philos_eat;
	pthread_mutex_t	print_mutex;
	t_philo			*philo;
}	t_data;

int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
void		ft_handle_error(char *str);
char		**ft_join_args(char **av);
int			ft_empty_arg(int ac, char **av);
int			ft_check_integers(char **str);
int			ft_init_data(t_data *data, char **args, int ac, char **av);
int			ft_init_mutex(t_data *data);
int			ft_init_thread(t_data *data);
void		ft_print_state(t_data *data, int philo_id, char *str);
void		ft_eat(t_philo *philo, t_data *data);
void		ft_chk_deth(t_philo *philo, t_data *data);
long int	ft_timestamp(void);
void		ft_precis_usleep(t_philo *philo, long int sleep_time);
void		*ft_routine(void *arg);
void		free_data(char **ptr);

#endif
