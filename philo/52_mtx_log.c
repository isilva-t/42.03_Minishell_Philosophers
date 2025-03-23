/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   52_mtx_log.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:54:21 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/15 08:40:44 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_print_tab(size_t n_philos)
{
	size_t	i;

	i = 0;
	while (i < n_philos)
	{
		printf("\t\t\t\t");
		i++;
	}
}

void	ft_log(t_philo *ph, char *what_are_doing, size_t n_philos)
{
	size_t	actual_time;

	actual_time = 0;
	pthread_mutex_lock(&ph->d->mtx_died);
	if (ph->d->is_died == FALSE)
	{
		pthread_mutex_unlock(&ph->d->mtx_died);
		pthread_mutex_lock(&ph->d->mtx_log);
		if (TAB == 1)
			ft_print_tab(n_philos);
		actual_time = ft_get_time() - ph->d->start_time;
		printf("%zu\t%d %s\n", actual_time, ph->id, what_are_doing);
		pthread_mutex_unlock(&ph->d->mtx_log);
		return ;
	}
	pthread_mutex_unlock(&ph->d->mtx_died);
}
