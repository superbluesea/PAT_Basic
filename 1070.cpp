#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int N;
	scanf("%d", &N);
	int *r = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i<N; ++i)scanf("%d", &r[i]);
	qsort(r, N, sizeof(int), cmp);
	double d = (double)r[0] / 2;
	for (int i = 1; i<N; ++i)
	{
		if (i == N - 1)
			d = d + (double)r[i] / 2;
		else
			d = (d + (double)r[i] / 2) / 2;
	}
	printf("%d\n", (int)d);
	return 0;
}