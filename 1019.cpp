#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b){ return *(int*)b - *(int*)a; }

int main()
{
	int num, number[4], a = 0, b = 0, c = 0;
	scanf("%d", &num);
	number[0] = num / 1000;
	number[1] = num / 100 % 10;
	number[2] = num / 10 % 10;
	number[3] = num % 10;
	while (1)
	{
		qsort(number, 4, sizeof(int), cmp);
		a = number[0] * 1000 + number[1] * 100 + number[2] * 10 + number[3];
		b = number[3] * 1000 + number[2] * 100 + number[1] * 10 + number[0];
		c = a - b;
		if (c != 0)
		{
			if (c == 6174)
			{
				printf("%04d - %04d = %04d\n", a, b, c);
				break;
			}
			printf("%04d - %04d = %04d\n", a, b, c);
		}
		else
		{
			printf("%04d - %04d = %04d\n", a, b, c);
			break;
		}
		number[0] = c / 1000;
		number[1] = c / 100 % 10;
		number[2] = c / 10 % 10;
		number[3] = c % 10;
	}
	return 0;
}