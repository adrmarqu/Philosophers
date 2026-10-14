/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:17:51 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/08/02 14:39:41 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long)tv.tv_sec * 1000000 + tv.tv_usec);
}

void	ft_usleep(long time_in_ms)
{
	long	start;

	start = get_time();
	while ((get_time() - start) / 1000 < time_in_ms)
		usleep(250);
}

int	check_death(t_philo *p)
{
	int		dead;

	dead = 0;
	if (((get_time() - p->last_meal) / 1000) > p->tbl.time_die)
		dead = 1;
	return (dead);
}
