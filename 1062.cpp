#include<stdio.h>

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
	int N1, M1, N2, M2, K;
	scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);
	if (N1*M2>M1*N2)
	{
		int tmp;
		tmp = N1; N1 = N2; N2 = tmp;
		tmp = M1; M1 = M2; M2 = tmp;
	}
	int i = 1, k[1000], pos = 0, flag = 1;
	while (N1*K >= i*M1)++i;
	while (i*M2 < N2*K)
	{
		if (gcd(i, K) == 1)
		{
			k[pos] = i; ++pos;
		}
		++i;
	}
	for (i = 0; i < pos; ++i)
	{
		if (i == 0)printf("%d/%d", k[i], K);
		else printf(" %d/%d", k[i], K);
	}
	return 0;
}