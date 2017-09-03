#include<stdio.h>

int main()
{
	char A[15], B[15];
	long int DA, DB, i, DANum, DBNum, sum;
	i = sum = DANum = DBNum = 0;
	scanf("%s %d %s %d", A, &DA, B, &DB);
	while (A[i] != '\0')
	{
		int a = A[i] - '0';
		if (a == DA)
			DANum += 1;
		++i;
	}
	i = 0;
	while (B[i] != '\0')
	{
		int a = B[i] - '0';
		if (a == DB)
			DBNum += 1;
		++i;
	}
	while (DANum)
	{
		int a = DA;
		for (int i = 1; i < DANum; ++i)
		{
			a = a * 10;
		}
		sum += a;
		--DANum;
	}
	while (DBNum)
	{
		int a = DB;
		for (int i = 1; i < DBNum; ++i)
		{
			a = a * 10;
		}
		sum += a;
		--DBNum;
	}
	printf("%ld\n", sum);
	return 0;
}