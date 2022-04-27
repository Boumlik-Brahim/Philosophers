/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:11:12 by bbrahim           #+#    #+#             */
/*   Updated: 2022/04/16 02:11:13 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
#include <time.h>

#define THINK   0
#define EAT     1
#define SLEEP   2
#define DIE     3


typedef struct s_philo
{
	int             id;
    int             right_fork;
    int             left_fork;
    pthread_t       thread;
    pthread_mutex_t fork_Mutex;
    struct s_data  *shared_data;
}   t_philo;

typedef struct s_data
{
    int     nbr_philosophers;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     nmbroftm_each_philo_eat;
    pthread_mutex_t print_Mutex;
    t_philo *philo;
}   t_data;

void	ft_handle_error(char *str);
char	**ft_join_args(char **av);
int ft_empty_arg(int ac, char **av);
int ft_check_integers(char **str);

int ft_init_data(t_data *data, char **args, int ac, char **av);
void	ft_init_philo(t_philo  *philo,t_data *data);

int     ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void    ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
int     ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

void	free_data(char **ptr);


#endif