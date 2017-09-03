#include<stdio.h>

int main()
{
	int T, i = 0;
	long int a, b, c;
	scanf("%d", &T);
	while (i < T)
	{
		scanf("%ld %ld %ld", &a, &b, &c);
		if (a + b > c)printf("Case #%d: true\n", i++ + 1);
		else printf("Case #%d: false\n", i++ + 1);
	}
	return 0;
}