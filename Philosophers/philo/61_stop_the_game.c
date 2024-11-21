/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   61_stop_the_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:48:06 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/14 09:48:08 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_stop_the_game(t_philo **ph, t_args *d)
{
	size_t	i;

	i = 0;
	while (i < d->nb_philos)
	{
		pthread_join(ph[i]->td, NULL);
		i++;
	}
}
