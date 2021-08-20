/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_states.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:03:02 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/20 15:31:29 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/// Prints the message status as required per subject
/// Ex: "2000 1 is sleeping"
static	void	ft_print_status(t_philo *philo, int state)
{
	int	time_elapsed;

	time_elapsed = philo->current_time - philo->start_time;
	ft_putnbr_fd(time_elapsed, STDOUT);
	ft_putchar_fd('\t', STDOUT);
	ft_putnbr_fd(philo->philo_number, STDOUT);
	ft_putchar_fd('\t', STDOUT);
	if (state == EATING)
		ft_putendl_fd("is eating", STDOUT);
	else if (state == TOOK_A_FORK)
		ft_putendl_fd("has taken a fork", STDOUT);
	else if (state == SLEEPING)
		ft_putendl_fd("is sleeping", STDOUT);
	else if (state == THINKING)
		ft_putendl_fd("is thinking", STDOUT);
	else if (state == DIED)
		ft_putendl_fd("died", STDOUT);
}

void	ft_eat(t_philo *philo)
{
	int	time_to_eat;

	pthread_mutex_lock(philo->left_fork);
	ft_print_status(philo, TOOK_A_FORK);
	pthread_mutex_lock(philo->right_fork);
	ft_print_status(philo, TOOK_A_FORK);
	time_to_eat = philo->t_to_eat;
	if (ft_get_current_time(philo) == -1)
		return ;
	ft_print_status(philo, EATING);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	ft_sleep(t_philo *philo)
{
	if (!philo)
		return (0);
	return (0);
}

int	ft_think(t_philo *philo)
{
	if (!philo)
		return (0);
	return (0);
}
