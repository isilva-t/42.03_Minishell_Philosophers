/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   81_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:51:09 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/14 09:54:48 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_atol_positive(const char *nptr)
{
	int		i;
	size_t	num;

	i = 0;
	num = 0;
	while (nptr[i] && nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + nptr[i++] - '0';
	return (num);
}

void	ft_print_user_manual(void)
{
	printf("\nTo start the dinner, use between FOUR or FIVE arguments.\n");
	printf("Fifth argument is optional.\n");
	printf("Do not use negative numbers, or above INT_MAX.\n");
	printf("Arguments description:\n");
	printf("[0] prog_name\n");
	printf("[1] number_of_philos\n");
	printf("[2] time_to_die\n");
	printf("[3] time_to_eat\n");
	printf("[4] time_to_sleep\n");
	printf("[5] number_of_times_each_philosopher_must_eat\n\n");
	printf("Examples (with or without fifth argument:\n");
	printf("./philo 5 800 200 200 7\n");
	printf("./philo 2 800 200 200\n\n");
}
