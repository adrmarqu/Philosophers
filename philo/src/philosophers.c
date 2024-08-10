/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:52:33 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/07/20 13:24:45 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_action(t_philo *p, const char *action)
{
	long	time;

	pthread_mutex_lock(&p->tbl_dir->mutex_table);
	if (!isdeath(p))
	{
		time = (get_time() - p->tbl.start_time) / 1000;
		printf("%ld\t%d\t%s\n", time, p->id, action);
	}
	pthread_mutex_unlock(&p->tbl_dir->mutex_table);
}

void	*philosophers(void *arg)
{
	t_philo	*p;

	p = arg;
	if (p->tbl.n_philo == 1)
	{
		print_action(p, FORK);
		return (NULL);
	}
	if (p->id % 2)
		usleep(p->tbl.time_eat * 500);
	while (!isdeath(p))
	{
		take_forks(p);
		ft_eat(p);
		leave_forks(p);
		ft_sleep(p);
		ft_think(p);
	}
	return (NULL);
}
