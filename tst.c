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

// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <pthread.h>

// void	ft_putstr_fd(char *s, int fd)
// {
// 	int	i;

// 	if (!s)
// 		return ;
// 	i = 0;
// 	while (s[i])
// 	{
// 		write(fd, &s[i], 1);
// 		i++;
// 	}
// }

// void	ft_handle_error(char *str)
// {
// 	ft_putstr_fd("\033[0;31m\e[1mError\033[0m\n", 1);
// 	ft_putstr_fd(str, 1);
// 	exit(0);
// }

// condition variables

// int fuel = 0;
// pthread_mutex_t mutexFuel;
// pthread_cond_t condFuel;

// void *fuel_filling(void *arg)
// {
//     int i;
//     i = 0;
//     while(i < 5)
//     {
//         pthread_mutex_lock(&mutexFuel);
//         fuel += 60;
//         printf("Filled fuel... %d\n", fuel);
//         pthread_mutex_unlock(&mutexFuel);
//         pthread_cond_broadcast(&condFuel);
//         sleep(1);
//     }
// }

// void *car(void *arg)
// {
//     pthread_mutex_lock(&mutexFuel);
//     while(fuel < 40)
//     {
//         printf("No fuel. Waiting...\n");
//         pthread_cond_wait(&condFuel, &mutexFuel);
//     }
//     fuel -= 40;
//     printf("Got fuel. Now left: %d\n", fuel);
//     pthread_mutex_unlock(&mutexFuel);
// }

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

// void ft_usleep(int time, t_philo *philo)
// {
//     int i;

// 	i = ft_timestamp();
// 	while (philo->philo_state != DIE)
// 	{
// 		if ((i - ft_timestamp()) >= time)
// 			break ;
// 		usleep(50);
// 	}
// } 

// pthread_mutex_t stoveMutex[4];
// int stoveFuel[4] = { 100, 100, 100, 100};

// void *routine(void *arg)
// {
//     int i;
//     i = 0;
//     int fuelNeeded;

//     while(i++ < 4)
//     {
//         if(pthread_mutex_trylock(&stoveMutex[i]) == 0)
//         {
//             fuelNeeded = (rand() % 30);
//             if (stoveFuel[i] - fuelNeeded < 0)
//                 printf("No more fuel... going  home\n");
//             else
//             {
//                 stoveFuel[i] -= fuelNeeded;
//                 usleep(500000);
//                 printf("Fuel left %d\n", stoveFuel[i]);
//             }
//             pthread_mutex_unlock(&stoveMutex[i]);
//             break ;
//         }
//         else
//         {
//             if (i == 3)
//             {
//                 printf("No stove available yet, waiting...\n");
//                 usleep(300000);
//                 i = 0;
//             }
//         }
//     }
// }

// int main(int ac, char *av[])
// {
//     srand(time(NULL));
//    pthread_t    t[10];
//    int          i;

//    i = 0;
//    while(i < 4)
//    {
//        pthread_mutex_init(&stoveMutex[i], NULL);
//        i++;
//    }
//    i = 0;
//    while(i < 10)
//    {
//         if(pthread_create(&t[i], NULL, &routine, NULL) != 0)
//             ft_handle_error("THREAD ERROR");
//        i++;
//    }
//    i = 0;
//    while(i < 10)
//    {
//        if (pthread_join(t[i], NULL) != 0)
//             ft_handle_error("JOIN THREAD ERROR");
//        i++;
//    }
//    i = 0;
//    while(i < 4)
//    {
//        pthread_mutex_destroy(&stoveMutex[i]);
//        i++;
//    }
//    return 0;
// }



// i = 0;
// while(i++ < data->nbr_philosophers)
// {
//     if (pthread_mutex_init(&data->fork_Mutex[i], NULL)!= 0)
//         ft_handle_error("Mutex ERROR");
// }
// i = 0;
// while(i++ < data->nbr_philosophers)
// {
//     if (pthread_create(&data->philo->thread[i], NULL, &routine, (void*)data) != 0)
//         ft_handle_error("THREAD ERROR");
// }
// i = 0;
// while(i++ < data->nbr_philosophers)
// {
//     if (pthread_join(data->philo->thread[i], NULL) != 0)
//         ft_handle_error("THREAD ERROR");
// }
// i = 0;
// while(i++ < data->nbr_philosophers)
// {
//     pthread_mutex_destroy(&data->fork_Mutex[i]);
// }

//  int i;
// i = 0;
// while (i++ < data->nbr_philosophers)
// {
//     data->philo[i].id = i;
//     data->philo[i].right_fork = i;
//     data->philo[i].left_fork = (i % data->nbr_philosophers) + 1;
// }

// void	print_state(t_data *data, int id, char *str)
// {
// 	pthread_mutex_lock(&data->writing_mutex);
// 	if (data->dieded == 0)
// 	{
// 		printf("%lld	%d	%s",(timestamp() - data->first_time), id, str);
// 	}
// 	pthread_mutex_unlock(&data->writing_mutex);
// }

// printf("data.nbr_philosophers: %d\n",data.nbr_philosophers);
// printf("data.time_to_die: %d\n",data.time_to_die);
// printf("data.time_to_eat: %d\n",data.time_to_eat);
// printf("data.time_to_sleep: %d\n",data.time_to_sleep);
// printf("data.nmbroftm_each_philo_eat: %d\n",data.nmbroftm_each_philo_eat);
// printf("data.philo[i].id: %d\n",data.philo[i].id);
// printf("data.philo[i].shared_data: %d\n",data.philo[i].shared_data->nbr_philosophers);
// printf("data.philo[i].right_fork: %d\n",data.philo[i].right_fork);
// printf("data.philo[i].left_fork: %d\n",data.philo[i].left_fork);


