#include<stdio.h>
#include<string.h>

int main()
{
	int N, count = 0;
	char birth[11], oBirth[11], yBirth[11], oldest[6], youngest[6], tmp[6];
	scanf("%d", &N);
	for (int i = 0; i<N; ++i)
	{
		scanf("%s %s", tmp, birth);
		if (strcmp(birth, "2014/09/06") <= 0 &&
			strcmp(birth, "1814/09/06") >= 0 &&
			!count)
		{
			++count; strcpy(oldest, tmp); strcpy(oBirth, birth); strcpy(youngest, tmp); strcpy(yBirth, birth); continue;
		}
		if (strcmp(birth, "2014/09/06") <= 0 &&
			strcmp(birth, "1814/09/06") >= 0)
		{
			++count;
			if (strcmp(birth, oBirth) < 0){ strcpy(oldest, tmp); strcpy(oBirth, birth); }
			if (strcmp(birth, yBirth) > 0){ strcpy(youngest, tmp); strcpy(yBirth, birth); }
		}
	}
	if (count)printf("%d %s %s", count, oldest, youngest);
	else printf("0\n");
	return 0;
}