#include<stdio.h>

int main()
{
	char inStr[100];
	char outStr[100][100];
	gets(inStr);
	int i, j, k;
	i = j = k = 0;
	while (inStr[i] != '\0')
	{
		if (inStr[i] != ' ')outStr[j][k++] = inStr[i];		
		else
		{
			outStr[j][k] = '\0';
			k = 0;
			j += 1;
		}
		++i;
	}
	outStr[j][k] = '\0';
	while (j >= 0)
	{
		if (j != 0)printf("%s ", outStr[j--]);
		else printf("%s", outStr[j--]);
	}
	return 0;
}