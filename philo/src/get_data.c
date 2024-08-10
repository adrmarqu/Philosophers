/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:17:51 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/07/20 13:51:50 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	tv.tv_sec %= 31556925;
	return (tv.tv_sec * 1e6 + tv.tv_usec);
}

int	has_eaten(t_philo *p)
{
	int	eat;

	eat = 0;
	pthread_mutex_lock(&p->mutex_philo);
	if (p->n_eat >= p->tbl.n_eat)
		eat = 1;
	pthread_mutex_unlock(&p->mutex_philo);
	return (eat);
}

int	isdeath(t_philo *p)
{
	int	dead;

	pthread_mutex_lock(&p->mutex_philo);
	dead = p->dead;
	pthread_mutex_unlock(&p->mutex_philo);
	return (dead);
}

int	check_death(t_philo *p)
{
	int		dead;

	dead = 0;
	pthread_mutex_lock(&p->mutex_philo);
	if (((get_time() - p->last_meal) / 1000) > p->tbl.time_die)
		dead = 1;
	pthread_mutex_unlock(&p->mutex_philo);
	return (dead);
}
