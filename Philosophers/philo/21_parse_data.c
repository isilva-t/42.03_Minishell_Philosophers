/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:42:23 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/14 09:43:22 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_convert_user_input_to_long_vars(char **av, t_args *d)
{
	d->nb_philos = ft_atol_positive(av[1]);
	d->time_to_die = ft_atol_positive(av[2]);
	d->time_to_eat = ft_atol_positive(av[3]);
	d->time_to_sleep = ft_atol_positive(av[4]);
	if (av[5])
		d->nb_must_eat = ft_atol_positive(av[5]);
	else
		d->nb_must_eat = -1;
}

void	ft_check_if_have_bigger_than_int_max(t_args *d)
{
	if (d->nb_philos > INT_MAX)
		d->error_philo = (1 << 5) | d->error_philo;
	if (d->time_to_die > INT_MAX)
		d->error_philo = (1 << 4) | d->error_philo;
	if (d->time_to_eat > INT_MAX)
		d->error_philo = (1 << 3) | d->error_philo;
	if (d->time_to_sleep > INT_MAX)
		d->error_philo = (1 << 2) | d->error_philo;
	if (d->nb_must_eat > INT_MAX)
		d->error_philo = 1 | d->error_philo;
}

void	ft_print_what_happen(int error)
{
	printf("\nYou have error on some input(s):\n\n");
	if (((error >> 5) & 1) == TRUE)
		printf("	=> number_of_philosophers\n");
	if (((error >> 4) & 1) == TRUE)
		printf("	=> time_to_die\n");
	if (((error >> 3) & 1) == TRUE)
		printf("	=> time_to_eat\n");
	if (((error >> 2) & 1) == TRUE)
		printf("	=> time_to_sleep\n");
	if ((error & 1) == TRUE)
		printf("	=> number_of_times_each_philosopher_must_eat\n");
	printf("\nYou tried higher than INT_MAX due(s) on above list.\n");
	ft_print_user_manual();
}

int	ft_parse_data_and_check_error(char **av, t_args *d)
{
	ft_init_variables(d);
	ft_convert_user_input_to_long_vars(av, d);
	ft_check_if_have_bigger_than_int_max(d);
	if (d->error_philo >= TRUE)
		return (ft_print_what_happen(d->error_philo), TRUE);
	return (FALSE);
}
