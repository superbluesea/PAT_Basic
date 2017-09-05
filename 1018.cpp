#include<stdio.h>

int main()
{
	const char str[] = "BCJ";
	int N, aw[3] = { 0, 0, 0 }, bw[3] = { 0, 0, 0 };
	char a, b;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		getchar();
		scanf("%c %c", &a, &b);
		if (a == 'B'&&b == 'C')++aw[0];
		if (a == 'C'&&b == 'J')++aw[1];
		if (a == 'J'&&b == 'B')++aw[2];
		if (b == 'B'&&a == 'C')++bw[0];
		if (b == 'C'&&a == 'J')++bw[1];
		if (b == 'J'&&a == 'B')++bw[2];
	}
	int aWin = aw[0] + aw[1] + aw[2], bWin = bw[0] + bw[1] + bw[2], draw = N - aWin - bWin;
	int aMax = aw[0] >= aw[1] ? 0 : 1, bMax = bw[0] >= bw[1] ? 0 : 1;
	aMax = aw[aMax] >= aw[2] ? aMax : 2;
	bMax = bw[bMax] >= bw[2] ? bMax : 2;
	printf("%d %d %d\n", aWin, draw, bWin);
	printf("%d %d %d\n", bWin, draw, aWin);
	printf("%c %c", str[aMax], str[bMax]);
	return 0;
}