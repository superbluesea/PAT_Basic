#include<stdio.h>

int main()
{
	const int inf = 1000000007;
	int p, pa, result;
	p = pa = result = 0;
	char c;
	while ((c = getchar()) != '\n')
	{
		if (c == 'P')++p;
		if (c == 'A')pa = (pa + p) % inf;
		if (c == 'T')result = (result + pa) % inf;
	}
	printf("%d\n", result);
	return 0;
}