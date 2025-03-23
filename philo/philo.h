/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:49:51 by isilva-t          #+#    #+#             */
/*   Updated: 2024/11/14 10:38:14 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# ifndef TAB
#  define TAB 0
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

# define RED "\e[1;3;31m"
# define GREEN "\e[1;3;32m"
# define YELLOW "\e[1;3;93m"
# define RESET "\e[0m"

# define S_FORK "has taken a fork"
# define S_EATING "is eating"
# define S_SLEEPING "is sleeping"
# define S_THINKING "is thinking"
# define S_DIED "died"
# define LEFT 0
# define RIGHT 1

# define INVALID -1
# define TRUE 1
# define TRUE_VERIFYED 2
# define FALSE 0

# define THO 1000

# define MAX_PHILO 250
# define MIN_TIME 60

typedef struct s_args
{
	pthread_mutex_t	*mtx_fork;
	pthread_mutex_t	mtx_log;
	pthread_mutex_t	mtx_died;
	size_t			is_died;
	pthread_mutex_t	mtx_finish_dinner;
	size_t			finish_dinner;
	pthread_mutex_t	mtx_all_tds_running;
	size_t			all_tds_running;
	void			**ph;
	size_t			start_time;
	size_t			nb_philos;
	size_t			forks;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			all_eaten;
	long			nb_must_eat;
	int				error_philo;
}	t_args;

typedef struct s_philo
{
	pthread_t		td;
	unsigned int	index;
	unsigned int	id;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	pthread_mutex_t	mtx_philo;
	pthread_mutex_t	mtx_eat_done;
	size_t			start_delay;
	size_t			last_meal;
	unsigned int	n_meals;
	unsigned int	max_meals;
	unsigned int	eating_done;
	size_t			n_philos;
	int				usleep_done;
	t_args			*d;
}	t_philo;

// init vars
void	ft_init_variables(t_args *val);
// 10_Argument check
int		ft_first_args_check_have_error(int ac, char **av);
// 20_parse data
int		ft_parse_data_and_check_error(char **av, t_args *val);

// 30_prepare restaurant
t_philo	**ft_create_philos_mem(t_args *d);
// 35_align_forks
int		ft_align_forks(t_philo **ph, t_args *d);

// 41
int		ft_let_the_game_begin(t_philo **ph, t_args *d);
// 42
void	ft_set_start_time(t_args *d, t_philo **ph);
// 43_mtx_fts_all_tds_running
int		ft_mtx_are_all_threads_running(t_philo *ph);
void	ft_mtx_increase_created_threads(t_args *d);
// 44_mtx_fts_forks
void	ft_mtx_take_forks(t_philo *ph);
void	ft_mtx_leave_forks(t_philo *ph);
// 45
void	ft_mtx_save_meal_time(t_philo *ph);
// 46
int		ft_mtx_have_reached_max_meals(t_philo *ph);

// 49_monitor
void	*ft_monitor(void *arg);

//50 mutex_helper_functions
//51
int		ft_mtx_have_died_philo(t_philo *ph);
//52
void	ft_log(t_philo *ph, char *what_are_doing, size_t n_philos);
//59 mtx_fts_usleep_and_get_time
size_t	ft_get_time(void);
void	ft_usleep(size_t time);
int		ft_mtx_is_usleep_loop_done(t_philo *ph, size_t ms_time);

// 61
void	ft_stop_the_game(t_philo **ph, t_args *d);

//71_mutex_init_and_destroy
int		ft_mutex_init(t_philo **ph, t_args *d);
int		ft_mutex_destroy(t_philo **ph, t_args *d);

//81_utils
int		ft_isdigit(int c);
size_t	ft_atol_positive(const char *nptr);
void	ft_print_user_manual(void);

// 91_free_and_cleanup
int		ft_free_philo_mem(t_philo **ph, t_args *d);

#endif
