/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:00:41 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/08/02 15:31:24 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	put_sem_wait(t_data *da)
{
	int	i;

	i = 0;
	while (i < da->table.n_philo)
	{
		sem_wait(da->table.meal_sem);
		i++;
	}
}

void	put_sem_post(t_data *da)
{
	int	i;

	i = 0;
	while (i < da->table.n_philo)
	{
		sem_post(da->table.meal_sem);
		i++;
	}
}

void	ft_close(t_data *da)
{
	sem_close(da->table.forks_sem);
	sem_close(da->table.table_sem);
	sem_close(da->table.end_sem);
	sem_close(da->table.meal_sem);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_TABLE);
	sem_unlink(SEM_END);
	sem_unlink(SEM_MEAL);
}

void	open_sem(t_table *t)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_TABLE);
	sem_unlink(SEM_END);
	sem_unlink(SEM_MEAL);
	t->forks_sem = sem_open(SEM_FORKS, O_CREAT, 0644, t->n_philo);
	t->table_sem = sem_open(SEM_TABLE, O_CREAT, 0644, 1);
	t->end_sem = sem_open(SEM_END, O_CREAT, 0644, 1);
	t->meal_sem = sem_open(SEM_MEAL, O_CREAT, 0644, t->n_philo);
}
