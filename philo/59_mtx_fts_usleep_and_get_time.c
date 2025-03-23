/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   59_mtx_fts_usleep_and_get_time.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:13:34 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/15 07:13:36 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday() function error!\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t ms_time)
{
	size_t	time;

	time = ft_get_time();
	while (ft_get_time() - time < ms_time)
		usleep(500);
}

int	ft_mtx_is_usleep_loop_done(t_philo *ph, size_t ms_time)
{
	size_t	time;
	size_t	end_time;

	time = ft_get_time();
	end_time = time + ms_time;
	while (time < end_time)
	{
		ft_usleep(1);
		time = ft_get_time();
		if (ft_mtx_have_died_philo(ph) == TRUE)
			return (FALSE);
	}
	return (TRUE);
}
