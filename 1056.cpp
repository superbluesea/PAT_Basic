#include<stdio.h>

int main()
{
	int N, a[10], sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &a[i]);
		sum += (a[i] * 10 + a[i])*(N - 1);
	}
	printf("%d\n", sum);
	return 0;
}