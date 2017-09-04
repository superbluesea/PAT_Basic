#include<stdio.h>
#include<stdlib.h>

int main()
{
	struct node{
		int address;
		int data;
		int next;
	};
	typedef struct node *pNode;
	int N, first, K, i;
	struct node n[100005];
	scanf("%d %d %d", &first, &N, &K);
	for (int i = 0; i < N; ++i)
	{
		int tmp1, tmp2, tmp3;
		scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
		n[tmp1].address = tmp1;
		n[tmp1].data = tmp2;
		n[tmp1].next = tmp3;
	}
	int count = 0;
	pNode *p = (pNode*)malloc(sizeof(struct node)*N);
	while (first != -1)
	{
		*(p + count++) = &n[first];
		first = n[first].next;
	}
	for (i = 0; i < count / K; ++i)
	{
		int start = i*K, end = (i + 1)*K - 1;
		while (end > start)
		{
			pNode tmp = *(p + end);
			*(p + end) = *(p + start);
			*(p + start) = tmp;
			++start; --end;
		}
	}
	if (count%K)
	{
		i = count - count%K - 1;
		int nextAddress = (*p[i + 1]).address;
		while (i >= 0)
		{
			(*p[i]).next = nextAddress;
			nextAddress = (*p[i]).address;
			--i;
		}
	}
	else
	{
		i = count - 1;
		int nextAddress = -1;
		while (i >= 0)
		{
			(*p[i]).next = nextAddress;
			nextAddress = (*p[i]).address;
			--i;
		}
	}
	for (i = 0; i < count - 1; ++i)
		printf("%05d %d %05d\n", (*p[i]).address, (*p[i]).data, (*p[i]).next);
	printf("%05d %d -1\n", (*p[i]).address, (*p[i]).data, (*p[i]).next);
	return 0;
}