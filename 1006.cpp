#include<stdio.h>
#include<string.h>

int main()
{
	char str[4];
	scanf("%s", str);
	int length = strlen(str);
	if (length == 3)
	{
		int i = str[0] - '0'; while (i--)printf("B");
		i = str[1] - '0'; while (i--)printf("S");
		i = str[2] - '0'; int j = 0; while (j<i)printf("%d", j++ + 1);
	}
	if (length == 2)
	{
		int i = str[0] - '0'; while (i--)printf("S");
		i = str[1] - '0'; int j = 0; while (j<i)printf("%d", j++ + 1);
	}
	if (length == 1)
	{
		int i = str[0] - '0'; int j = 0; while (j<i)printf("%d", j++ + 1);
	}
	return 0;
}