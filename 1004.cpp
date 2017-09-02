#include<stdio.h>
#include<string.h>

int main()
{
	typedef struct stu{
		char name[11];
		char id[11];
		int score;
	}stu;
	int n;
	stu max, min;
	scanf("%d", &n);
	scanf("%s %s %d", max.name, max.id, &max.score);
	strcpy(min.name, max.name);
	strcpy(min.id, max.id);
	min.score = max.score;
	--n;
	while (n--)
	{
		stu tmp;
		scanf("%s %s %d", tmp.name, tmp.id, &tmp.score);
		if (tmp.score>max.score){ strcpy(max.name, tmp.name); strcpy(max.id, tmp.id); max.score = tmp.score; }
		else if (tmp.score<min.score){ strcpy(min.name, tmp.name); strcpy(min.id, tmp.id); min.score = tmp.score; }
	}
	printf("%s %s\n%s %s\n", max.name, max.id, min.name, min.id);
	return 0;
}