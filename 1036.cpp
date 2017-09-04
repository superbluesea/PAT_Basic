#include<stdio.h>

int main()
{
	int N, row;
	char c;
	scanf("%d %c", &N, &c);
	row = N / 2.0f + 0.5f;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i == 0 || i == row - 1)printf("%c", c);
			else
			{
				if (j == 0 || j == N - 1)printf("%c", c);
				else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
