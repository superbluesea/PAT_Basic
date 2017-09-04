#include<stdio.h>
#include<math.h>

int main()
{
	char sym, A[10000];
	int e, i = 0;
	sym = getchar();
	while ((A[i++] = getchar()) != 'E');
	scanf("%d", &e);
	i -= 3;
	if (sym == '-')putchar('-');
	if (e >= 0)
	{
		if (e <= i)
		{
			putchar(A[0]);
			int j = 2, k = e;
			while (k){ putchar(A[j++]); --k; }
			if (e != i)putchar('.');
			while (A[j] != 'E')putchar(A[j++]);
		}
		else
		{
			int j = 0;
			while (A[j] != 'E'){ if (A[j] != '.')putchar(A[j]); ++j; }
			j = e - i;
			while (j--)putchar('0');
		}
	}
	else
	{
		int j = abs(e);
		putchar('0'); putchar('.'); --j;
		while (j--)putchar('0');
		++j;
		while (A[j] != 'E'){ if (A[j] != '.')putchar(A[j]); ++j; }
	}
	return 0;
}