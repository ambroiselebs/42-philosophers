/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 19:00:48 by aberenge          #+#    #+#             */
/*   Updated: 2025-01-26 20:01:59 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

# define RST "\033[0m"
# define RED "\033[1;31m"
# define G "\033[1;21m"
# define Y "\033[1;33m"
# define B "\033[1;34m"
# define M "\033[1;35m"
# define C "\033[1;36m"
# define W "\033[1;37m"

/*
	n 			= Id philo
	m_count		= nb repas mage
	is_eating	= bool si mage
	thread		= thread associe au philo
	last_eat	= temps depuis dernier repas
	info		= lien vers t_info
	fork_r		= fourchette droite
	fork_l		= fourchette gauche
*/
typedef struct s_philo
{
	int				n;
	int				m_count;
	bool			is_eating;
	pthread_t		thread;
	long int		last_eat;
	struct s_info	*info;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	fork_l;
}	t_philo;

/*
	philo_eat		= total repas consomme
	n_philo			= nb total de philo
	t_die			= temps avant meurt de faim
	t_eat			= temps qui met a manger
	t_sleep			= temps de repos
	n_eat			= nb de repas avant fin
	stop			= bool en cours/fin
	t_start			= timestamp du debut de la simu
	*philo			= tableau de philos
	print			= mutex pour gerer les print
	m_stop			= mutex pour gerer l'arret de la simu
	m_eat			= mutex pour gerer l'acces aux repas
	dead			= mutex piur gerer la mort
*/
typedef struct s_info
{
	int				philo_eat;
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				stop;
	long int		t_start;
	t_philo			*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	m_stop;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	dead;
}	t_info;

void		ft_usleep(int ms);
int			philo_init(t_info *data);
void		*philo_life(void *philo);
long long	timestamp(void);
int			var_init(t_info *data, char **av);
void		*philo_life(void *phi);
void		print(t_philo *philo, char *str);
int			is_dead(t_philo *philo, int nb);
int			ft_isdigit(int character);
int			ft_atoi(const char *str);

#endif
