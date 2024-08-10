/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:18:46 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/07/11 14:14:43 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	destroy_mutex(t_data *da)
{
	int	i;

	pthread_mutex_destroy(&da->table.mutex_table);
	i = 0;
	while (i < da->table.n_philo)
	{
		pthread_mutex_destroy(&da->table.forks[i]);
		pthread_mutex_destroy(&da->philo[i].mutex_philo);
		i++;
	}
}

void	join_threads(t_data *da)
{
	int	i;

	i = 0;
	while (i < da->table.n_philo)
	{
		pthread_join(da->table.threads[i], NULL);
		i++;
	}
}

int	create_threads(t_data *da)
{
	int			i;
	t_philo		*p;
	pthread_t	*t;

	i = 0;
	while (i < da->table.n_philo)
	{
		t = &da->table.threads[i];
		p = &da->philo[i];
		if (pthread_create(t, NULL, philosophers, p))
			return (ft_error("Failed to create threads"), 1);
		i++;
	}
	return (0);
}
