#include<stdio.h>
#include<math.h>

int main()
{
	int N, prev, count, i, j;
	prev = 2;
	count = 0;
	scanf("%d", &N);
	for (i = 2; i <= N; ++i)
	{
		if (i % 2 == 0 && i != 2)continue;
		for (j = 2; j <= sqrt(i); ++j)
		{
			if (i % j == 0)
				break;
		}
		if (j>sqrt(i))
		{
			if (i - prev == 2)
				count += 1;
			prev = i;
		}
	}
	printf("%d\n", count);
	return 0;
}