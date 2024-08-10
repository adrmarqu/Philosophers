/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:06:58 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/07/23 16:16:33 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEATH "died"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_table
{
	int					n_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					n_eat;
	long				start_time;
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		mutex_table;
}	t_table;

typedef struct s_philo
{
	int					id;
	int					n_eat;
	int					dead;
	long				last_meal;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		mutex_philo;
	t_table				tbl;
	t_table				*tbl_dir;
}	t_philo;

typedef struct s_data
{
	int					end;
	t_table				table;
	t_philo				*philo;
}	t_data;

int		init_data(t_data *da, char **av);
int		get_data(t_table *tbl, char **av);

int		atoi_space(char *str, int *nbr);

void	*philosophers(void *arg);
void	print_action(t_philo *p, const char *action);

void	take_forks(t_philo *p);
void	leave_forks(t_philo *p);
void	ft_eat(t_philo *p);
void	ft_sleep(t_philo *p);
void	ft_think(t_philo *p);

int		create_threads(t_data *da);
void	join_threads(t_data *da);
void	destroy_mutex(t_data *da);

void	check_end(t_data *da);

long	get_time(void);
int		has_eaten(t_philo *p);
int		isdeath(t_philo *p);
int		check_death(t_philo *p);

void	ft_error(const char *s);
int		ft_strlen(const char *s);
void	ft_free(t_data *da);

#endif
