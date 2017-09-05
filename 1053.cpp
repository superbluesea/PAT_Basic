#include<stdio.h>

int main()
{
	int N, D, K, count = 0, nullRoom = 0, mayNullRoom = 0;
	double e;
	scanf("%d %lf %d", &N, &e, &D);
	for (int i = 0; i<N; ++i)
	{
		scanf("%d", &K);
		count = 0;
		for (int j = 0; j<K; ++j)
		{
			double tmp;
			scanf("%lf", &tmp);
			if (tmp<e)++count;
		}
		if (count >= K / 2 + 1)
		if (K > D)++nullRoom; else ++mayNullRoom;
	}
	printf("%.1lf%% %.1lf%%\n", (double)mayNullRoom / N * 100, (double)nullRoom / N * 100);
	return 0;
}