#include<stdio.h>

int main()
{
	char c;
	int sum = 0, zeroCount = 0, oneCount = 0;
	while ((c = getchar()) != '\n')
	{
		if (c >= 65 && c <= 90)sum += c - 64;
		if (c >= 97 && c <= 122)sum += c - 96;
	}
	if (sum)++oneCount;
	while (sum / 2)
	{
		if (sum % 2)++oneCount; else ++zeroCount;
		sum = sum / 2;
	}
	printf("%d %d\n", zeroCount, oneCount);
	return 0;
}