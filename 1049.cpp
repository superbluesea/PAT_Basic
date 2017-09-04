#include<stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	double d[100000], sum = 0.0f;
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf", &d[i]);
		sum += d[i] * (N - i)*(i + 1);
	}
	printf("%.2lf\n", sum);
	return 0;
}