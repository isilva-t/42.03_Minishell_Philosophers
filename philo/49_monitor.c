/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   49_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 07:55:33 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/15 09:03:49 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mtx_all_philos_eaten_all_meals(t_philo **ph, t_args *d, size_t i)
{
	pthread_mutex_lock(&ph[i]->mtx_eat_done);
	if (ph[i]->eating_done == TRUE)
	{
		ph[i]->eating_done = TRUE_VERIFYED;
		d->all_eaten++;
		if (d->all_eaten == d->nb_philos)
		{
			pthread_mutex_unlock(&ph[i]->mtx_eat_done);
			ft_stop_the_game(ph, d);
			pthread_mutex_lock(&d->mtx_finish_dinner);
			d->finish_dinner = TRUE;
			pthread_mutex_unlock(&d->mtx_finish_dinner);
			return (TRUE);
		}
	}
	pthread_mutex_unlock(&ph[i]->mtx_eat_done);
	return (FALSE);
}

int	ft_mtx_set_if_have_philo_died(t_philo **ph, t_args *d, size_t i)
{
	usleep(10);
	pthread_mutex_lock(&ph[i]->mtx_philo);
	if (ft_get_time() - ph[i]->last_meal > d->time_to_die)
	{
		pthread_mutex_unlock(&ph[i]->mtx_philo);
		pthread_mutex_lock(&d->mtx_died);
		d->is_died = TRUE;
		pthread_mutex_unlock(&d->mtx_died);
		ft_stop_the_game(ph, d);
		printf("%zu\t%zu died\n", ft_get_time() - d->start_time, i + 1);
		pthread_mutex_lock(&d->mtx_finish_dinner);
		d->finish_dinner = TRUE;
		pthread_mutex_unlock(&d->mtx_finish_dinner);
		return (TRUE);
	}
	pthread_mutex_unlock(&ph[i]->mtx_philo);
	return (FALSE);
}

void	*ft_monitor(void *arg)
{
	t_args	*d;
	t_philo	**ph;
	size_t	i;

	d = (t_args *)arg;
	ph = (t_philo **)d->ph;
	i = 0;
	while (1)
	{
		if (d->nb_must_eat < 1)
			;
		else if (ft_mtx_all_philos_eaten_all_meals(ph, d, i) == TRUE)
			break ;
		if (ft_mtx_set_if_have_philo_died(ph, d, i) == TRUE)
			break ;
		i = (i + 1) % d->nb_philos;
	}
	return (NULL);
}
