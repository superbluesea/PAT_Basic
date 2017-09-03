#include<stdio.h>

int main()
{
	char A[1001];
	int Q[1000], B = 0, R = 0, i = 0;
	scanf("%s %d", A, &B);
	for (i = 0; A[i] != '\0'; ++i)
	{
		int tmp = R * 10 + A[i] - '0';
		Q[i] = tmp / B;
		R = tmp%B;
	}
	for (int j = 0; j < i; ++j){ if (j == 0 && Q[j] == 0 && i != 1)continue; printf("%d", Q[j]); }
	printf(" %d\n", R);
	return 0;
}