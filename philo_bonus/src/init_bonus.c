/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:14:51 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/08/02 15:21:27 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

static void	assign_vars(t_data *da, int idx)
{
	da->philo[idx].id = idx + 1;
	da->philo[idx].tbl = da->table;
	da->philo[idx].tbl_dir = &da->table;
	da->philo[idx].n_eat = 0;
	da->philo[idx].last_meal = da->table.start_time;
}

static void	init_philos(t_data *da)
{
	int	i;

	da->table.start_time = get_time();
	i = 0;
	while (i < da->table.n_philo)
	{
		assign_vars(da, i);
		i++;
	}
}

int	init_data(t_data *da, char **av)
{
	if (get_data(&da->table, av))
		return (1);
	da->philo = malloc(da->table.n_philo * sizeof(t_philo));
	if (!da->philo)
		return (ft_error("Memory reservation"), 1);
	open_sem(&da->table);
	init_philos(da);
	return (0);
}
