#include<stdio.h>
#include<stdlib.h>

typedef struct guest{
	int isJoinParty;
	int partner;
}guest;

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int N, M, singleDog[10000], count;
	guest g[100000];
	for (int i = 0; i<100000; ++i){ g[i].partner = -1; g[i].isJoinParty = 0; }
	scanf("%d", &N);
	for (int i = 0; i<N; ++i)
	{
		int husband, wife;
		scanf("%d%d", &husband, &wife);
		g[husband].partner = wife;
		g[wife].partner = husband;
	}
	scanf("%d", &M);
	count = M;
	for (int i = 0; i<M; ++i)
	{
		scanf("%d", &singleDog[i]);
		g[singleDog[i]].isJoinParty = 1;
	}

	for (int i = 0; i<M; ++i)
	{
		if (g[singleDog[i]].partner == -1)continue;
		if (g[g[singleDog[i]].partner].isJoinParty)
		{
			singleDog[i] = -1;
			--count;
		}
	}
	qsort(singleDog, M, sizeof(int), cmp);
	printf("%d\n", count);
	count = 0;
	for (int i = 0; i<M; ++i)
	{
		if (singleDog[i] != -1)
		if (count++ == 0)printf("%05d", singleDog[i]); else printf(" %05d", singleDog[i]);
	}
	return 0;
}