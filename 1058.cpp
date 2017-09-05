#include<stdio.h>
#include<string.h>

typedef struct option{
	int score;
	int optionNum;
	int rightNum;
	char rightChoose[6];
}option;

int main()
{
	option opt[100];
	int N, M, wrongCnt[100];
	memset(wrongCnt, 0, sizeof(int)* 100);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d%d%d", &opt[i].score, &opt[i].optionNum, &opt[i].rightNum);
		for (int j = 0; j < opt[i].rightNum; ++j)
			scanf(" %c", &opt[i].rightChoose[j]);
		opt[i].rightChoose[opt[i].rightNum] = '\0';
	}
	for (int i = 0; i < N; ++i)
	{
		int score = 0;
		scanf("\n");
		for (int j = 0; j < M; ++j)
		{
			if (j != 0)scanf(" ");
			int num;
			char ans[6];
			scanf("(%d", &num);
			for (int k = 0; k < num; ++k)
				scanf(" %c", &ans[k]);
			ans[num] = '\0';
			scanf(")");
			if (num != opt[j].rightNum)
			{
				++wrongCnt[j];
				continue;
			}
			else
			{
				if (!strcmp(ans, opt[j].rightChoose))
					score += opt[j].score;
				else
					++wrongCnt[j];
			}
		}
		printf("%d\n", score);
	}
	int maxWrongTimes = 0;
	for (int i = 0; i < M; ++i)
	{
		if (wrongCnt[i]>maxWrongTimes)
			maxWrongTimes = wrongCnt[i];
	}
	if (!maxWrongTimes)
		printf("Too simple\n");
	else
	{
		printf("%d", maxWrongTimes);
		for (int i = 0; i < M; ++i)
		{
			if (wrongCnt[i] == maxWrongTimes)printf(" %d", i + 1);
		}
	}
	return 0;
}