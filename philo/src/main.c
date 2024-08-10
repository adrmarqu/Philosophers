/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:11:18 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/07/25 17:46:37 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	check_n_arg(int n)
{
	if (n < 5)
		return (ft_error("Too few arguments"), 1);
	else if (n > 6)
		return (ft_error("Too many arguments"), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_n_arg(ac) || init_data(&data, av))
		return (1);
	data.end = create_threads(&data);
	check_end(&data);
	join_threads(&data);
	destroy_mutex(&data);
	ft_free(&data);
	return (0);
}
