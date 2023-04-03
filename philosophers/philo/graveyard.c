static void thread_barrier(t_env *env)
{
	static int count = 1;

	pthread_mutex_lock(&(env->common_mtx));
	count++;
	pthread_mutex_unlock(&(env->common_mtx));
	while (1)
	{
		pthread_mutex_lock(&(env->common_mtx));
		if (count == env->arg[N])
		{
			pthread_mutex_unlock(&(env->common_mtx));
			break;
		}
		pthread_mutex_unlock(&(env->common_mtx));
		usleep(1000);
	}
}

	{
		pthread_mutex_lock(&(t->env->mtx[t->id]));
		print_action(t->env, MSG_FORK);
		pthread_mutex_unlock(&(t->env->mtx[t->id]));
		return((void)print_action(t->env, MSG_DIE));
	} // FIXME: not very clean, maybe add custom func
