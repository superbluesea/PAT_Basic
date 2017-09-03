#include<stdio.h>
#include<stdlib.h>

typedef struct good{
	float num;
	float sumPrice;
	float perPrice;
}good;

int cmpa(const void *a, const void *b)
{
	return (*(good*)a).perPrice<(*(good*)b).perPrice;
}

int main()
{
	good g[1000];
	int N, D;
	float gain = 0.0f;
	scanf("%d %d", &N, &D);
	for (int i = 0; i<N; ++i)scanf("%f", &g[i].num);
	for (int i = 0; i<N; ++i)
	{
		scanf("%f", &g[i].sumPrice);
		g[i].perPrice = g[i].sumPrice / g[i].num;
	}
	qsort(g, N, sizeof(good), cmpa);
	for (int i = 0; i<N; ++i)
	{
		if (D <= g[i].num)
		{
			gain += D*g[i].perPrice;
			break;
		}
		else
		{
			D = D - g[i].num;
			gain += g[i].sumPrice;
		}
	}
	printf("%.2f\n", gain);
	return 0;
}