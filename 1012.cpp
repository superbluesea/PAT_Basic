#include<stdio.h>

int main()
{
	int N, count[5], a1Sum = 0, a4Sum = 0, max = 0;
	for (int i = 0; i<5; ++i)count[i] = 0;
	scanf("%d", &N);
	while (N--)
	{
		int tmp;
		scanf("%d", &tmp);
		switch (tmp % 5)
		{
			case 0:if (!(tmp % 2))count[0] += tmp; break;
			case 1:++count[1]; if (count[1] % 2)a1Sum += tmp; else a1Sum -= tmp; break;
			case 2:++count[2]; break;
			case 3:a4Sum += tmp; ++count[3]; break;
			case 4:++count[4]; if (tmp>max)max = tmp; break;
			default:break;
		}
	}
	for (int i = 0; i<5; ++i)
	{
		if (i == 0){ if (!count[i])printf("N "); else printf("%d ", count[i]); }
		if (i == 1){ if (!count[i])printf("N "); else printf("%d ", a1Sum); }
		if (i == 2){ if (!count[i])printf("N "); else printf("%d ", count[i]); }
		if (i == 3){ if (!count[i])printf("N "); else printf("%.1lf ", (double)a4Sum / count[i]); }
		if (i == 4){ if (!count[i])printf("N"); else printf("%d", max); }
	}
	return 0;
}