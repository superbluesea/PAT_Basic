#include<stdio.h>
#include<math.h>

int main()
{
	int N, K, flag, i, j;
	int rank[10001], id[10001], prime[10001];
	prime[1] = 0;
	id[1] = 0;
	for (int i = 2; i <= 10000; ++i)
	{
		prime[i] = 1;
		id[i] = 0;
		for (int j = 2; j <= sqrt(i); ++j)
		if (i%j == 0){ prime[i] = 0; break; }
	}
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)scanf("%d", &rank[i]);
	scanf("%d", &K);
	for (i = 1; i <= K; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		if (id[tmp] == 0)
		{
			for (j = 1; j <= N; ++j)
			{
				if (rank[j] == tmp)
				{
					if (j == 1)printf("%04d: Mystery Award\n", tmp);
					else if (prime[j])printf("%04d: Minion\n", tmp);
					else printf("%04d: Chocolate\n", tmp);
					id[tmp] = 1;
					break;
				}
			}
			if (j > N){ printf("%04d: Are you kidding?\n", tmp); id[tmp] = -1; }
		}
		else if (id[tmp] == -1)printf("%04d: Are you kidding?\n", tmp);
		else printf("%04d: Checked\n", tmp);
	}
	return 0;
}