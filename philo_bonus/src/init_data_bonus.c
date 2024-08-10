/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:20:34 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/07/25 17:51:08 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

static int	check_data(t_table *tbl)
{
	if (tbl->n_philo == 0 || tbl->n_philo > 200)
		return (ft_error("Wrong number of philos (1-200)"), 1);
	if (tbl->time_die < 60)
		return (ft_error("Wrong number of time to die (>60)"), 1);
	if (tbl->time_eat < 60)
		return (ft_error("Wrong number of time to eat (>60)"), 1);
	if (tbl->time_sleep < 60)
		return (ft_error("Wrong number of time to sleep (>60)"), 1);
	if (tbl->n_eat == 0)
		return (ft_error("Wrong number of eats (>0)"), 1);
	return (0);
}

int	get_data(t_table *tbl, char **av)
{
	if (atoi_space(av[1], &tbl->n_philo))
		return (1);
	if (atoi_space(av[2], &tbl->time_die))
		return (1);
	if (atoi_space(av[3], &tbl->time_eat))
		return (1);
	if (atoi_space(av[4], &tbl->time_sleep))
		return (1);
	tbl->n_eat = -1;
	if (av[5] && atoi_space(av[5], &tbl->n_eat))
		return (1);
	return (check_data(tbl));
}
