#include<stdio.h>
#include<string.h>
#include<math.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	char A[101], B[101];
	scanf("%s %s", A, B);
	int c = strlen(A) - strlen(B), maxLen = max(strlen(A), strlen(B)), pos = 1;
	if (c>0)
	{
		int len = strlen(B);
		++len;
		while (len >= 0){ B[len + c] = B[len]; --len; }
		while (c--)B[c] = '0';
	}
	else
	{
		c = abs(c);
		int len = strlen(A);
		++len;
		while (len >= 0){ A[len + c] = A[len]; --len; }
		while (c--)A[c] = '0';
	}
	for (int i = maxLen - 1; i >= 0; --i)
	{
		if (pos % 2 == 0)
		{
			int tmp = B[i] - A[i];
			if (tmp<0)tmp += 10;
			B[i] = tmp + '0';
		}
		else
		{
			int tmp = (A[i] - '0' + B[i] - '0') % 13;
			if (tmp < 10)B[i] = tmp + '0';
			else
			{
				if (tmp == 10)B[i] = 'J';
				if (tmp == 11)B[i] = 'Q';
				if (tmp == 12)B[i] = 'K';
			}
		}
		++pos;
	}
	printf("%s\n", B);
	return 0;
}