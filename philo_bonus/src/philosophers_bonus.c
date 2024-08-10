/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:52:33 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/08/02 17:02:49 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	*philo_end(void *arg)
{
	t_philo	*p;
	int		eated;

	p = arg;
	eated = 0;
	if (p->tbl.n_eat == -1)
		eated = 1;
	while (1)
	{
		if (!eated && p->tbl.n_eat != -1 && p->n_eat >= p->tbl.n_eat)
		{
			eated = 1;
			sem_post(p->tbl_dir->meal_sem);
		}
		if (check_death(p))
		{
			print_action(p, DEATH);
			sem_wait(p->tbl_dir->table_sem);
			sem_post(p->tbl_dir->end_sem);
			return (NULL);
		}
		usleep(3000);
	}
}

void	philosophers(t_philo *p)
{
	pthread_t	end;

	pthread_create(&end, NULL, philo_end, p);
	pthread_detach(end);
	while (1)
	{
		take_forks(p);
		ft_eat(p);
		leave_forks(p);
		ft_sleep(p);
		print_action(p, THINK);
	}
}
