#include<stdio.h>

int main()
{
	int A, B, D;
	scanf("%d %d %d", &A, &B, &D);
	int C = A + B;
	int a[10000];
	for (int j = 0; j < 10000; ++j)
		a[j] = -1;
	int i = 0;
	for (i;; ++i)
	{
		if (C / D == 0)break;
		a[i] = C % D;
		C = C / D;
	}
	a[i] = C % D;
	for (i; i >= 0; --i)printf("%d", a[i]);
	return 0;
}