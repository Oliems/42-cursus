static int	thread_monitor_full(t_env *env)
{
	int	c;
	int	i;

	i = 0;
	c = 0;
	pthread_mutex_lock(&(env->common_mtx));
	while (i < env->arg[N])
	{
		if (env->full[i] == true)
			c++;
		i++;
	}
	if (c == env->arg[N])
	{
		printf("All philosophers have eaten %d times.\n", env->arg[LIM]);
		env->exit = true;
		pthread_mutex_unlock(&(env->common_mtx));
		return (1);
	}
	pthread_mutex_unlock(&(env->common_mtx));
	usleep(1000);
	return (0);
}

// Might be more efficient to check both ends at the same time and converg towards middle
static int	thread_monitor_death(t_env *env)
{
	int			i;
	time_t		now;
	time_t		delta;

	i = 0;
	now = time_now();
	pthread_mutex_lock(&(env->common_mtx));
	while (i < env->arg[N])
	{
		delta = now - env->last_meal[i];
		if (delta >= env->arg[T2D])
		{
			printf("%ld %d %s\n", now - env->start, i + 1, MSG_DIE);
			env->exit = true;
			pthread_mutex_unlock(&(env->common_mtx));
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&(env->common_mtx));
	usleep(100);
	return (0);
}

void	thread_monitor(t_env *env)
{
	while (1)
	{
		if (thread_monitor_full(env))
			break ;
		if (thread_monitor_death(env))
			break ;
	}
}



static void	thread_eat(t_thread *t, int fork1, int fork2)
{
	pthread_mutex_lock(&(t->env->mtx[fork1]));
	print_action(t->env, t->id, MSG_FORK);
	pthread_mutex_lock(&(t->env->mtx[fork2]));
	print_action(t->env, t->id, MSG_FORK);
	print_action(t->env, t->id, MSG_EAT);
	pthread_mutex_lock(&(t->env->common_mtx));
	t->env->last_meal[t->id] = time_now();
	pthread_mutex_unlock(&(t->env->common_mtx));
	my_usleep(t->env->arg[T2E]);
	pthread_mutex_unlock(&(t->env->mtx[fork1]));
	pthread_mutex_unlock(&(t->env->mtx[fork2]));
	t->nmeal++;
	if (t->nmeal == t->env->arg[LIM] && t->env->full[t->id] == false)
	{
		pthread_mutex_lock(&(t->env->common_mtx));
		t->env->full[t->id] = true;
		pthread_mutex_unlock(&(t->env->common_mtx));
	}
}








static int thread_monitor_full(t_env *env)
{
	if (env->nfull == env->arg[N])
	{
		printf("All philosophers have eaten %d times.\n", env->arg[LIM]);
		env->exit = true;
		return (1);
	}
	return (0);
}

static int thread_monitor_death(t_env *env, int i)
{
	time_t now;
	time_t delta;

	now = time_now();
	delta = now - env->last_meal[i];
	if (delta >= env->arg[T2D])
	{
		printf("%ld %d %s\n", now - env->start, i + 1, MSG_DIE);
		env->exit = true;
		return (1);
	}
	return (0);
}

// Might be more efficient to check both ends at the same time and converg towards middle
void thread_monitor(t_env *env)
{
	int i;

	i = 0;
	while (1)
	{
		if (i == env->arg[N])
			i = 0;
		pthread_mutex_lock(&(env->common_mtx));
		if (thread_monitor_death(env, i) || thread_monitor_full(env))
		{
			pthread_mutex_unlock(&(env->common_mtx));
			return;
		}
		pthread_mutex_unlock(&(env->common_mtx));
		i++;
		usleep(100);
	}
}
