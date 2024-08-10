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
	tv.tv_sec %= 31556925;
	return (tv.tv_sec * 1e6 + tv.tv_usec);
}

int	check_death(t_philo *p)
{
	int		dead;

	dead = 0;
	if (((get_time() - p->last_meal) / 1000) > p->tbl.time_die)
		dead = 1;
	return (dead);
}
