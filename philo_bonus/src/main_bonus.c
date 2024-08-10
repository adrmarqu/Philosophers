/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:11:18 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/08/10 13:59:19 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

static int	check_n_arg(int n)
{
	if (n < 5)
		return (ft_error("Too few arguments"), 1);
	else if (n > 6)
		return (ft_error("Too many arguments"), 1);
	return (0);
}

static void	ft_end(t_data *data)
{
	pid_t	pid;

	sem_wait(data->table.end_sem);
	if (data->table.n_eat != -1)
	{
		pid = fork();
		if (pid == 0)
		{
			put_sem_wait(data);
			put_sem_wait(data);
			put_sem_post(data);
			sem_post(data->table.end_sem);
			exit(0);
		}
	}
	sem_wait(data->table.end_sem);
	sem_post(data->table.end_sem);
	if (data->table.n_eat != -1)
		kill_process(pid);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_n_arg(ac) || init_data(&data, av))
		return (1);
	create_pid(&data);
	ft_end(&data);
	kill_all(&data);
	ft_close(&data);
	free(data.philo);
	return (0);
}
