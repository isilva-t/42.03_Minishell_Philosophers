/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:37:38 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/14 09:39:45 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_variables(t_args *d)
{
	d->nb_philos = 0;
	d->forks = 0;
	d->time_to_die = 0;
	d->time_to_eat = 0;
	d->time_to_sleep = 0;
	d->nb_must_eat = 0;
	d->is_died = 0;
	d->error_philo = 0;
	d->all_eaten = 0;
	d->finish_dinner = 0;
	d->all_tds_running = 0;
}
