#include<stdio.h>

int main()
{
	int C1, C2;
	scanf("%d %d", &C1, &C2);
	int progRunTime = (int)((double)(C2 - C1) / 100 + 0.5f);
	int hh = progRunTime / (60 * 60), mm = (progRunTime % (60 * 60)) / 60, ss = (progRunTime % (60 * 60)) % 60;
	printf("%02d:%02d:%02d", hh, mm, ss);
	return 0;
}