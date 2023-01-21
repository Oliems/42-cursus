static void	ft_swap(void *i, void *j)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned char	tmp;

	a = (unsigned char *)i;
	b = (unsigned char *)j;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_permute(void *b, int n)
{
	int				k;
	int				l;
	int				lo;
	int				hi;
	unsigned char	*p;

	k = n - 2;
	p = (unsigned char *)b;
	while (k >= 0 && p[k] > p[k + 1])
		k--;
	if (k < 0)
		return (0);
	l = n - 1;
	while (p[k] > p[l])
		l--;
	ft_swap(&p[k], &p[l]);
	lo = k + 1;
	hi = n - 1;
	while (lo < hi)
		ft_swap(&p[lo++], &p[hi--]);
	return (1);
}

#include <stdio.h>

int main(void)
{
	int t[6] = {0, 1, 2, 3, 4, 5};
	// char s[6] = "012345";

/* 	while (ft_permute(s, 6))
		printf("%s\n", s); */

		while (ft_permute(t, 6))
			;

	for (int i = 0; i != 6; i++)
		printf("%d", t[i]);
	printf("\n");
}
