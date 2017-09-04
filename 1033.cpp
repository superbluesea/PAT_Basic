#include<stdio.h>

int main()
{
	char str[45];
	char txt[100001];
	gets(str);
	gets(txt);
	int isUpper = 1;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == '+')
		{
			isUpper = 0;
			break;
		}
	}
	for (int i = 0; str[i] != '\0'; ++i)
	{
		for (int j = 0; txt[j] != '\0'; ++j)
		{
			if (!isUpper)if (txt[j] >= 65 && txt[j] <= 90)txt[j] = '*';
			if ((str[i] >= 'A'&&str[i] <= 'Z') || (str[i] >= 'a'&&str[i] <= 'z'))
			{
				if (str[i] == txt[j] || str[i] + 32 == txt[j])txt[j] = '*';
			}
			else
				if (str[i] == txt[j])txt[j] = '*';
		}
	}
	for (int i = 0; txt[i] != '\0'; ++i)if (txt[i] != '*' && txt[i] != '+')printf("%c", txt[i]);
	return 0;
}