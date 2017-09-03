#include<stdio.h>
#include<math.h>

int main()
{
	int M, N, count = 0, sumCount = 0, i = 2, j = 2, isSuShu = 1;
	scanf("%d %d", &M, &N);

	while (1)
	{
		for (j = 2; j <= sqrt(i); ++j)
		{
			if (i % 2 == 0 && i != 2){ isSuShu = 0; break; }
			if (i%j == 0){ isSuShu = 0; break; }
		}
		if (j > sqrt(i))isSuShu = 1;
		if (isSuShu)
		{
			count += 1;
			if (count >= M&&count <= N)
			{
				sumCount += 1;
				if (sumCount % 10 == 0)
				{
					printf("%d\n", i);
				}
				else if (sumCount == N - M + 1)
				{
					printf("%d", i);
				}
				else
					printf("%d ", i);
			}
			else if (count > N)
				break;
		}
		++i;
	}
	return 0;
}