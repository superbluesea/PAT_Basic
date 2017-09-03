#include<stdio.h>
#include<ctype.h>

int main()
{
	const char *week[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	char s1[61], s2[61], s3[61], s4[61];
	scanf("%s %s %s %s", s1, s2, s3, s4);
	int i = 0;
	for (i; s1[i] && s2[i]; ++i)
	{
		if (s1[i] >= 'A'&&s1[i] <= 'G'&&s1[i] == s2[i]){ printf("%s ", *(week + s1[i] - 'A')); break; }
	}
	for (++i; s1[i] && s2[i]; ++i)
	{
		if (s1[i] == s2[i])
		{
			if (isdigit(s1[i]))
			{
				printf("%02d:", s1[i] - '0'); break;
			}
			if (s1[i] >= 'A'&&s1[i] <= 'N')
			{
				printf("%02d:", s1[i] - 'A' + 10); break;
			}
		}
	}
	for (i = 0; s3[i] && s4[i]; ++i)
	{
		if (isalpha(s3[i]) && s3[i] == s4[i]){ printf("%02d\n", i); break; }
	}
	return 0;
}