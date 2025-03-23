/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:35:32 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/15 07:44:19 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_mtx_the_game_is_over(t_args *d, pthread_t *monitor)
{
	pthread_mutex_lock(&d->mtx_finish_dinner);
	if (d->finish_dinner == TRUE)
	{
		pthread_mutex_unlock(&d->mtx_finish_dinner);
		pthread_join(*monitor, NULL);
		return (TRUE);
	}
	pthread_mutex_unlock(&d->mtx_finish_dinner);
	return (FALSE);
}

static void	ft_start_monitor(t_args *d)
{
	pthread_t	monitor;

	pthread_create(&monitor, NULL, &ft_monitor, (void *)d);
	while (1)
	{
		if (ft_mtx_the_game_is_over(d, &monitor) == TRUE)
			break ;
		usleep (500);
	}
}

int	main(int ac, char **av)
{
	t_args		d;
	t_philo		**ph;

	if (ft_first_args_check_have_error(ac, av) == TRUE)
		return (1);
	if (ft_parse_data_and_check_error(av, &d) == TRUE)
		return (2);
	if (d.nb_philos == 0 || d.nb_must_eat == 0)
		return (0);
	ph = ft_create_philos_mem(&d);
	if (!ph && d.nb_philos > 0)
		return (printf("Error: Can't create Philosophers memory!\n"), 3);
	d.ph = (void **)ph;
	ft_mutex_init(ph, &d);
	ft_align_forks(ph, &d);
	ft_let_the_game_begin(ph, &d);
	usleep (500);
	ft_start_monitor(&d);
	usleep(500);
	ft_mutex_destroy(ph, &d);
	ft_free_philo_mem(ph, &d);
	return (0);
}
