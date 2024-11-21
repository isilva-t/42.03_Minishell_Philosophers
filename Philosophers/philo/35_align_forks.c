/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   35_align_forks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:42:10 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/14 08:43:53 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_align_forks_for_even_philo(t_philo **ph, t_args *d, size_t i)
{
	ph[i]->first_fork = &d->mtx_fork[i];
	if (i == d->nb_philos - 1)
		ph[i]->second_fork = &d->mtx_fork[0];
	else
		ph[i]->second_fork = &d->mtx_fork[i + 1];
}

static void	ft_align_forks_for_odd_philo(t_philo **ph, t_args *d, size_t i)
{
	if (i == d->nb_philos - 1)
		ph[i]->first_fork = &d->mtx_fork[0];
	else
		ph[i]->first_fork = &d->mtx_fork[i + 1];
	ph[i]->second_fork = &d->mtx_fork[i];
}

int	ft_align_forks(t_philo **ph, t_args *d)
{
	size_t	i;

	i = 0;
	if (d->nb_philos == 1)
	{
		ph[0]->first_fork = &d->mtx_fork[0];
		return (TRUE);
	}
	while (i < d->nb_philos)
	{
		if (ph[i]->id % 2 == 0)
			ft_align_forks_for_even_philo(ph, d, i);
		else
			ft_align_forks_for_odd_philo(ph, d, i);
		i++;
	}
	return (TRUE);
}
