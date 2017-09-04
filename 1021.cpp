#include<stdio.h>
#include<string.h>

int main()
{
	char str[1000];
	int a[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == '0')a[str[i] - '0'] += 1;
		if (str[i] == '1')a[str[i] - '0'] += 1;
		if (str[i] == '2')a[str[i] - '0'] += 1;
		if (str[i] == '3')a[str[i] - '0'] += 1;
		if (str[i] == '4')a[str[i] - '0'] += 1;
		if (str[i] == '5')a[str[i] - '0'] += 1;
		if (str[i] == '6')a[str[i] - '0'] += 1;
		if (str[i] == '7')a[str[i] - '0'] += 1;
		if (str[i] == '8')a[str[i] - '0'] += 1;
		if (str[i] == '9')a[str[i] - '0'] += 1;
	}
	for (int i = 0; i < 10; ++i)if (a[i] != 0)printf("%d:%d\n", i, a[i]);
	return 0;
}