#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
	const char *MarsLow[] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	const char *MarsUp[] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	int N, space;
	char str[10];
	scanf("%d", &N);
	getchar();
	for (int i = 0; i<N; ++i)
	{
		space = 0;
		memset(str, 0, sizeof(char)* 10);
		int j = 0;
		while ((str[j] = getchar()) != '\n')
		{
			if (str[j] == ' ')space = 1;
			++j;
		}
		if (isdigit(str[0]))
		{
			int n = atoi(str);
			int a = n / 13;
			if (a)
			{
				printf("%s", *(MarsUp + a - 1));
				if (n % 13)printf(" %s\n", *(MarsLow + n % 13)); else printf("\n");
			}

			else printf("%s\n", *(MarsLow + n % 13));
		}
		else
		if (space)
		{
			char s[10];
			int j = 0, found = 0, sum = 0;
			while (str[j] != ' '){ s[j] = str[j]; ++j; }
			int spacePos = j + 1;
			s[j--] = '\0';
			for (j = 0; j<12; ++j)
			{
				if (!strcmp(*(MarsUp + j), s)){ found = 1; break; }
			}
			if (found)sum += (j + 1) * 13;
			j = 0; found = 0;
			while (str[spacePos] != '\n'){ s[j] = str[spacePos]; ++spacePos; ++j; }
			s[j] = '\0';
			for (j = 0; j<13; ++j)
			{
				if (!strcmp(*(MarsLow + j), s)){ found = 1; break; }
			}
			if (found)sum += j;
			printf("%d\n", sum);
		}
		else
		{
			char s[10];
			int j = 0, k = 0, found = 0, sum = 0;
			while (str[j] != '\0'){ s[j] = str[j]; ++j; }
			s[--j] = '\0';
			for (j = 0; j<12; ++j)
			{
				if (!strcmp(*(MarsUp + j), s)){ found = 1; break; }
			}
			for (k = 0; k<13; ++k)
			{
				if (!strcmp(*(MarsLow + k), s)){ break; }
			}
			if (found)sum += (j + 1) * 13; else sum += k;
			printf("%d\n", sum);
		}
	}
	return 0;
}