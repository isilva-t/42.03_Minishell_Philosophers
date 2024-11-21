/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   31_create_philos_mem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:14:21 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/14 09:43:52 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo_vars(t_philo **ph, t_args *d, size_t i)
{
	ph[i]->last_meal = d->start_time;
	ph[i]->d = d;
	ph[i]->index = i;
	ph[i]->id = i + 1;
	ph[i]->n_meals = 0;
	ph[i]->eating_done = 0;
	ph[i]->max_meals = d->nb_must_eat;
	ph[i]->n_philos = d->nb_philos;
	if (ph[i]->id % 2 != 0)
		ph[i]->start_delay = 90;
	else
		ph[i]->start_delay = 0;
	ph[i]->usleep_done = TRUE;
}

t_philo	**ft_create_philos_mem(t_args *d)
{
	t_philo	**ph;
	size_t	i;

	ph = (t_philo **)malloc(sizeof(t_philo *) * d->nb_philos);
	if (!ph)
		return (NULL);
	i = 0;
	while (i < d->nb_philos)
	{
		ph[i] = malloc(sizeof(t_philo) * 1);
		if (!ph[i])
		{
			while (i-- > 0)
				free(ph[i]);
			free(ph);
			return (NULL);
		}
		ft_init_philo_vars(ph, d, i);
		i++;
	}
	return (ph);
}
