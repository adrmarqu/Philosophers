/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:14:51 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/07/23 16:30:23 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	assign_forks(t_data *da, int idx)
{
	da->philo[idx].right_fork = &da->table.forks[idx];
	if (da->table.n_philo == 1)
		da->philo[idx].left_fork = NULL;
	else
	{
		if (!idx)
			da->philo[idx].left_fork = &da->table.forks[da->table.n_philo - 1];
		else
			da->philo[idx].left_fork = &da->table.forks[idx - 1];
	}
}

static void	assign_vars(t_data *da, int idx)
{
	da->philo[idx].id = idx + 1;
	da->philo[idx].tbl = da->table;
	da->philo[idx].tbl_dir = &da->table;
	da->philo[idx].n_eat = 0;
	da->philo[idx].dead = 0;
	da->philo[idx].last_meal = da->table.start_time;
}

static int	init_philos(t_data *da)
{
	int	i;

	i = 0;
	da->table.start_time = get_time();
	while (i < da->table.n_philo)
	{
		assign_forks(da, i);
		assign_vars(da, i);
		if (pthread_mutex_init(&da->philo[i].mutex_philo, NULL))
			return (ft_error("Failed to init mutex"), 1);
		i++;
	}
	return (0);
}

static int	init_forks(t_table *tbl)
{
	int	i;

	if (pthread_mutex_init(&tbl->mutex_table, NULL))
		return (ft_error("Failed to init mutex"), 1);
	i = 0;
	while (i < tbl->n_philo)
	{
		if (pthread_mutex_init(&tbl->forks[i], NULL))
			return (ft_error("Failed to init mutex"), 1);
		i++;
	}
	return (0);
}

int	init_data(t_data *da, char **av)
{
	if (get_data(&da->table, av))
		return (1);
	da->philo = malloc(da->table.n_philo * sizeof(t_philo));
	da->table.threads = malloc(da->table.n_philo * sizeof(t_philo));
	da->table.forks = malloc(da->table.n_philo * sizeof(t_philo));
	if (!da->philo || !da->table.forks || !da->table.threads)
		return (ft_free(da), ft_error("Memory reservation failed"), 1);
	if (init_forks(&da->table) || init_philos(da))
		return (destroy_mutex(da), ft_free(da), 1);
	return (0);
}
