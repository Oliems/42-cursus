// TODO Add timestamp (save time when program start and print curr - start time)
static int philo(t_env *env)
{
	int r;
	int i;

	i = 0;
	r = 0;
	while(1)
	{
		while (i < env->np)
		{
			if (!i)
			{
				r = pthread_mutex_lock(env->phi[i].mtx);
				if (r != 0)
					return (r);
				printf("%d has taken a fork", env->phi[i].phid);
				pthread_mutex_lock(env->phi[env->np - 1].mtx);
				if (r != 0)
					return (r);
				printf("%d has taken a fork", env->phi[i].phid);
				printf("%d is eating", env->phi[i].phid);
				usleep(env->te);
								r = pthread_mutex_lock(env->phi[i].mtx);
				if (r != 0)
					return (r);
				printf("%d has taken a fork", env->phi[i].phid);
				pthread_mutex_lock(env->phi[env->np - 1].mtx);
				if (r != 0)
					return (r);

			}
			else if
			{

			}
			else
			{

			}
		i++;
		}

	}
}

	printf("np=%d, td=%ld, te=%ld, ts=%ld, n=%d\n", env->np, env->td, env->te, env->ts, env->n);

typedef struct
{
	int				phid;
	pthread_t		th;
	pthread_mutex_t	mtx;
} t_thread;
