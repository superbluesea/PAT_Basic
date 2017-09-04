#include<stdio.h>
#include<stdlib.h>

typedef struct info{
	int id;
	int score;
}info;

int cmp(const void *a, const void *b)
{
	return (*(info*)a).id >(*(info*)b).id;
}

int main()
{
	int N;
	info ifo[100000];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)scanf("%d %d", &ifo[i].id, &ifo[i].score);
	qsort(ifo, N, sizeof(info), cmp);
	int maxSum = -1, scoreSum = 0, maxID = 1, curID = 1;
	for (int i = 0; i < N; ++i)
	{
		if (ifo[i].id != curID)
		{
			if (scoreSum > maxSum)
			{
				maxSum = scoreSum;
				maxID = curID;
			}
			scoreSum = ifo[i].score;
			curID = ifo[i].id;
		}
		else scoreSum += ifo[i].score;
	}
	if (scoreSum>maxSum){ maxSum = scoreSum; maxID = curID; }
	printf("%d %d\n", maxID, maxSum);
	return 0;
}