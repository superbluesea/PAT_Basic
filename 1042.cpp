#include<stdio.h>
#include<string.h>

int main()
{
	char str[1000];
	int num[26];
	for (int i = 0; i < 26; ++i)
	{
		num[i] = 0;
	}
	gets(str);
	int length = strlen(str);
	for (int i = 0; i < length; ++i)
	{
		if (str[i] >= 65 && str[i] <= 90)
			num[str[i] - 65] += 1;
		if (str[i] >= 97 && str[i] <= 122)
			num[str[i] - 97] += 1;
	}
	int maxNdx = 0;
	for (int i = 1; i < 26; ++i)
	{
		if (num[maxNdx] < num[i])
		{
			maxNdx = i;
		}
	}
	printf("%c %d\n", maxNdx + 97, num[maxNdx]);
	return 0;
}