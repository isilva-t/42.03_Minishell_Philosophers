#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

int	n_td;
int	repeat_loop;

#define SIZE	1999999
#define MID		(SIZE / 2)

typedef struct s_data
{
	pthread_mutex_t mute;
	long sum;
	int	*read;
}	t_data;


typedef struct s_work
{
	pthread_t td;
	int id;
	pthread_mutex_t	*mute_sum;
	t_data *d;
	long		td_sum;
}	t_work;

t_work	**do_work_info(int j, t_data *d)
{
	t_work	**w;
	int i;

	w = (t_work **)malloc(sizeof(t_work *) * j);
	if (!w)
		return (NULL);
	i = 0;
	while (i < j)
	{
		w[i] = malloc(sizeof(t_work) * 1);
		if (!w[i])
		{
			while (i-- > 0)
				free(w[i]);
			free(w);
			return (NULL);
		}
		w[i]->d = d;
		w[i]->id = i;
		w[i]->td_sum = 0;
		i++;
	}
	return (w);
}




void	*routine(void *arg)
{
	t_work	*w;
	int	i;
	int	reset_i;
	int	j;

	w = (t_work *)arg;

	i = -1;
	j = -1;

	while (i != w->id)
		i++;
	reset_i = i;

	while (i < SIZE)
	{
		w->td_sum += w->d->read[i];
		i += n_td;
		if (i >= SIZE & j < repeat_loop)
		{
			j++;
			i = reset_i;
		}
	}
	pthread_mutex_lock(&w->d->mute);
	w->d->sum += w->td_sum;
	pthread_mutex_unlock(&w->d->mute);

	return (NULL);
}



int main(int ac, char **av)
{
	t_work **w;
	t_data	d;
	int	i;
	int j;
	int array[SIZE];

	if (ac == 3)
	{
		n_td = atoi(av[1]);
		repeat_loop = atoi(av[2]);
		i = 0;
		j = 0;
		while (i < SIZE)
		{
			if (i >= MID)
				j = 3;
			array[i] = 1 + j;
			i++;
		}
		pthread_mutex_init(&d.mute, NULL);
		d.read = array;
		d.sum = 0;
		
		w = do_work_info(n_td, &d);
		if (!w)
			return (1);
		i = -1;
		while (++i < n_td)
			pthread_create(&w[i]->td, NULL, &routine, (void *)w[i]);

		printf("lets do the party!\n");

		while (i-- > 0)
			pthread_join(w[i]->td, NULL);

		printf("sum: %ld \n", d.sum);

		i = -1;
		while (++i < n_td)
		{
			if (i % 2 == 0)
			{
				printf("\n");
			}
		 	printf("TD %d sum: %ld", w[i]->id, w[i]->td_sum);
		}
		printf("\n");
		i = 0;
		pthread_mutex_destroy(&d.mute);

		while (i < n_td)
			free(w[i++]);
		free(w);
	}
	else
		printf("Two arguments required: [1] nb_threads, [2] n_loop_repeats\n");
}
