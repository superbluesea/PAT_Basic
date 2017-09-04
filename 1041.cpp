#include<stdio.h>

int main()
{
	typedef struct info{
		char id[14];
		int testID;
		int examID;
	}info;
	info ifo[1000];
	int N, M, checkAry[1000];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s %d %d", ifo[i].id, &ifo[i].testID, &ifo[i].examID);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &checkAry[i]);
		for (int j = 0; j < N; ++j)
		{
			if (ifo[j].testID == checkAry[i])
			{
				printf("%s %d\n", ifo[j].id, ifo[j].examID);
				break;
			}
		}
	}
	return 0;
}