#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define SIZE	1000000
#define MID		500000
#define N_TD	8

typedef struct s_data
{
	pthread_mutex_t mute;
	int sum;
	int	*read;
}	t_data;


typedef struct s_work
{
	pthread_t td;
	int id;
	pthread_mutex_t	*mute_sum;
	t_data *d;
}	t_work;

void	*routine(void *arg)
{
	t_work	*w;
	int i;

	w = (t_work *)arg;
	i = 0;
	while (i < MID)
	{
		pthread_mutex_lock(&w->d->mute);
		if (w->id == 1)
			 w->d->sum += w->d->read[i + MID];
		else
			 w->d->sum += w->d->read[i];
		pthread_mutex_unlock(&w->d->mute);
		i++;
	}
	return (NULL);
}

int	do_work_info(t_work	***w, int j, t_data *d)
{
	int i;

	*w = (t_work **)malloc(sizeof(t_work *) * j);
	if (!w)
	{
		printf("aqui\n");
		return (1);
	}
	i = 0;
	while (i < j)
	{
		(*w)[i] = malloc(sizeof(t_work) * 1);
		if (!(*w)[i])
		{
		printf("ou\n");
			//ft free all points and struct
			return (1);
		}
		(*w)[i]->d = d;
		(*w)[i]->id = i;
		i++;
	}
	return (0);
}

int main(void)
{
	t_work	**w;
	t_data	d;
	int	i;
	int array[SIZE];

	i = 0;
	while (i < SIZE)
	{
		array[i] = 1;
		i++;
	}
	pthread_mutex_init(&d.mute, NULL);
	d.read = array;
	d.sum = 0;
	w = NULL;
	if (do_work_info(&w, N_TD, &d) == 1)
	{
		printf("antes\n");
		return (1);
	}
	i = 0;
	while (i < 2)
	{
		pthread_create(&w[i]->td, NULL, &routine, (void *)w[i]);
		i++;
	}

//	printf("lets do the party!\n");
//	sleep(1);

	while (i-- > 0)
	{
		pthread_join(w[i]->td, NULL);
	}
	i = 0;
	pthread_mutex_destroy(&d.mute);
	printf("sum: %d \n", d.sum);
	while (i < 8)
		free(w[i++]);
	free(w);

}
