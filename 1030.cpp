#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int N, p;
	scanf("%d%d", &N, &p);
	long *ptr = (long*)malloc(sizeof(long*)*N);
	for (int i = 0; i < N; ++i)scanf("%ld", ptr + i);
	qsort(ptr, N, sizeof(long), cmp);
	long count = 0;

	int index = N - 1;
	for (int i = N - 1; i >= 0; --i)
	{
		for (index; index >= 0; --index)
		{
			if (*(ptr + index)*p >= *(ptr + i))
			{
				if (i - index + 1>count)
					count = i - index + 1;
			}
			else
				break;
		}
	}

	//for (int i = N - 1; i >= 0; --i)
	//{
	//	while (*(ptr + index)*p >= *(ptr + i) && index >= 0)
	//		--index;
	//	if (count<i-index)
	//		count = i - index;
	//}

	//overtime
	//int posMax = N-1, posMin = 0;
	//for (int i = N-1; i >= 0; --i)
	//{
	//	int tmpMax = *(ptr + i);
	//	for (int j = 0; j < N; ++j)
	//	{
	//		if (*(ptr + j)*p * 1L >= tmpMax&&i - j + 1 > count)
	//		{
	//			if (i - j + 1 > count)
	//			{
	//				count = i - j + 1; break;
	//			}
	//			else
	//				break;
	//		}
	//	}
	//}


	//overtime	
	//int posMax = N-1,posMin = 0;
	//while (posMax >= posMin)
	//{
	//	int tmpMax = *(ptr + posMax);
	//	if (*(ptr + posMin)*p*1L >= tmpMax)
	//	{
	//		if (posMax - posMin + 1 > count)
	//			count = posMax - posMin + 1;
	//		--posMax;
	//		posMin = 0;			
	//	}
	//	else
	//		++posMin;
	//}
	printf("%d", count);
	return 0;
}