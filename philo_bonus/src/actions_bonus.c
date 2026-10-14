/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:31:40 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/08/01 13:49:03 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	take_forks(t_philo *p)
{
	sem_wait(p->tbl_dir->forks_sem);
	print_action(p, FORK);
	sem_wait(p->tbl_dir->forks_sem);
	print_action(p, FORK);
}

void	leave_forks(t_philo *p)
{
	sem_post(p->tbl_dir->forks_sem);
	sem_post(p->tbl_dir->forks_sem);
}

void	ft_eat(t_philo *p)
{
	p->last_meal = get_time();
	p->n_eat++;
	print_action(p, EAT);
	ft_usleep(p->tbl.time_eat);
}

void	ft_sleep(t_philo *p)
{
	print_action(p, SLEEP);
	ft_usleep(p->tbl.time_sleep);
}
