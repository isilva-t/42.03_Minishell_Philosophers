/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   41_let_the_game_begin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:35:45 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/15 08:45:39 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

static void	*ft_philo_dinner_plan(void *arg)
{
	t_philo		*ph;

	ph = (t_philo *)arg;
	while (1)
		if (ft_mtx_are_all_threads_running(ph) == TRUE)
			break ;
	usleep(ph->start_delay);
	while (ph->n_meals != ph->d->nb_must_eat
		|| ft_mtx_have_died_philo(ph) == FALSE)
	{
		ft_mtx_take_forks(ph);
		ft_mtx_save_meal_time(ph);
		ft_log(ph, S_EATING, ph->index);
		ph->usleep_done = ft_mtx_is_usleep_loop_done(ph, ph->d->time_to_eat);
		ft_mtx_leave_forks(ph);
		if (ph->usleep_done == FALSE
			|| (ph->max_meals > 0 && ft_mtx_have_reached_max_meals(ph) == TRUE))
			break ;
		ft_log(ph, S_SLEEPING, ph->index);
		if (ft_mtx_is_usleep_loop_done(ph, ph->d->time_to_sleep) == FALSE)
			break ;
		ft_log(ph, S_THINKING, ph->index);
		usleep(350);
	}
	return (NULL);
}

static void	*ft_one_philo_case(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	pthread_mutex_lock(ph->first_fork);
	ft_log(ph, S_FORK, 1);
	pthread_mutex_unlock(ph->first_fork);
	return (NULL);
}

int	ft_let_the_game_begin(t_philo **ph, t_args *d)
{
	size_t	i;

	i = 0;
	d->start_time = ft_get_time();
	if (d->nb_philos == 0 || d->nb_must_eat == 0)
		return (FALSE);
	else if (d->nb_philos == 1)
	{
		ph[0]->last_meal = ft_get_time();
		pthread_create(&(ph[0]->td), NULL,
			&ft_one_philo_case, (void *)ph[0]);
	}
	else
	{
		while (i < d->nb_philos)
		{
			pthread_create(&(ph[i]->td), NULL,
				&ft_philo_dinner_plan, (void *)ph[i]);
			i++;
		}
		ft_set_start_time(d, ph);
		ft_mtx_increase_created_threads(d);
	}
	return (TRUE);
}
