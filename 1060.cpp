#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}

int main()
{
	int N, ary[100000], max = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)scanf("%d", ary + i);
	qsort(ary, N, sizeof(int), cmp);
	for (int i = 0; i < N; ++i)
	{
		if (i + 1 >= ary[i])
			break;
		else
			++max;
	}
	printf("%d", max);
	return 0;
}