#include<stdio.h>
#include<stdlib.h>

typedef struct stu{
	int id;
	int deScore;
	int caiScore;
	int sumScore;
	int type;
}stu;

int cmpStu(const void *a, const void *b)
{
	struct stu *c = (stu*)a;
	struct stu *d = (stu*)b;
	if ((*c).type == (*d).type)
	if ((*c).sumScore == (*d).sumScore)
	if ((*c).deScore == (*d).deScore)
		return (*c).id - (*d).id;
	else
		return (*d).deScore - (*c).deScore;
	else
		return (*d).sumScore - (*c).sumScore;
	else
		return (*c).type - (*d).type;
}

int main()
{
	int N, L, H, count = 0;
	scanf("%d %d %d", &N, &L, &H);
	stu *stuNum = (stu*)malloc(N*sizeof(stu));
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d %d", &stuNum[i].id, &stuNum[i].deScore, &stuNum[i].caiScore);
		stuNum[i].sumScore = stuNum[i].deScore + stuNum[i].caiScore;
		if (stuNum[i].deScore >= H&&stuNum[i].caiScore >= H)
			stuNum[i].type = 1;
		if (stuNum[i].deScore >= H&&stuNum[i].caiScore >= L&&stuNum[i].caiScore < H)
			stuNum[i].type = 2;
		if (stuNum[i].deScore >= L&&stuNum[i].caiScore >= L&&stuNum[i].deScore >= stuNum[i].caiScore
			&&stuNum[i].deScore < H&&stuNum[i].caiScore < H)
			stuNum[i].type = 3;
		if (stuNum[i].deScore >= L&&stuNum[i].caiScore >= L&&stuNum[i].deScore < stuNum[i].caiScore
			&&stuNum[i].deScore < H)
			stuNum[i].type = 4;
		if (stuNum[i].deScore < L || stuNum[i].caiScore < L)
			stuNum[i].type = 5;
		if (stuNum[i].type == 1 || stuNum[i].type == 2 || stuNum[i].type == 3 || stuNum[i].type == 4)++count;
	}
	qsort(stuNum, N, sizeof(stu), cmpStu);
	printf("%d\n", count);
	for (int i = 0; i < N; ++i)
	{
		if (stuNum[i].type == 5)
			break;
		printf("%d %d %d\n", stuNum[i].id, stuNum[i].deScore, stuNum[i].caiScore);
	}
	return 0;
}