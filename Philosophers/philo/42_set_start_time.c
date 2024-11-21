/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42_set_start_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:12:40 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/15 07:12:42 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_set_start_time(t_args *d, t_philo **ph)
{
	size_t	i;
	size_t	nb_philos;
	size_t	start_time;

	i = 0;
	nb_philos = d->nb_philos;
	start_time = ft_get_time();
	d->start_time = start_time;
	while (i < nb_philos)
		ph[i++]->last_meal = start_time;
}
