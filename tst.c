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

int main(int ac, char *av[])
{
   pthread_t    t[5];
   int          i;

   pthread_mutex_init(&mutexFuel, NULL);
   pthread_cond_init(&condFuel, NULL);
   i = 0;
   while(i < 5)
   {
       if (i == 4)
       {
           if(pthread_create(&t[i], NULL, &fuel_filling, NULL) != 0)
                ft_handle_error("THREAD ERROR");
       }
       else
       {
           if(pthread_create(&t[i], NULL, &car, NULL) != 0)
                ft_handle_error("THREAD ERROR");
       }
       i++;
   }
   i = 0;
   while(i < 5)
   {
       if (pthread_join(t[i], NULL) != 0)
            ft_handle_error("JOIN THREAD ERROR");
       i++;
   }
   pthread_mutex_destroy(&mutexFuel);
   pthread_cond_destroy(&condFuel);
   return 0;
}
