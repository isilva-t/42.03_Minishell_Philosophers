/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   43_mtx_fts_all_tds_running.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:12:53 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/15 08:47:43 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mtx_are_all_threads_running(t_philo *ph)
{
	usleep(10);
	pthread_mutex_lock(&ph->d->mtx_all_tds_running);
	if (ph->d->all_tds_running == TRUE)
	{
		pthread_mutex_unlock(&ph->d->mtx_all_tds_running);
		return (TRUE);
	}
	pthread_mutex_unlock(&ph->d->mtx_all_tds_running);
	return (FALSE);
}

void	ft_mtx_increase_created_threads(t_args *d)
{
	pthread_mutex_lock(&d->mtx_all_tds_running);
	d->all_tds_running = TRUE;
	pthread_mutex_unlock(&d->mtx_all_tds_running);
}
