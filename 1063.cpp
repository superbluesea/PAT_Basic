#include<stdio.h>
#include<math.h>

int main()
{
	int a, b, N;
	double max = 0.0f;
	scanf("%d", &N);
	for (int i = 0; i<N; ++i)
	{
		scanf("%d %d", &a, &b);
		if (sqrt(a*a + b*b)>max)max = sqrt(a*a + b*b);
	}
	printf("%.2lf\n", max);
	return 0;
}