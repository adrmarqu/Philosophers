/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:26:42 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/07/11 13:59:31 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static char	*delete_space(char *s)
{
	int		i;
	int		j;
	char	*str;

	if (!s || !*s)
		return (ft_error("Wrong data (no data)"), NULL);
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (ft_error("Memory reservation failed"), NULL);
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
		str[j++] = s[i++];
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i])
	{
		free(str);
		return (ft_error("Wrong data"), NULL);
	}
	str[j] = '\0';
	return (str);
}

int	atoi_space(char *str, int *nbr)
{
	long	n;
	int		i;
	char	*num;

	num = delete_space(str);
	if (!num)
		return (1);
	i = 0;
	if (num [i] == '-')
		return (free(num), ft_error("Wrong data (negative)"), 1);
	else if (num [i] == '+')
		i++;
	n = 0;
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (free(num), ft_error("Wrong data (no number)"), 1);
		n = n * 10 + num[i++] - '0';
	}
	if (ft_strlen(num) > 12 || n > INT_MAX)
		return (ft_error("Data out of limits (int)"), 1);
	free(num);
	*nbr = (int)n;
	return (0);
}
