#include<stdio.h>
#include<string.h>

int main()
{
	int M, N, S, count = 0, flag = 0, j = 0, isReward = 0;
	char name[20], str[1000][20];
	scanf("%d %d %d", &M, &N, &S);
	for (int i = 0; i<M; ++i)
	{
		++count;
		scanf("%s", name);
		isReward = 0;
		if (count == S || count - N == S)
		{
			for (int k = 0; k<j; ++k)
			{
				if (!strcmp(str[k], name))
					isReward = 1;
			}
			if (isReward)++S;
			else
			{
				printf("%s\n", name);
				strcpy(str[j++], name);
				S = count;
				flag = 1;
			}
		}
	}
	if (!flag)printf("Keep going...");
	return 0;
}