#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[15000], num[100];
	for (int i = 0; i<150; ++i)a[i] = 0;
	int K, count = 0;
	scanf("%d", &K);
	for (int i = 0; i<K; ++i)scanf("%d", &num[i]);	
	qsort(num, K, sizeof(int), cmp);
	for (int i = 0; i<K; ++i)
	{
		int tmp = num[i];
		if (tmp % 2)tmp = (3 * tmp + 1) / 2; else tmp = tmp / 2;
		while (a[tmp] != 1)
		{
			a[tmp] = 1;
			if (tmp % 2)tmp = (3 * tmp + 1) / 2; else tmp = tmp / 2;
		}
	}
	for (int i = 0; i < K; ++i)if (!a[num[i]])++count;
	for (int i = 0; i<K; ++i)
	{
		if (!a[num[i]])
		{
			--count; if (count)printf("%d ", num[i]); else printf("%d", num[i]);
		};
	}
	return 0;
}