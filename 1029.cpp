#include<stdio.h>
#include<string.h>

int main()
{
	char srcStr[85], destStr[85];
	scanf("%s %s", srcStr, destStr);
	int srcLength = strlen(srcStr), destLength = strlen(destStr);
	char a[35];
	int i = 0, j = 0, k = 0;
	int isFound = 0;
	for (i = 0; i < srcLength; ++i)
	{
		if (srcStr[i] != destStr[j])
		{
			isFound = 0;
			if (srcStr[i] >= 97 && srcStr[i] <= 122)
			{
				for (int pos = 0; pos < k; ++pos)
				{
					if (a[pos] == srcStr[i] - 32)
					{
						isFound = 1;
						break;
					}
				}
				if (!isFound)
				{
					a[k] = srcStr[i] - 32;
					++k;
				}
			}
			else
			{
				for (int pos = 0; pos < k; ++pos)
				{
					if (a[pos] == srcStr[i])
					{
						isFound = 1;
						break;
					}
				}
				if (!isFound)
				{
					a[k] = srcStr[i];
					++k;
				}
			}
			continue;
		}
		else
			++j;
	}
	for (int n = 0; n < k; ++n)printf("%c", a[n]);
	return 0;
}