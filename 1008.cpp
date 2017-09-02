#include<stdio.h>

int main()
{
	int N, M;
	int a[101];
	scanf("%d %d", &N, &M);
	int i = 1;
	while (i <= N)
	{
		if (M > N)
		{
			M = M%N;
		}
		if (i <= N - M)
			scanf("%d", &a[i + M]);
		else
			scanf("%d", &a[M - N + i]);
		++i;
	}
	i = 1;
	while (i <= N)
	{
		if (i == N)printf("%d", a[i++]);
		else printf("%d ", a[i++]);
	}
	return 0;
}