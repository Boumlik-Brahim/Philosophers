/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:55:51 by bbrahim           #+#    #+#             */
/*   Updated: 2022/04/13 22:55:52 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pthread_mutex_t mutex;

// void *start_routine()
// {
//     int i;
//     int *result;
//     result = malloc(sizeof(int));
//     i = 0;
//     while(i <= 100)
//     {
//         pthread_mutex_lock(&mutex);
//         *result = i;
//         i++;
//         pthread_mutex_unlock(&mutex);
//     }
//     return (void*) result;
// }

// int primes[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// void *routine(void *arg)
// {
//     int index;
//     int sum;
//     int i;
//     index = *(int*)arg;
//     sum = 0;
//     i = 0;
//     while(i < 5)
//     {
//         sum += primes[index + i];
//         i++;
//     }
//     *(int*)arg = sum;
//     return arg;
// }

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_handle_error(char *str)
{
	ft_putstr_fd("\033[0;31m\e[1mError\033[0m\n", 1);
	ft_putstr_fd(str, 1);
	exit(0);
}

// condition variables

int fuel = 0;
pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;

void *fuel_filling(void *arg)
{
    int i;
    i = 0;
    while(i < 5)
    {
        pthread_mutex_lock(&mutexFuel);
        fuel += 60;
        printf("Filled fuel... %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_broadcast(&condFuel);
        sleep(1);
    }
}

void *car(void *arg)
{
    pthread_mutex_lock(&mutexFuel);
    while(fuel < 40)
    {
        printf("No fuel. Waiting...\n");
        pthread_cond_wait(&condFuel, &mutexFuel);
    }
    fuel -= 40;
    printf("Got fuel. Now left: %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
}

// int main(int ac, char *av[])
// {
//    pthread_t    t[10];
//    int          i;

//    pthread_mutex_init(&mutexFuel, NULL);
//    pthread_cond_init(&condFuel, NULL);
//    i = 0;
//    while(i < 5)
//    {
//        if (i == 4)
//        {
//            if(pthread_create(&t[i], NULL, &fuel_filling, NULL) != 0)
//                 ft_handle_error("THREAD ERROR");
//        }
//        else
//        {
//            if(pthread_create(&t[i], NULL, &car, NULL) != 0)
//                 ft_handle_error("THREAD ERROR");
//        }
//        i++;
//    }
//    i = 0;
//    while(i < 5)
//    {
//        if (pthread_join(t[i], NULL) != 0)
//             ft_handle_error("JOIN THREAD ERROR");
//        i++;
//    }
//    pthread_mutex_destroy(&mutexFuel);
//    pthread_cond_destroy(&condFuel);
//    return 0;
// }

// condition variables

// typedef struct s_philo
// {
// 	int	id;
// 	int	left_fork;
// 	int right_fork;
// 	pthread_t thread_id;
// 	long long	last_eat;
// 	struct s_data *data;
// }t_philo;

// typedef struct s_data
// {
// 	int	nbr_philo;
// 	int	tt_die;
// 	int	tt_eat;
// 	int	tt_sleep;
// 	int	n_eat;
// 	int eating_counter;
// 	int	dieded;
// 	int	all_eat;
// 	long long first_time;
// 	pthread_mutex_t fork_mutex[210];
// 	pthread_mutex_t writing_mutex;
// 	pthread_mutex_t eating_mutex;
// 	t_philo philo[210];
// }t_data;

// void	ft_philo_eat(t_philo *philo)
// {
// 	t_data *data;

// 	data = philo->data;
// 	pthread_mutex_lock(&data->fork_mutex[philo->left_fork]);
// 	pthread_mutex_lock(&data->fork_mutex[philo->right_fork]);
// 	print_state(data, philo->id, "has taken a fork\n");
// 	print_state(data, philo->id, "has taken a fork\n");
// 	pthread_mutex_lock(&data->eating_mutex);
// 	print_state(data, philo->id, "is eating\n");
// 	philo->last_eat = timestamp();
// 	usleep(200 * 1000);
// 	printf("eat 2: %lld\n", philo->last_eat);
	
// }

// int	ft_init_philo(t_data *data)
// {
// 	int i;

// 	i = 1;
// 	while (i <= data->nbr_philo)
// 	{
// 		data->philo[i].id = i  ;
// 		data->philo[i].left_fork = i ;
// 		data->philo[i].right_fork = (i % data->nbr_philo ) + 1;
// 		data->philo[i].last_eat = 0;
// 		data->philo[i].data = data;
// 		i++;
// 	}
// 	return (0);
// }

pthread_mutex_t stoveMutex[4];
int stoveFuel[4] = { 100, 100, 100, 100};

void *routine(void *arg)
{
    int i;
    i = 0;
    int fuelNeeded;

    while(i++ < 4)
    {
        if(pthread_mutex_trylock(&stoveMutex[i]) == 0)
        {
            fuelNeeded = (rand() % 30);
            if (stoveFuel[i] - fuelNeeded < 0)
                printf("No more fuel... going  home\n");
            else
            {
                stoveFuel[i] -= fuelNeeded;
                usleep(500000);
                printf("Fuel left %d\n", stoveFuel[i]);
            }
            pthread_mutex_unlock(&stoveMutex[i]);
            break ;
        }
        else
        {
            if (i == 3)
            {
                printf("No stove available yet, waiting...\n");
                usleep(300000);
                i = 0;
            }
        }
    }
}

int main(int ac, char *av[])
{
    srand(time(NULL));
   pthread_t    t[10];
   int          i;

   i = 0;
   while(i < 4)
   {
       pthread_mutex_init(&stoveMutex[i], NULL);
       i++;
   }
   i = 0;
   while(i < 10)
   {
        if(pthread_create(&t[i], NULL, &routine, NULL) != 0)
            ft_handle_error("THREAD ERROR");
       i++;
   }
   i = 0;
   while(i < 10)
   {
       if (pthread_join(t[i], NULL) != 0)
            ft_handle_error("JOIN THREAD ERROR");
       i++;
   }
   i = 0;
   while(i < 4)
   {
       pthread_mutex_destroy(&stoveMutex[i]);
       i++;
   }
   return 0;
}



i = 0;
while(i++ < data->nbr_philosophers)
{
    if (pthread_mutex_init(&data->fork_Mutex[i], NULL)!= 0)
        ft_handle_error("Mutex ERROR");
}
i = 0;
while(i++ < data->nbr_philosophers)
{
    if (pthread_create(&data->philo->thread[i], NULL, &routine, (void*)data) != 0)
        ft_handle_error("THREAD ERROR");
}
i = 0;
while(i++ < data->nbr_philosophers)
{
    if (pthread_join(data->philo->thread[i], NULL) != 0)
        ft_handle_error("THREAD ERROR");
}
i = 0;
while(i++ < data->nbr_philosophers)
{
    pthread_mutex_destroy(&data->fork_Mutex[i]);
}

 int i;
i = 0;
while (i++ < data->nbr_philosophers)
{
    data->philo[i].id = i;
    data->philo[i].right_fork = i;
    data->philo[i].left_fork = (i % data->nbr_philosophers) + 1;
}