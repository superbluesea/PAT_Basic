#include<stdio.h>

int main()
{
	int N, a1, a2, b1, b2, c1, c2;
	c1 = c2 = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
		if (a1 + b1 == a2&&a1 + b1 == b2)
			continue;
		if (a1 + b1 == a2)
			c2 += 1;
		if (a1 + b1 == b2)
			c1 += 1;
	}
	printf("%d %d\n", c1, c2);
	return 0;
}