#include<stdio.h>

int main()
{
	char handEmoji[10][5], eyeEmoji[10][5], mouthEmoji[10][5], ch[100];
	int flag = 0, i = 0, k = 0, hNum, eNum, mNum;
	gets(ch);
	while (ch[k] != '\0')
	{
		if (ch[k] == '[')flag = 1;
		if (flag)
		{
			int j = 0;
			++k;
			while (ch[k] != ']'){ handEmoji[i][j] = ch[k]; ++k; ++j; }
			handEmoji[i][j--] = '\0';
			flag = 0;
			++i;
		}
		++k;
	}
	hNum = i;
	k = i = 0;
	gets(ch);
	while (ch[k] != '\0')
	{
		if (ch[k] == '[')flag = 1;
		if (flag)
		{
			int j = 0;
			++k;
			while (ch[k] != ']'){ eyeEmoji[i][j] = ch[k]; ++k; ++j; }
			eyeEmoji[i][j--] = '\0';
			flag = 0;
			++i;
		}
		++k;
	}
	eNum = i;
	k = i = 0;
	gets(ch);
	while (ch[k] != '\0')
	{
		if (ch[k] == '[')flag = 1;
		if (flag)
		{
			int j = 0;
			++k;
			while (ch[k] != ']'){ mouthEmoji[i][j] = ch[k]; ++k; ++j; }
			mouthEmoji[i][j--] = '\0';
			flag = 0;
			++i;
		}
		++k;
	}
	mNum = i;
	int K, a, b, c, d, e;
	scanf("%d", &K);
	for (i = 0; i<K; ++i)
	{
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		if (a<1 || b<1 || c<1 || d<1 || e<1){ printf("Are you kidding me? @\\/@\n"); continue; }
		if (a>hNum || e > hNum){ printf("Are you kidding me? @\\/@\n"); continue; }
		if (b > eNum || d > eNum){ printf("Are you kidding me? @\\/@\n"); continue; }
		if (c > mNum){ printf("Are you kidding me? @\\/@\n"); continue; }
		printf("%s(%s%s%s)%s\n", handEmoji[a - 1], eyeEmoji[b - 1], mouthEmoji[c - 1], eyeEmoji[d - 1], handEmoji[e - 1]);
	}
	return 0;
}