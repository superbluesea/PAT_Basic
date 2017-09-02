#include<stdio.h>

int main()
{
	int a, b, c, pos, n;
	char str[101];
	scanf("%d", &n);
	getchar();
	for (int i = 0; i<n; ++i)
	{
		a = b = c = pos = 0;
		int j = 0, p = 0, t = 0, es = 0;
		while ((str[j] = getchar()) != '\n')
		{
			if (str[j] != 'P' && str[j] != 'A' && str[j] != 'T')++es;
			if (str[j] == 'A' && pos == 0)++a;
			if (str[j] == 'A' && pos == 1)++b;
			if (str[j] == 'A' && pos == 2)++c;
			if (str[j] == 'P'){ pos = 1; ++p; }
			if (str[j] == 'T'&&pos == 1){ pos = 2; ++t; }
			++j;
		}
		if (pos == 2 && b && p == 1 && t == 1 && !es)
		{
			if (((b - 1)*a + a == c) || (a == c&&b == 1))printf("YES\n");
			else printf("NO\n");
		}
		else printf("NO\n");
	}
	return 0;
}