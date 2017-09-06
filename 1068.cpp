#include<stdio.h>
#include<math.h>

int check(int a[][1001], int n, int m, int x, int y, int TOL)
{
	if (x == 1 && y == 1 && abs(a[y][x] - a[y][x + 1])>TOL&&abs(a[y][x] - a[y + 1][x])>TOL&&abs(a[y][x] - a[y + 1][x + 1])>TOL)
		return 1;
	if (x == m && y == 1 && abs(a[y][x] - a[y][x - 1])>TOL&&abs(a[y][x] - a[y + 1][x])>TOL&&abs(a[y][x] - a[y + 1][x - 1])>TOL)
		return 1;
	if (x == 1 && y == n && abs(a[y][x] - a[y - 1][x])>TOL&&abs(a[y][x] - a[y][x + 1])>TOL&&abs(a[y][x] - a[y - 1][x + 1])>TOL)
		return 1;
	if (x == m && y == n && abs(a[y][x] - a[y][x - 1])>TOL&&abs(a[y][x] - a[y - 1][x])>TOL&&abs(a[y][x] - a[y - 1][x - 1])>TOL)
		return 1;
	if (x == 1 && abs(a[y][x] - a[y][x + 1]) > TOL&&abs(a[y][x] - a[y - 1][x + 1]) > TOL&&abs(a[y][x] - a[y + 1][x + 1]) > TOL&&abs(a[y][x] - a[y + 1][x]) > TOL&&abs(a[y][x] - a[y - 1][x]) > TOL)
		return 1;
	if (x == m && abs(a[y][x] - a[y][x - 1]) > TOL&&abs(a[y][x] - a[y - 1][x - 1]) > TOL&&abs(a[y][x] - a[y][x - 1]) > TOL&&abs(a[y][x] - a[y + 1][x]) > TOL&&abs(a[y][x] - a[y - 1][x]) > TOL)
		return 1;
	if (y == 1 && abs(a[y][x] - a[y + 1][x + 1]) > TOL&&abs(a[y][x] - a[y + 1][x - 1]) > TOL&&abs(a[y][x] - a[y + 1][x]) > TOL&&abs(a[y][x] - a[y][x + 1]) > TOL&&abs(a[y][x] - a[y][x - 1]) > TOL)
		return 1;
	if (y == n && abs(a[y][x] - a[y - 1][x + 1]) > TOL&&abs(a[y][x] - a[y - 1][x - 1]) > TOL&&abs(a[y][x] - a[y - 1][x]) > TOL&&abs(a[y][x] - a[y - 1][x + 1]) > TOL&&abs(a[y][x] - a[y - 1][x - 1]) > TOL)
		return 1;
	if (abs(a[y][x] - a[y][x + 1]) > TOL&&abs(a[y][x] - a[y][x - 1]) > TOL&&abs(a[y][x] - a[y + 1][x]) > TOL&&abs(a[y][x] - a[y - 1][x]) > TOL
		&&abs(a[y][x] - a[y + 1][x + 1]) > TOL&&abs(a[y][x] - a[y + 1][x - 1]) > TOL&&abs(a[y][x] - a[y - 1][x + 1]) > TOL&&abs(a[y][x] - a[y - 1][x - 1]) > TOL)
		return 1;
	return 0;
}

int isUnique(int a[][1001], int n, int m, int x, int y)
{
	int tmp = a[y][x];
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	if (a[i][j] == tmp && (i != y || j != x))
		return 0;
	return 1;
}

int main()
{
	int M, N, TOL, pixelArray[1001][1001], flag = 0;
	int a, b;
	scanf("%d %d %d", &M, &N, &TOL);
	for (int i = 1; i <= N; ++i)
	for (int j = 1; j <= M; ++j)
		scanf("%d", &pixelArray[i][j]);
	for (int i = 1; i <= N; ++i)
	for (int j = 1; j <= M; ++j)
	{
		if (check(pixelArray, N, M, j, i, TOL) && isUnique(pixelArray, N, M, j, i))
		{
			++flag;
			a = j; b = i;
		}
	}
	if (flag == 1)printf("(%d, %d): %d\n", a, b, pixelArray[b][a]);
	else
	if (flag > 1) printf("Not Unique\n");
	else printf("Not Exist\n");
	return 0;
}