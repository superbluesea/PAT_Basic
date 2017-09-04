#include<stdio.h>

int main()
{
	char c;
	int N, sum = 1, count = 1, i = 1, remain = 0;
	scanf("%d %c", &N, &c);
	for (i = 1;; ++i)
	{
		count += 2;
		sum = sum + ((i * 2) + 1) * 2;
		if (sum > N)break;
	}
	sum = sum - ((i * 2) + 1) * 2;
	count -= 2;
	remain = N - sum;
	for (i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			if ((j >= i && j <= count - 1 - i) || (j <= i&&j >= count - 1 - i))printf("%c", c);
			else 
				if (i>j && j<count - 1 - i)printf(" ");
				else break;
		}
		printf("\n");
	}
	printf("%d\n", remain);
	return 0;
}