/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   51_mtx_have_died_philo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:56:42 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/15 08:56:51 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mtx_have_died_philo(t_philo *ph)
{
	pthread_mutex_lock(&ph->d->mtx_died);
	if (ph->d->is_died == TRUE)
	{
		pthread_mutex_unlock(&ph->d->mtx_died);
		return (TRUE);
	}
	pthread_mutex_unlock(&ph->d->mtx_died);
	return (FALSE);
}
