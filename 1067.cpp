#include<stdio.h>
#include<string.h>

int main()
{
	char rightPsw[21], psw[100];
	int N, len = 0, count = 0;
	scanf("%s %d", rightPsw, &N);
	getchar();
	while (1)
	{
		gets(psw);
		++count;
		len = strlen(psw);
		if (len == 1 && psw[0] == '#')break;
		if ((!strcmp(rightPsw, psw)) && count <= N)
		{
			printf("Welcome in\n"); break;
		}
		else
		{
			if (count <= N)
			{
				printf("Wrong password: %s\n", psw);
				if (count == N)
				{
					printf("Account locked\n"); break;
				}
			}
		}
	}
	return 0;
}