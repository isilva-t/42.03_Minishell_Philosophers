/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   81_mutex_init_and_destroy.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 07:40:10 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/14 07:42:56 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mutex_init(t_philo **ph, t_args *d)
{
	size_t	i;

	i = 0;
	(void)ph;
	d->mtx_fork = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * d->nb_philos);
	if (!d->mtx_fork)
		return (FALSE);
	while (i < d->nb_philos)
	{
		pthread_mutex_init(&d->mtx_fork[i], NULL);
		pthread_mutex_init(&ph[i]->mtx_philo, NULL);
		pthread_mutex_init(&ph[i]->mtx_eat_done, NULL);
		i++;
	}
	pthread_mutex_init(&d->mtx_log, NULL);
	pthread_mutex_init(&d->mtx_died, NULL);
	pthread_mutex_init(&d->mtx_finish_dinner, NULL);
	pthread_mutex_init(&d->mtx_all_tds_running, NULL);
	return (TRUE);
}

int	ft_mutex_destroy(t_philo **ph, t_args *d)
{
	size_t	i;

	(void)ph;
	i = d->nb_philos;
	while (i-- > 0)
	{
		pthread_mutex_destroy(&d->mtx_fork[i]);
		pthread_mutex_destroy(&ph[i]->mtx_philo);
		pthread_mutex_destroy(&ph[i]->mtx_eat_done);
	}
	free (d->mtx_fork);
	pthread_mutex_destroy(&d->mtx_log);
	pthread_mutex_destroy(&d->mtx_died);
	pthread_mutex_destroy(&d->mtx_finish_dinner);
	pthread_mutex_destroy(&d->mtx_all_tds_running);
	return (TRUE);
}
