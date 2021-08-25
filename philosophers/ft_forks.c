/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:36:39 by ysoroko           #+#    #+#             */
/*   Updated: 2021/08/25 11:52:05 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	ft_one_philo_fork(t_philo *ph)
{
	pthread_mutex_t	*left_fork;

	left_fork = malloc(sizeof(*left_fork));
	if (!left_fork)
		return (ft_puterr("Failed to malloc a mutex fork"));
	if (pthread_mutex_init(left_fork, NULL))
		return (ft_free_int_ret(left_fork, "Failed to init a mutex fork", -1));
	ph->left_fork = left_fork;
	ph->right_fork = NULL;
	return (0);
}

/// This function creates a mutex for every fork and assigns 2 forks to
/// every philosopher, both shared with neighbours.
/// Returns 0 in case of success or -1 in case of an error
int	ft_initialize_forks_mutex(t_philo *ph, int n, t_philo *prev, t_philo *f)
{
	pthread_mutex_t	*left_fork;

	if (n == 1)
		return (ft_one_philo_fork(ph));
	left_fork = malloc(sizeof(*left_fork));
	if (!left_fork)
		return (ft_puterr("Failed to malloc a mutex fork"));
	if (pthread_mutex_init(left_fork, NULL))
		return (ft_free_int_ret(left_fork, "Failed to init a mutex fork", -1));
	if (!prev)
		ph->left_fork = left_fork;
	else if (ph->philo_number == n)
	{
		ph->left_fork = left_fork;
		ph->right_fork = f->left_fork;
		prev->right_fork = left_fork;
	}
	else
	{
		ph->left_fork = left_fork;
		prev->right_fork = left_fork;
	}
	return (0);
}
