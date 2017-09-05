#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N, count = 0;
	scanf("%d", &N);
	double d, sum = 0.0f;
	char str[100];
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", str);
		int dotNum = 0, dotNumberNum = 0, flag = 1, j = 0;
		for (j; str[j] != '\0'; ++j)
		{
			if (str[j] == '-'&& j == 0)continue;
			if ((str[j] < 48 || str[j]>57) && str[j] != '.'){ flag = 0; break; }
			if (str[j] == '.'&& dotNum){ flag = 0; break; }
			if (dotNum)dotNumberNum += 1;
			if (str[j] == '.')dotNum += 1;
			if (dotNumberNum > 2){ flag = 0; break; }
		}

		if (flag && atof(str) >= -1000 && atof(str) <= 1000)
		{
			sum += atof(str);
			count += 1;
		}
		else
		{
			printf("ERROR: %s is not a legal number\n", str);
		}
	}
	if (count == 0)
		printf("The average of 0 numbers is Undefined\n");
	if (count == 1)
		printf("The average of 1 number is %.2lf\n", sum);
	if (count >= 2)
		printf("The average of %d numbers is %.2lf\n", count, sum / count);
	return 0;
}