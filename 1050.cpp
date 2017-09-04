#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}

int main()
{
	int N;
	scanf("%d", &N);
	int *p = (int*)malloc(sizeof(int)*N);
	int *matrix = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i<N; ++i)scanf("%d", p + i);
	qsort(p, N, sizeof(int), cmp);
	int m, n;
	for (m = 0;; ++m)
	{
		if (m*m >= N&&N%m == 0)break;
	}
	n = N / m;
	int horizontal = n, vertical = m, index = 0, y = 0, x = -1;
	while (horizontal>0 && vertical>0)
	{
		for (int i = 0; i<horizontal&&vertical>0; ++i)
			matrix[y*n + ++x] = p[index++];
		--vertical;
		for (int i = 0; i<vertical&&horizontal>0; ++i)
			matrix[++y*n + x] = p[index++];
		--horizontal;
		for (int i = 0; i<horizontal&&vertical>0; ++i)
			matrix[y*n + --x] = p[index++];
		--vertical;
		for (int i = 0; i<vertical&&horizontal>0; ++i)
			matrix[--y*n + x] = p[index++];
		--horizontal;
	}
	for (int i = 0; i<m; ++i)
	for (int j = 0; j<n; ++j)
		printf("%d%c", matrix[i*n + j], (j + 1) % n ? ' ' : '\n');
	return 0;
}