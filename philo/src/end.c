/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:32:44 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/07/23 16:29:14 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	set_philo_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->table.n_philo)
	{
		pthread_mutex_lock(&data->philo[i].mutex_philo);
		data->philo[i].dead = 1;
		pthread_mutex_unlock(&data->philo[i].mutex_philo);
		i++;
	}
}

static void	print_death(t_data *data, int i, const char *action)
{
	long	time;

	time = (get_time() - data->table.start_time) / 1000;
	printf("%ld\t%d\t%s\n", time, data->philo[i].id, action);
}

static int	check_eats(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->table.n_philo)
	{
		if (!has_eaten(&data->philo[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_end(t_data *data)
{
	int		i;

	if (data->table.n_eat != -1 && check_eats(data))
	{
		pthread_mutex_lock(&data->table.mutex_table);
		set_philo_death(data);
		pthread_mutex_unlock(&data->table.mutex_table);
		data->end = 1;
		return ;
	}
	i = 0;
	while (i < data->table.n_philo)
	{
		if (check_death(&data->philo[i]))
		{
			pthread_mutex_lock(&data->table.mutex_table);
			set_philo_death(data);
			print_death(data, i, DEATH);
			pthread_mutex_unlock(&data->table.mutex_table);
			data->end = 1;
			return ;
		}
		i++;
	}
}

void	check_end(t_data *data)
{
	if (data->end)
	{
		pthread_mutex_lock(&data->table.mutex_table);
		set_philo_death(data);
		pthread_mutex_unlock(&data->table.mutex_table);
		return ;
	}
	while (!data->end)
	{
		usleep(3000);
		ft_end(data);
	}
}
