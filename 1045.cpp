#include<stdio.h>

int main()
{
	int N, ary[100000], minAry[100000], maxAry[100000], count = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)scanf("%d", ary + i);
	maxAry[0] = ary[0];
	for (int i = 1; i < N; ++i)if (ary[i] >= maxAry[i - 1])maxAry[i] = ary[i]; else maxAry[i] = maxAry[i - 1];
	minAry[N - 1] = ary[N - 1];
	for (int i = N - 2; i >= 0; --i)if (ary[i] <= minAry[i + 1])minAry[i] = ary[i]; else minAry[i] = minAry[i + 1];
	for (int i = 0; i < N; ++i)if (minAry[i] == maxAry[i])++count;
	printf("%d\n", count);
	if (count == 0)printf("\n");
	for (int i = 0; i < N; ++i)
	{
		if (minAry[i] == maxAry[i])
		{
			--count;
			if (count)printf("%d ", ary[i]); else printf("%d", ary[i]);
		}
	}
	return 0;
}