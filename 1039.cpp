#include<stdio.h>
#include<string.h>

int main()
{
	typedef struct bead{
		char color;
		int num;
	}bead;
	bead b[62];
	int count = 0;
	char src[1001], dest[1001];
	scanf("%s %s", dest, src);
	int srcLength = strlen(src);
	int destLength = strlen(dest);
	for (int i = 0; i < srcLength; ++i)
	{
		if (i == 0)
		{
			b[count].color = src[i];
			b[count].num = 1;
			count += 1;
		}
		else
		{
			for (int j = 0; j < count; ++j)
			{
				if (b[j].color != src[i] && j == count - 1)
				{
					b[count].color = src[i];
					b[count].num = 1;
					count += 1;
					break;
				}
				else
				{
					if (b[j].color == src[i])
					{
						b[j].num += 1;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < destLength; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			if (b[j].color == dest[i])
			{
				if (b[j].num != 0)
				{
					b[j].num -= 1;
					break;
				}
				else
					break;
			}
		}
	}
	int canBuy = 1;
	int lackSum = 0;
	for (int i = 0; i < count; ++i)
	{
		if (b[i].num != 0)
		{
			lackSum += b[i].num;
			canBuy = 0;
		}
	}
	if (canBuy)printf("Yes %d", destLength - srcLength);
	else printf("No %d", lackSum);
	return 0;
}