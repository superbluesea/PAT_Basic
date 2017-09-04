#include<stdio.h>
#include<string.h>

int main()
{
	char str[10000];
	gets(str);
	int num[6];
	int sum = 0;
	for (int i = 0; i < 6; ++i)num[i] = 0;
	int length = strlen(str);
	for (int i = 0; i < length; ++i)
	{
		if (str[i] == 'P')num[0] += 1;
		if (str[i] == 'A')num[1] += 1;
		if (str[i] == 'T')num[2] += 1;
		if (str[i] == 'e')num[3] += 1;
		if (str[i] == 's')num[4] += 1;
		if (str[i] == 't')num[5] += 1;
		if (str[i] == 'P' || str[i] == 'A' || str[i] == 'T' || str[i] == 'e' || str[i] == 's' || str[i] == 't')
			sum += 1;
	}
	while (sum)
	{
		for (int i = 0; i < 6; i++)
		{
			if (num[i] != 0)
			{
				num[i] -= 1;
				sum -= 1;
				if (i == 0)printf("P");
				if (i == 1)printf("A");
				if (i == 2)printf("T");
				if (i == 3)printf("e");
				if (i == 4)printf("s");
				if (i == 5)printf("t");
			}
		}
	}
	return 0;
}