/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_first_args_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:40:57 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/14 09:42:14 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_have_only_digits_in_numbers(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			while (av[i][j] == '+')
				j++;
			if (ft_isdigit(av[i][j]) == FALSE)
				return (FALSE);
		}
	}
	return (TRUE);
}

int	ft_first_args_check_have_error(int ac, char **av)
{
	int	rt;

	rt = 0;
	if (ac < 5 || ac > 6)
		rt = printf("\nNumber of arguments incorrect!\n");
	else if (ft_have_only_digits_in_numbers(av) == FALSE)
		rt = printf("\nPlease, only numbers (not negative) on arguments!\n");
	if (rt > 0)
		return (ft_print_user_manual(), TRUE);
	else
		return (FALSE);
}
