#include<stdio.h>

int main()
{
	int a, b, count = 0;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		++count;
		if (b != 0)
		{
			if (count == 1)printf("%d %d", a*b, b - 1);
			else printf(" %d %d", a*b, b - 1);			
		}
		else
			if (count == 1)
				printf("0 0\n");
	}
	return 0;
}