#include<stdio.h>

int main()
{
	int N, M, score[100], answer[100];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &score[i]);
	}
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &answer[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		int tmp, sum = 0;
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &tmp);
			if (tmp == answer[j])sum += score[j];
		}
		printf("%d\n", sum);
	}
	return 0;
}