/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:06:14 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/08/02 15:31:03 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	kill_process(pid_t pid)
{
	if (kill(pid, SIGTERM) == -1)
	{
		ft_error("Failed to kill process");
		return ;
	}
	if (waitpid(pid, NULL, 0) == -1)
	{
		ft_error("Failed to waitpid process");
		return ;
	}
}

void	kill_all(t_data *da)
{
	int	i;

	i = 0;
	while (i < da->table.n_philo)
	{
		kill_process(da->philo[i].pid);
		i++;
	}
}

void	create_pid(t_data *da)
{
	int		i;

	i = 0;
	while (i < da->table.n_philo)
	{
		da->philo[i].pid = fork();
		if (da->philo[i].pid == 0)
		{
			philosophers(&da->philo[i]);
			exit(0);
		}
		i++;
		usleep(100);
	}
}
