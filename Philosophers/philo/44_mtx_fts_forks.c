/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   44_mtx_fts_forks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:13:04 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/15 07:13:06 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mtx_take_forks(t_philo *ph)
{
	pthread_mutex_lock(ph->first_fork);
	ft_log(ph, S_FORK, ph->index);
	pthread_mutex_lock(ph->second_fork);
	ft_log(ph, S_FORK, ph->index);
}

void	ft_mtx_leave_forks(t_philo *ph)
{
	pthread_mutex_unlock(ph->second_fork);
	pthread_mutex_unlock(ph->first_fork);
}
