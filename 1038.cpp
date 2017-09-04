#include<stdio.h>

int main()
{
	int N, K, score[101];
	scanf("%d", &N);
	for (int i = 0; i < 101; ++i)score[i] = 0;
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		++score[tmp];
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		if (i != K - 1)printf("%d ", score[tmp]);
		else printf("%d", score[tmp]);
	}
	return 0;
}