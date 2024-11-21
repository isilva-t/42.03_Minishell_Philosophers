#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

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
	while (i < 5)
	{
		if (w->id == 1)
			 w->d->sum += w->d->read[i + 5];
		else
			 w->d->sum += w->d->read[i];
		i++;
	}
	return (NULL);
}

int main(void)
{
	t_work	w[2];
	t_data	d;
	int	i;
	int array[10] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2};

	pthread_mutex_init(&d.mute, NULL);

	d.read = array;


	i = 0;
	while (i < 2)
	{
		w[i].id = i;
		w[i].d = &d;
		i++;
	}

	i = 0;
	while (i < 2)
	{
		pthread_create(&w[i].td, NULL, &routine, (void *)&w[i]);
		i++;
	}

	printf("lets do the party!\n");
	sleep(1);

	while (i-- > 0)
	{
		pthread_join(w[i].td, NULL);
	}

	pthread_mutex_destroy(&d.mute);
	sleep(1);
	printf("sum: %d \n", d.sum);

}
