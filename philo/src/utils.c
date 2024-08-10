/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:15:17 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/07/20 13:27:52 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_error(const char *s)
{
	printf("Error: %s\n", s);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_free(t_data *da)
{
	if (da->table.threads)
		free(da->table.threads);
	if (da->table.forks)
		free(da->table.forks);
	if (da->philo)
		free(da->philo);
}
