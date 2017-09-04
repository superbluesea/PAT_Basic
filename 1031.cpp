#include<stdio.h>

int main()
{
	const int length = 17;
	int N, sum = 0, a = 0;
	int q[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	char zm[] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
	int isAllPassed = 1, isRight = 1;
	scanf("%d", &N);
	char id[20];
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", id);
		sum = 0;
		isRight = 1;
		for (int j = 0; j < length; ++j)
		{
			int tmp = id[j] - '0';
			if (tmp >= 0 && tmp <= 9)sum = sum + tmp * q[j];
			else
			{
				isAllPassed = 0;
				isRight = 0;
				break;
			}
		}
		if (isRight)
		{
			a = sum % 11;
			if (id[length] != zm[a])
			{
				isAllPassed = 0;
				isRight = 0;
			}
		}
		if (!isRight)printf("%s\n", id);
	}
	if (isAllPassed)printf("All passed\n");
	return 0;
}