// long long	timestamp(void)
// {
// 	struct timeval	t;

// 	gettimeofday(&t, NULL);
// 	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
// }

// long long	time_diff(long long past, long long current)
// {
// 	return (current - past);
// }

// void		smart_sleep(long long time, t_data *data)
// {
// 	long long i;

// 	i = timestamp();
// 	while (!(data->dieded))
// 	{
// 		if (time_diff(i, timestamp()) >= time)
// 			break ;
// 		usleep(50);
// 	}
// }

// int    ft_check_death(t_data d, t_philo ph, int i)
// {
//     while (d->all_eat == FALSE)
//     {
//         while (i < d->n_philo && d->dieded == FALSE)
//         {
//             pthread_mutex_lock(&d->eating_mutex);
//             if (ft_time_diff(ph[i].last_eat, ft_get_time()) > d->tt_die)
//             {
//                 ft_print_state(d, ph[i].id, "died\n");
//                 d->dieded = TRUE;
//             }
//             pthread_mutex_unlock(&d->eating_mutex);
//             usleep(100);
//             i++;
//         }
//         if (d->dieded == TRUE)
//             return (END);
//         i = 0;
//         while (d->n_eat != -1 && i < d->n_philo && ph[i].eat_cnt >= d->n_eat)
//             i++;
//         if (i == d->n_philo)
//             return (END);
//     }
//     return (PHTREAD_ERR);
// }
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/*exercice 2 function*/
// int ControleLigne(int **grille, int numline)
// {
//     int i;
//     int j;
//     int f;
    
//     i = 0;
//     while(grille[i])
//     {
//         j = 0;
//         while(grille[i][j])
//         {
//             f = 1;
//             while(grille[i][f])
//             {
//                 if(grille[i][j] == grille[i][f])
//                     return (-1);
//                 f++;
//             }
//             j++;
//         }
//         i++;
//     }
//     return (0);
// }
// /*exercice 2 function*/

// /*exercice 1 function*/
// int VerifierValeurs(int **grille)
// {
//     int i;
//     int j;
    
//     i = 0;
//     while(grille[i])
//     {
//         j = 0;
//         while(grille[i][j])
//         {
//             if(grille[i][j] > 9 || grille[i][j] < 0)
//                 return (-1);
//             j++;
//         }
//         i++;
//     }
//     return (0);
// }
// /*exercice 1 function*/

// int main(int ac, char *av[])
// {
//     /*exercice 1 test*/
//     int **grille;
//     int i = 0;
//     int j = 0;

//     grille = (int **)malloc(sizeof(int *) * 9);
//     while(i < 9)
//     {
//         grille[i] = (int *)malloc(sizeof(int) * 9);
//         i++;
//     }
//     i = 0;
//     while(i < 9)
//     {
//         j = 0;
//         while(j < 9)
//         {
//             grille[i][j] = 5;
//             printf("%d\n",grille[i][j]);
//             j++;
//         }
//         i++;
//     }
//     if(VerifierValeurs(grille) == 0)
//         printf("kulchi mzian");
//     else if(VerifierValeurs(grille) == -1)
//         printf("muchkil");
//     /*exercice 1 test*/

//     /*exercice 2 test*/
//     if(ControleLigne(grille, 1) == 0)
//         printf("kulchi mzian");
//     else if(ControleLigne(grille, 1) == -1)
//         printf("muchkil");
//     /*exercice 2 test*/    
//     return (0);
// }

// int Imax(int tab[], int nombredelement)
// {
//     int i;
//     int j;
//     int max;

//     max = 0;
//     i = 0;
//     while(i < nombredelement)
//     {
//         j = 1;
//         while(j < nombredelement)
//         {
//             if(tab[i] > tab[j])
//                 max = tab[i];
//             j++;
//         }
//         i++;
//     }
//     return(max);
// }

// int main()
// {
//     #define VSIZE 50
//     int i;
//     int vector[VSIZE];

//     for(i = 0; i < VSIZE;i++)
//     {
//         vector[i] = i;
//     }
//     printf("la valeur maximale est:%d\n",Imax(vector, VSIZE));
// }

void	ft_kill_process(t_info *info)
{
	int	i;

	i = 0;
	while (info->head)
	{
		kill(info->head->philo, SIGTERM);
		if (info->head->next == info->tmp)
			break ;
		info->head = info->head->next;
	}
}

void	_exit_process(t_info *info)
{
	int	exit_statu;

	while (1)
	{
		waitpid(-1, &exit_statu, 0);
		if (exit_statu != 0 || (info->cont == info->nmb_of_thread))
		{
			ft_kill_process(info);
			break ;
		}
		else if ((exit_statu == 0) && (info->nmb_of_time_eat != -1))
			info->cont++;
	}
	sem_close(info->forks);
	sem_close(info->print_sem);
	sem_unlink("forks");
	sem_unlink("print_sem");
	free_list(info);
}

void	*check_dead(void *info)
{
	int long	time_check;
	t_node		*node;
	long int	time;

	node = (t_node *) info;
	while (1)
	{
		time_check = get_time() - node->last_meal;
		if (time_check > node->share->time_to_die)
		{
			time = get_time() - node->share->t0;
			printf("%ld ms| %d is dead\n", time, node->index);
			sem_wait(node->share->print_sem);
			node->share->dead_statu = true;
			exit(1);
		}
		if (node->nmb_of_eat == node->share->nmb_of_time_eat)
		{
			node->share->dead_statu = true;
			exit(0);
		}
	}
	return (0);
}