#include<stdio.h>

int main()
{
	int M, N, A, B, replaceValue, value, count = 0;
	scanf("%d %d %d %d %d", &M, &N, &A, &B, &replaceValue);
	for (int i = 0; i<M; ++i)
		for (int j = 0; j<N; ++j)
		{
			scanf("%d", &value);
			if (value >= A&&value <= B)
			if (++count%N == 0)printf("%03d\n", replaceValue); else printf("%03d ", replaceValue);
			else
			if (++count%N == 0)printf("%03d\n", value); else printf("%03d ", value);
		}
	return 0;
}