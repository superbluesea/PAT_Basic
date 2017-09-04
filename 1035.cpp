#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int N, srcAry[100], destAry[100], i, j;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)scanf("%d", &srcAry[i]);
	for (i = 0; i < N; ++i)scanf("%d", &destAry[i]);
	//equal
	for (i = 0; i < N - 1 && destAry[i] <= destAry[i + 1]; ++i);
	for (j = i + 1; j < N&&srcAry[j] == destAry[j]; ++j);
	if (j == N)
	{
		if (i == N - 1)i += 1; else i += 2;
		printf("Insertion Sort\n");
		qsort(srcAry, i, sizeof(int), cmp);
	}
	else
	{
		printf("Merge Sort\n");
		int flag = 1;
		for (int k = 1; k <= N&&flag; k *= 2)
		{
			int index;
			for (index = 0; index < N&&srcAry[index] == destAry[index]; ++index);
			if (index == N)
				flag = 0;
			for (j = 0; j < N / k; ++j)
				qsort(srcAry + j*k, k, sizeof(int), cmp);
			qsort(srcAry + j*k, N%k, sizeof(int), cmp);
		}
	}
	for (i = 0; i < N; ++i){ if (i == 0)printf("%d", srcAry[i]); else printf(" %d", srcAry[i]); }
	return 0;
}