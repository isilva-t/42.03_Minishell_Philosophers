/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   91_free_and_cleanup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 06:53:54 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/14 09:57:27 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free_philo_mem(t_philo **ph, t_args *d)
{
	size_t	i;

	i = 0;
	while (i < d->nb_philos)
	{
		free(ph[i]);
		i++;
	}
	free(ph);
	return (TRUE);
}
