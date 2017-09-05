#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct peo{
	char name[10];
	int height;
}peo;

int cmp(const void *a, const void *b)
{
	if ((*(peo*)b).height == (*(peo*)a).height)
		return strcmp((*(peo*)a).name, (*(peo*)b).name);
	else
		return (*(peo*)b).height - (*(peo*)a).height;
}

int main()
{
	int N, K, i = 0;
	scanf("%d %d", &N, &K);
	peo *p = (peo*)malloc(sizeof(peo)*N);
	for (i = 0; i<N; ++i)
	{
		scanf("%s %d", (*(p + i)).name, &(*(p + i)).height);
	}
	int perRow = N / K, lastRow = N % K + perRow, pos = 0;
	qsort(p, N, sizeof(peo), cmp);
	int x = 0;
	for (x = lastRow / 2 * 2 - 1; x > 0; x -= 2)
	{
		printf("%s ", (*(p + x)).name);
	}
	for (x = 0; x < lastRow; x += 2)
	{
		if (x == lastRow - 1 || x == lastRow - 2)printf("%s\n", (*(p + x)).name);
		else printf("%s ", (*(p + x)).name);
	}
	for (int j = lastRow; j < N; j += perRow)
	{
		for (x = perRow / 2 * 2 - 1; x + j > j; x -= 2)
		{
			printf("%s ", (*(p + j + x)).name);
		}
		for (x = 0; x < perRow; x += 2)
		{
			if (x == perRow - 1 || x == perRow - 2)printf("%s\n", (*(p + j + x)).name);
			else printf("%s ", (*(p + j + x)).name);
		}
	}
	return 0;
}