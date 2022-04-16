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

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *start_routine()
{
    int i;
    int *result;
    result = malloc(sizeof(int));

    i = 0;
    while(i <= 100)
    {
        pthread_mutex_lock(&mutex);
        *result = i;
        i++;
        pthread_mutex_unlock(&mutex);
    }
    return (void*) result;
}

int primes[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void *routine(void *arg)
{
    int index;
    int sum;
    int i;

    index = *(int*)arg;
    sum = 0;
    i = 0;
    while(i < 5)
    {
        sum += primes[index + i];
        i++;
    }
    *(int*)arg = sum;
    return arg;
}

int main(int ac, char *av[])
{
    // pthread_t   t[2];
    pthread_t   t2[2];
    int i;
    int globalsum;
    int *res;
    int *a;
    
    if (ac != 5 && ac != 6)
        return 0;
    // pthread_mutex_init(&mutex, NULL);
    i = -1;
    while(++i < 2)
    {
        a = malloc(sizeof(int));
        *a = i * 5;
        if (pthread_create(&t2[i], NULL, &routine, a) != 0)
            return 1;
        // printf("thread |%d| has stared\n",i);
    }
    i = -1;
    while(++i < 2)
    {
        int *res;
        if (pthread_join(t2[i], (void**) &res) != 0)
            return 2;
        globalsum += *res;
        free(res);
        // printf("thread |%d| has finished\n",i);
    }
    printf("Global sum:%d\n",globalsum);
    // pthread_mutex_destroy(&mutex);
    // printf("result: %d\n", *res);
    // free(res);
    return 0;
}
