/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   45_mtx_save_meal_time.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:13:15 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/15 07:13:16 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mtx_save_meal_time(t_philo *ph)
{
	pthread_mutex_lock(&ph->mtx_philo);
	ph->last_meal = ft_get_time();
	pthread_mutex_unlock(&ph->mtx_philo);
	ph->n_meals++;
}
