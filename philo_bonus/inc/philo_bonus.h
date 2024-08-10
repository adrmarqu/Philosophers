/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:06:58 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/08/02 16:54:58 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEATH "died"

# define SEM_FORKS "forks"
# define SEM_TABLE "table"
# define SEM_END "end"
# define SEM_MEAL "meal"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <limits.h>

typedef struct s_table
{
	int					n_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					n_eat;
	long				start_time;
	sem_t				*forks_sem;
	sem_t				*table_sem;
	sem_t				*end_sem;
	sem_t				*meal_sem;
}	t_table;

typedef struct s_philo
{
	int					id;
	int					n_eat;
	long				last_meal;
	pid_t				pid;
	t_table				tbl;
	t_table				*tbl_dir;
}	t_philo;

typedef struct s_data
{
	t_table				table;
	t_philo				*philo;
}	t_data;

int		init_data(t_data *da, char **av);
int		get_data(t_table *tbl, char **av);

void	ft_close(t_data *da);
void	open_sem(t_table *t);
void	put_sem_wait(t_data *data);
void	put_sem_post(t_data *data);

void	kill_process(pid_t pid);
void	kill_all(t_data *da);
void	create_pid(t_data *da);

void	philosophers(t_philo *p);

void	take_forks(t_philo *p);
void	leave_forks(t_philo *p);
void	ft_eat(t_philo *p);
void	ft_sleep(t_philo *p);

long	get_time(void);
int		check_death(t_philo *p);

void	ft_error(const char *s);
int		ft_strlen(const char *s);
void	print_action(t_philo *p, const char *action);
int		atoi_space(char *str, int *nbr);

#endif
