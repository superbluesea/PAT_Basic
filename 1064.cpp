#include<stdio.h>

int main()
{
	int N, num[50], tmp = 0, count = 0;
	char str[5];
	scanf("%d", &N);
	for (int i = 0; i < 50; ++i)num[i] = 0;
	for (int i = 0; i<N; ++i)
	{
		tmp = 0;
		scanf("%s", str);
		for (int j = 0; str[j] != '\0'; ++j)tmp += str[j] - '0';
		++num[tmp];
	}
	for (int i = 0; i < 50; ++i)if (num[i])++count;
	printf("%d\n", count);
	for (int i = 0; i<50; ++i)
	if (num[i]){ --count; if (count)printf("%d ", i); else printf("%d", i); }
	return 0;
}