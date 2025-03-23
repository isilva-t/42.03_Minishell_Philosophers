/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   46_mtx_have_reached_max_meals.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:13:23 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/15 07:13:24 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mtx_have_reached_max_meals(t_philo *ph)
{
	if (ph->n_meals == ph->max_meals)
	{
		pthread_mutex_lock(&ph->mtx_eat_done);
		ph->eating_done = TRUE;
		pthread_mutex_unlock(&ph->mtx_eat_done);
		return (TRUE);
	}
	return (FALSE);
}
