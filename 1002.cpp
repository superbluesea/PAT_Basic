#include<stdio.h>

int main()
{
	char str[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	char num[102];
	scanf("%s", num);
	int i = 0, sum = 0;
	while (num[i] != '\0'){ sum += num[i] - '0'; ++i; }
	int a[3];
	a[0] = a[1] = a[2] = -1;
	i = 2;
	while (sum / 10)
	{
		a[i--] = sum % 10;
		sum = sum / 10;
	}
	a[i] = sum;
	for (i; i < 2; ++i)printf("%s ", str[a[i]]);
	printf("%s\n", str[a[2]]);
	return 0;
}