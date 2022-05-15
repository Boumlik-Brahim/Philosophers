/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:11:12 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/15 13:07:03 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/types.h>
# include <signal.h>
# include <time.h>
# include <sys/time.h>

# define DIE	0

typedef struct s_philob
{
	int				id;
	long int		last_time_eat;
	int				nmbroftm_philo_eat;
	pid_t			*pid;
}	t_philob;

typedef struct s_datab
{
	int				nbr_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nmbroftm_each_philo_eat;
	int				philo_state;
	long int		start_time;
	int				all_philos_eat;
	pthread_t		thread;
	sem_t			*fork_semaphore;
	sem_t			*print_semaphore;
	t_philob		philo;
}	t_datab;

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
void		ft_empty_arg(int ac, char **av);
void		ft_check_integers(char **str);
void		ft_semaphore_open(t_datab *data);
void		ft_init_process(t_datab *data);
void		ft_exit(t_datab *data);
void		ft_kill_process(t_datab *data);
void		ft_init_process(t_datab *data);
void		ft_init_data(t_datab *data, char **args, int ac, char **av);
void		*ft_chk_deth(void *arg);
void		ft_print_state(t_datab *data, int philo_id, char *str);
void		ft_eat(t_datab *data);
void		free_data(char **ptr);
long int	ft_timestamp(void);
void		ft_precis_usleep(long int sleep_time);
void		*ft_routine(t_datab *data);

#endif
