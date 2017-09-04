#include<stdio.h>

int main()
{
	int a[10], pos = 1;
	char str[55];
	for (int i = 0; i < 55; ++i)str[i] = '\0';
	for (int i = 0; i < 10; ++i)scanf("%d", &a[i]);
	for (int i = 1; i < 10; ++i)
	{
		if (a[i] != 0)
		{
			str[0] = i + '0';
			--a[i];
			break;
		}
	}
	for (int i = 0; i < 10; ++i)while (a[i]-- != 0)str[pos++] = i + '0';
	printf("%s", str);
	return 0;
}