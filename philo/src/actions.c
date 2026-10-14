/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:06:01 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/07/20 13:28:23 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	take_forks(t_philo *p)
{
	pthread_mutex_lock(p->right_fork);
	print_action(p, FORK);
	pthread_mutex_lock(p->left_fork);
	print_action(p, FORK);
}

void	leave_forks(t_philo *p)
{
	pthread_mutex_unlock(p->right_fork);
	pthread_mutex_unlock(p->left_fork);
}

void	ft_eat(t_philo *p)
{
	pthread_mutex_lock(&p->mutex_philo);
	p->last_meal = get_time();
	p->n_eat++;
	pthread_mutex_unlock(&p->mutex_philo);
	print_action(p, EAT);
	ft_usleep(p->tbl.time_eat, p);
}

void	ft_sleep(t_philo *p)
{
	print_action(p, SLEEP);
	ft_usleep(p->tbl.time_sleep, p);
}

void	ft_think(t_philo *p)
{
	print_action(p, THINK);
}
