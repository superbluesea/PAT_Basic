#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
#include <time.h>
using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int max(int a, int b)
{
	return (a > b ? a : b);
}

bool compare(int a, int b)
{
	return a > b;
}

int cmp(const void *a, const void *b)
{
	return *(int*)a < *(int*)b;
}

void Pat1001()
{
	int n, count = 0;
	scanf("%d", &n);
	while (n != 1)
	{
		if (n % 2){ n = (3 * n + 1) / 2; ++count; }
		else{ n = n / 2; ++count; }
	}
	printf("%d\n", count);
}

void Pat1002()
{
	char str[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	char num[102];
	scanf("%s", num);
	int i = 0, sum = 0;
	while (num[i] != '\0'){ sum += num[i] - '0'; ++i; }
	int a[3];
	a[0] = a[1] = a[2] = -1;
	i = 2;
	while (sum / 10)
	{
		a[i--] = sum % 10;
		sum = sum / 10;
	}
	a[i] = sum;
	for (i; i < 2; ++i)printf("%s ", str[a[i]]);
	printf("%s\n", str[a[2]]);
}

//弄清楚题目意思，找数字规律
void Pat1003()
{
	int a, b, c, pos, n;
	char str[101];
	scanf("%d", &n);
	getchar();
	for (int i = 0; i<n; ++i)
	{
		a = b = c = pos = 0;
		int j = 0, p = 0, t = 0, es = 0;
		while ((str[j] = getchar()) != '\n')
		{
			if (str[j] != 'P' && str[j] != 'A' && str[j] != 'T')++es;
			if (str[j] == 'A' && pos == 0)++a;
			if (str[j] == 'A' && pos == 1)++b;
			if (str[j] == 'A' && pos == 2)++c;
			if (str[j] == 'P'){ pos = 1; ++p; }
			if (str[j] == 'T'&&pos == 1){ pos = 2; ++t; }
			++j;
		}
		if (pos == 2 && b && p == 1 && t == 1 && !es)
		{
			if (((b - 1)*a + a == c) || (a == c&&b == 1))printf("YES\n");
			else printf("NO\n");
		}
		else printf("NO\n");
	}
}

void Pat1004()
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
}

//待改良
void Pat1005()
{
	int a[15000], num[100];
	for (int i = 0; i<150; ++i)a[i] = 0;
	int K, count = 0;
	scanf("%d", &K);
	for (int i = 0; i<K; ++i)
	{
		scanf("%d", &num[i]);
	}
	qsort(num, K, sizeof(int), cmp);
	for (int i = 0; i<K; ++i)
	{
		int tmp = num[i];
		if (tmp % 2)tmp = (3 * tmp + 1) / 2; else tmp = tmp / 2;
		while (a[tmp] != 1)
		{
			a[tmp] = 1;
			if (tmp % 2)tmp = (3 * tmp + 1) / 2; else tmp = tmp / 2;
		}
	}
	for (int i = 0; i < K; ++i)
	{
		if (!a[num[i]])++count;
	}
	for (int i = 0; i<K; ++i)
	{
		if (!a[num[i]])
		{
			--count; if (count)printf("%d ", num[i]); else printf("%d", num[i]);
		};
	}
}

void Pat1006()
{
	char str[4];
	scanf("%s", str);
	int length = strlen(str);
	if (length == 3)
	{
		int i = str[0] - '0'; while (i--)printf("B");
		i = str[1] - '0'; while (i--)printf("S");
		i = str[2] - '0'; int j = 0; while (j<i)printf("%d", j++ + 1);
	}
	if (length == 2)
	{
		int i = str[0] - '0'; while (i--)printf("S");
		i = str[1] - '0'; int j = 0; while (j<i)printf("%d", j++ + 1);
	}
	if (length == 1)
	{
		int i = str[0] - '0'; int j = 0; while (j<i)printf("%d", j++ + 1);
	}
}

void Pat1007()
{
	int N, prev, count, i, j;
	prev = 2;
	count = 0;
	scanf("%d", &N);
	for (i = 2; i <= N; ++i)
	{
		if (i % 2 == 0 && i != 2)continue;
		for (j = 2; j <= sqrt(i); ++j)
		{
			if (i % j == 0)
				break;
		}
		if (j>sqrt(i))
		{
			if (i - prev == 2)
				count += 1;
			prev = i;
		}
	}
	printf("%d\n", count);
}

void Pat1008()
{
	int N, M;
	int a[101];
	scanf("%d %d", &N, &M);
	int i = 1;
	while (i <= N)
	{
		if (M > N)
		{
			M = M%N;
		}
		if (i <= N - M)
			scanf("%d", &a[i + M]);
		else
			scanf("%d", &a[M - N + i]);
		++i;
	}
	i = 1;
	while (i <= N)
	{
		if (i == N)
			printf("%d", a[i]);
		else
			printf("%d ", a[i]);
		++i;
	}
}

void Pat1009()
{
	char inStr[100];
	char outStr[100][100];
	gets(inStr);
	int i = 0;
	int j = 0;
	int k = 0;
	while (inStr[i] != '\0')
	{
		if (inStr[i] != ' ')
		{
			outStr[j][k++] = inStr[i];
		}
		else
		{
			outStr[j][k] = '\0';
			k = 0;
			j += 1;
		}
		++i;
	}
	outStr[j][k] = '\0';
	while (j >= 0)
	{
		if (j != 0)
		{
			printf("%s", outStr[j]);
			printf(" ");
		}
		else
		{
			printf("%s", outStr[j]);
		}
		--j;
	}
}

//
//
//
void Pat1010()
{
	int a, b;
	int flag = 1, count = 0;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		++count;
		if (b != 0)
		{
			if (flag == 1)
			{
				printf("%d %d", a*b, b - 1);
				flag = 0;
			}
			else
			{
				printf(" %d %d", a*b, b - 1);
			}
		}
		else
			if (count == 1)
				printf("0 0\n");
	}
}

void Pat1011()
{
	int T, i = 0;
	long int a, b, c;
	scanf("%d", &T);
	while (i < T)
	{
		scanf("%ld %ld %ld", &a, &b, &c);
		if (a + b > c)printf("Case #%d: true\n", i++ + 1);
		else printf("Case #%d: false\n", i++ + 1);
	}
}

void Pat1012()
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
}

void Pat1013()
{
	int M, N, count = 0, sumCount = 0, i = 2, j = 2, isSuShu = 1;
	scanf("%d %d", &M, &N);

	while (1)
	{
		for (j = 2; j <= sqrt(i); ++j)
		{
			if (i % 2 == 0 && i != 2){ isSuShu = 0; break; }
			if (i%j == 0){ isSuShu = 0; break; }
		}
		if (j > sqrt(i))isSuShu = 1;
		if (isSuShu)
		{
			count += 1;
			if (count >= M&&count <= N)
			{
				sumCount += 1;
				if (sumCount % 10 == 0)
				{
					printf("%d\n", i);
				}
				else if (sumCount == N - M + 1)
				{
					printf("%d", i);
				}
				else
					printf("%d ", i);
			}
			else if (count > N)
				break;
		}
		++i;
	}
}

void Pat1014()
{
	const char *week[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	char s1[61], s2[61], s3[61], s4[61];
	scanf("%s %s %s %s", s1, s2, s3, s4);
	int i = 0;
	for (i; s1[i] && s2[i]; ++i)
	{
		if (s1[i] >= 'A'&&s1[i] <= 'G'&&s1[i] == s2[i]){ printf("%s ", *(week + s1[i] - 'A')); break; }
	}
	for (++i; s1[i] && s2[i]; ++i)
	{
		if (s1[i] == s2[i])
		{
			if (isdigit(s1[i]))
			{
				printf("%02d:", s1[i] - '0'); break;
			}
			if (s1[i] >= 'A'&&s1[i] <= 'N')
			{
				printf("%02d:", s1[i] - 'A' + 10); break;
			}
		}
	}
	for (i = 0; s3[i] && s4[i]; ++i)
	{
		if (isalpha(s3[i]) && s3[i] == s4[i]){ printf("%02d\n", i); break; }
	}
}
//qsort
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

void Pat1015()
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
}

void Pat1016()
{
	char A[15], B[15];
	long int DA, DB;
	long int i, DANum, DBNum;
	long int sum = 0;
	i = 0;
	DANum = 0;
	DBNum = 0;
	scanf("%s %d %s %d", A, &DA, B, &DB);
	while (A[i] != '\0')
	{
		int a = A[i] - '0';
		if (a == DA)
			DANum += 1;
		++i;
	}
	i = 0;
	while (B[i] != '\0')
	{
		int a = B[i] - '0';
		if (a == DB)
			DBNum += 1;
		++i;
	}
	while (DANum)
	{
		int a = DA;
		for (int i = 1; i < DANum; ++i)
		{
			a = a * 10;
		}
		sum += a;
		--DANum;
	}
	while (DBNum)
	{
		int a = DB;
		for (int i = 1; i < DBNum; ++i)
		{
			a = a * 10;
		}
		sum += a;
		--DBNum;
	}
	printf("%ld\n", sum);
}
//有一个只有一位数字的测试点
void Pat1017()
{
	char A[1001];
	int Q[1000], B = 0, R = 0, i = 0;
	scanf("%s %d", A, &B);
	for (i = 0; A[i] != '\0'; ++i)
	{
		int tmp = R * 10 + A[i] - '0';
		Q[i] = tmp / B;
		R = tmp%B;
	}
	for (int j = 0; j < i; ++j){ if (j == 0 && Q[j] == 0 && i != 1)continue; printf("%d", Q[j]); }
	putchar(' ');
	printf("%d\n", R);
}
//
//优化
//
void Pat1018()
{
	int n;
	int countCofJia, countJofJia, countBofJia, countCofYi, countJofYi, countBofYi, countWin, countLose, maxJia, maxYi;
	countCofJia = countJofJia = countBofJia = countCofYi = countJofYi = countBofYi = countWin = countLose = maxJia = maxYi = 0;
	char a[2], b[2];
	scanf("%d", &n);
	int i = n;
	while (i)
	{
		scanf("%s %s", a, b);
		if (a[0] == 'C'&&b[0] == 'J')
		{
			countWin += 1;
			countCofJia += 1;
		}
		if (a[0] == 'J'&&b[0] == 'B')
		{
			countWin += 1;
			countJofJia += 1;
		}
		if (a[0] == 'B'&&b[0] == 'C')
		{
			countWin += 1;
			countBofJia += 1;
		}
		if (a[0] == 'J'&&b[0] == 'C')
		{
			countLose += 1;
			countCofYi += 1;
		}
		if (a[0] == 'B'&&b[0] == 'J')
		{
			countLose += 1;
			countJofYi += 1;
		}
		if (a[0] == 'C'&&b[0] == 'B')
		{
			countLose += 1;
			countBofYi += 1;
		}
		--i;
	}
	maxJia = max(countJofJia, max(countCofJia, countBofJia));
	maxYi = max(countJofYi, max(countCofYi, countBofYi));
	printf("%d %d %d\n", countWin, n - countWin - countLose, countLose);
	printf("%d %d %d\n", countLose, n - countWin - countLose, countWin);
	if (maxJia == countBofJia)
		printf("B ");
	else if (maxJia == countCofJia)
		printf("C ");
	else
		printf("J ");

	if (maxYi == countBofYi)
		printf("B");
	else if (maxYi == countCofYi)
		printf("C");
	else
		printf("J");
}
//用字符串会超时
void Pat1019()
{
	int num;
	int number[4];
	int a = 0, b = 0, c = 0;
	scanf("%s", &num);
	number[0] = num / 1000;
	number[1] = num / 100 % 10;
	number[2] = num / 10 % 10;
	number[3] = num % 10;
	while (1)
	{
		sort(number, number + 4, compare);
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
}
//结构体排序
//单价高的优先
//
typedef struct good{
	float num;
	float sumPrice;
	float perPrice;
}good;
int cmpa(const void *a, const void *b)
{
	return (*(good*)a).perPrice<(*(good*)b).perPrice;
}
void Pat1020()
{
	good g[1000];
	int N, D;
	float gain = 0.0f;
	scanf("%d %d", &N, &D);
	for (int i = 0; i<N; ++i)scanf("%f", &g[i].num);
	for (int i = 0; i<N; ++i)
	{
		scanf("%f", &g[i].sumPrice);
		g[i].perPrice = g[i].sumPrice / g[i].num;
	}
	qsort(g, N, sizeof(good), cmpa);
	for (int i = 0; i<N; ++i)
	{
		if (D <= g[i].num)
		{
			gain += D*g[i].perPrice;
			break;
		}
		else
		{
			D = D - g[i].num;
			gain += g[i].sumPrice;
		}
	}
	printf("%.2f\n", gain);
}

void Pat1021()
{
	char str[1000];
	int a[10] = { 0 };
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == '0')
			a[str[i] - '0'] += 1;
		if (str[i] == '1')
			a[str[i] - '0'] += 1;
		if (str[i] == '2')
			a[str[i] - '0'] += 1;
		if (str[i] == '3')
			a[str[i] - '0'] += 1;
		if (str[i] == '4')
			a[str[i] - '0'] += 1;
		if (str[i] == '5')
			a[str[i] - '0'] += 1;
		if (str[i] == '6')
			a[str[i] - '0'] += 1;
		if (str[i] == '7')
			a[str[i] - '0'] += 1;
		if (str[i] == '8')
			a[str[i] - '0'] += 1;
		if (str[i] == '9')
			a[str[i] - '0'] += 1;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (a[i] != 0)
			printf("%d:%d\n", i, a[i]);
	}
}

void Pat1022()
{
	int A, B, D;
	scanf("%d %d %d", &A, &B, &D);
	int C = A + B;
	int a[10000];
	for (int j = 0; j < 10000; ++j)
		a[j] = -1;
	int i = 0;
	for (i;; ++i)
	{
		if (C / D == 0)
			break;
		a[i] = C % D;
		C = C / D;
	}
	a[i] = C % D;
	for (i; i >= 0; --i)
	{
		printf("%d", a[i]);
	}
}

void Pat1023()
{
	int a[10];
	char str[55];
	int pos = 1;
	for (int i = 0; i < 55; ++i)
		str[i] = '\0';
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < 10; ++i)
	{
		if (a[i] != 0)
		{
			str[0] = i + '0';
			--a[i];
			break;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		while (a[i]-- != 0)str[pos++] = i + '0';
	}
	printf("%s", str);
}

//有三个测试点超时（已通过)
void Pat1024()
{
	char sym, A[10000];
	int i = 0;//小数位数
	sym = getchar();
	while ((A[i++] = getchar()) != 'E');
	int e;
	scanf("%d", &e);
	i -= 3;//减去整数、小数点和E
	if (sym == '-')putchar('-');
	if (e >= 0)
	{
		if (e <= i)
		{
			putchar(A[0]);
			int j = 2,k = e;
			while (k){ putchar(A[j++]); --k; }
			if (e != i)putchar('.');
			while (A[j] != 'E')putchar(A[j++]);
		}
		else
		{
			int j = 0;
			while (A[j] != 'E'){ if (A[j] != '.')putchar(A[j]); ++j; }
			j = e - i;
			while (j--)putchar('0');
		}
	}
	else
	{
		int j = abs(e);
		putchar('0'); putchar('.'); --j;
		while (j--)putchar('0');
		++j;
		while (A[j] != 'E'){ if (A[j] != '.')putchar(A[j]); ++j; }
	}
}

void Pat1025()
{

}

void Pat1026()
{
	int C1, C2;
	scanf("%d %d", &C1, &C2);
	int progRunTime = (int)((double)(C2 - C1) / 100 + 0.5f);
	int hh = progRunTime / (60 * 60);
	int mm = (progRunTime % (60 * 60)) / 60;
	int ss = (progRunTime % (60 * 60)) % 60;
	printf("%02d:%02d:%02d", hh, mm, ss);
}

//后面的空格不能输出
void Pat1027()
{
	char c;
	int N, sum = 1, count = 1, i = 1, remain = 0;
	scanf("%d %c", &N, &c);
	for (i = 1;; ++i)
	{
		count += 2;
		sum = sum + ((i * 2) + 1) * 2;
		if (sum > N)
			break;
	}
	sum = sum - ((i * 2) + 1) * 2;
	count -= 2;
	remain = N - sum;

	for (i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			if ((j >= i && j <= count - 1 - i) || (j <= i&&j >= count - 1 - i))
			{
				printf("%c", c);
			}
			else if (i>j && j<count-1-i )
			{
				printf(" ");
			}
			else
				break;
		}
		printf("\n");
	}
	printf("%d\n", remain);
}

//利用便利的输入方式可以直接比较生日，不用重新写判断边界函数
//注意合法生日为0的情况
void Pat1028()
{
	int N, count = 0;
	char birth[11], oBirth[11], yBirth[11], oldest[6], youngest[6], tmp[6];
	scanf("%d", &N);
	for (int i = 0; i<N; ++i)
	{
		scanf("%s %s", tmp, birth);
		if (strcmp(birth, "2014/09/06") <= 0 &&
			strcmp(birth, "1814/09/06") >= 0 &&
			!count)
		{
			++count; strcpy(oldest, tmp); strcpy(oBirth, birth); strcpy(youngest, tmp); strcpy(yBirth, birth); continue;
		}
		if (strcmp(birth, "2014/09/06") <= 0 &&
			strcmp(birth, "1814/09/06") >= 0)
		{
			++count;
			if (strcmp(birth, oBirth) < 0){ strcpy(oldest, tmp); strcpy(oBirth, birth); }
			if (strcmp(birth, yBirth) > 0){ strcpy(youngest, tmp); strcpy(yBirth, birth); }
		}
	}
	if (count)
		printf("%d %s %s", count, oldest, youngest);
	else
		printf("0\n");
}

void Pat1029()
{
	char srcStr[85], destStr[85];
	scanf("%s %s", srcStr, destStr);
	int srcLength = strlen(srcStr), destLength = strlen(destStr);
	char a[35];
	int i = 0, j = 0, k = 0;
	bool isFound = false;
	for (i = 0; i < srcLength; ++i)
	{
		if (srcStr[i] != destStr[j])
		{
			isFound = false;
			if (srcStr[i] >= 97 && srcStr[i] <= 122)
			{
				for (int pos = 0; pos < k; ++pos)
				{
					if (a[pos] == srcStr[i] - 32)
					{
						isFound = true;
						break;
					}
				}
				if (!isFound)
				{
					a[k] = srcStr[i] - 32;
					++k;
				}
			}
			else
			{
				for (int pos = 0; pos < k; ++pos)
				{
					if (a[pos] == srcStr[i])
					{
						isFound = true;
						break;
					}
				}
				if (!isFound)
				{
					a[k] = srcStr[i];
					++k;
				}
			}
			continue;
		}
		else
			++j;
	}
	for (int n = 0; n < k; ++n)
	{
		printf("%c", a[n]);
	}
	printf("\n");
}

//有一个测试用例是输入1 1 x
//两个数相乘可能超过int能存储的范围

int cmpSeries(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

void Pat1030()
{
	int N, p;
	scanf("%d%d", &N, &p);
	long *ptr = (long*)malloc(sizeof(long*)*N);
	for (int i = 0; i < N; ++i)scanf("%ld", ptr + i);
	qsort(ptr, N, sizeof(long), cmpSeries);
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

	//超时
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


	//超时	
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
}

void Pat1031()
{
	int N;
	int q[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	char zm[] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
	const int length = 17;
	int sum = 0, a = 0;
	bool isAllPassed = true, isRight = true;
	scanf("%d", &N);
	char id[20];
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", id);
		sum = 0;
		isRight = true;
		for (int j = 0; j < length; ++j)
		{
			int tmp = id[j] - '0';
			if (tmp >= 0 && tmp <= 9)
			{
				sum = sum + tmp * q[j];
			}
			else
			{
				isAllPassed = false;
				isRight = false;
				break;
			}
		}
		if (isRight)
		{
			a = sum % 11;
			if (id[length] != zm[a])
			{
				isAllPassed = false;
				isRight = false;
			}
		}
		if (!isRight)
			printf("%s\n", id);
	}
	if (isAllPassed)
		printf("All passed\n");
}

typedef struct info{
	int id;
	int score;
}info;

bool compareStruct(info a, info b)
{
	return a.id < b.id;
}

int cmpInfo(const void *a, const void *b)
{
	return (*(info*)a).id > (*(info*)b).id;
}

void Pat1032()
{
	int N;
	info ifo[100001];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &ifo[i].id, &ifo[i].score);
	}
	qsort(ifo, N, sizeof(info), cmpInfo);
	int maxSum = -1, scoreSum = 0, maxID = 1, curID = 1;
	for (int i = 0; i < N; ++i)
	{
		if (ifo[i].id != curID)
		{
			if (scoreSum > maxSum)
			{
				maxSum = scoreSum;
				maxID = curID;
			}
			scoreSum = ifo[i].score;
			curID = ifo[i].id;
		}
		else
		{
			scoreSum += ifo[i].score;
		}
	}
	if (scoreSum>maxSum){ maxSum = scoreSum; maxID = curID; }
	printf("%d %d\n", maxID, maxSum);
}

void Pat1033()
{
	char str[45];
	char txt[100001];
	gets(str);
	gets(txt);
	int isUpper = 1;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == '+')
		{
			isUpper = 0;
			break;
		}
	}
	for (int i = 0; str[i] != '\0'; ++i)
	{
		for (int j = 0; txt[j] != '\0'; ++j)
		{
			if (!isUpper)
			{
				if (txt[j] >= 65 && txt[j] <= 90)
				{
					txt[j] = '*';
				}
			}
			if ((str[i] >= 'A'&&str[i] <= 'Z') || (str[i] >= 'a'&&str[i] <= 'z'))
			{
				if (str[i] == txt[j] || str[i] + 32 == txt[j])
					txt[j] = '*';
			}
			else
			{
				if (str[i] == txt[j])
					txt[j] = '*';
			}
		}
	}
	for (int i = 0; txt[i] != '\0'; ++i)
	{
		if (txt[i] != '*' && txt[i] != '+')
			printf("%c", txt[i]);
	}
	printf("\n");
}

//考察最大公约数和输出表示
//分子、分母是整型范围内整数，但是相乘后可能会超出整形范围
//
void print(long a, long b, long c, long d, int flag)
{
	long g = 1;
	if (a < 0)g = gcd(-a, b); else g = gcd(a, b);
	a /= g; b /= g;
	if (c < 0)g = gcd(-c, d); else g = gcd(c, d);
	c /= g; d /= g;
	if (a<0)printf("(");
	if (b != 1)
		if (a / b)printf("%d %d/%d", a / b, a%b < 0 ? -a%b : a%b, b); else if (a)printf("%d/%d", a, b); else printf("0");
	else
		printf("%d", a);
	if (a<0)printf(")");
	switch (flag)
	{
	case 1:printf(" + "); break;
	case 2:printf(" - "); break;
	case 3:printf(" * "); break;
	case 4:printf(" / "); break;
	deafult:break;
	}
	if (c<0)printf("(");
	if (d != 1)
		if (c / d)printf("%d %d/%d", c / d, c%d < 0 ? -c%d : c%d, d); else if (c)printf("%d/%d", c, d); else printf("0");
	else
		printf("%d", c);
	if (c<0)printf(")");
	printf(" = ");
}

void printAdd(long a, long b, long c, long d)
{
	long den = b*d;
	long num = a*d + b*c;
	long g = 1;
	if (num < 0)g = gcd(den, -num); else g = gcd(den, num);
	den /= g;
	num /= g;
	print(a, b, c, d, 1);
	if (num<0)printf("(");
	if (den != 1)
		if (num / den)printf("%d %d/%d", num / den, num%den<0 ? -num%den : num%den, den); else
			if (num)printf("%d/%d", num, den); else printf("0");
	else
		printf("%d", num);
	if (num<0)printf(")");
}

void printSub(long a, long b, long c, long d)
{
	long den = b*d;
	long num = a*d - b*c;
	long g = 1;
	if (num < 0)g = gcd(den, -num); else g = gcd(den, num);
	den /= g;
	num /= g;
	print(a, b, c, d, 2);
	if (num<0)printf("(");
	if (den != 1)
		if (num / den)printf("%d %d/%d", num / den, num%den<0 ? -num%den : num%den, den); else
			if (num)printf("%d/%d", num, den); else printf("0");
	else
		printf("%d", num);
	if (num<0)printf(")");
}

void printMulti(long a, long b, long c, long d)
{
	long den = b*d;
	long num = a*c;
	long g = 1;
	if (num < 0)g = gcd(den, -num); else g = gcd(den, num);
	den /= g;
	num /= g;
	print(a, b, c, d, 3);
	if (num<0)printf("(");
	if (den != 1)
		if (num / den)printf("%d %d/%d", num / den, num%den<0 ? -num%den : num%den, den); else
			if (num)printf("%d/%d", num, den); else printf("0");
	else
		printf("%d", num);
	if (num<0)printf(")");
}

void printDiv(long a, long b, long c, long d)
{
	long den = b*c;
	long num = a*d;
	long g = 1;//
	if (den < 0 && num > 0)g = gcd(-den, num);
	if (den > 0 && num < 0)g = gcd(den, -num);
	if (den < 0 && num < 0)g = gcd(-den, -num);
	if (den > 0 && num > 0)g = gcd(den, num);
	den /= g;
	num /= g;
	if (den < 0){ den = -den; num = -num; }
	print(a, b, c, d, 4);
	if (!c){ printf("Inf"); return; }
	if (num<0)printf("(");
	if (den != 1)
		if (num / den)printf("%d %d/%d", num / den, num%den<0 ? -num%den : num%den, den); else
			if (num)printf("%d/%d", num, den); else printf("0");
	else
		printf("%d", num);
	if (num<0)printf(")");
}

void Pat1034()
{
	long a1, b1, a2, b2;
	scanf("%ld/%ld%ld/%ld", &a1, &b1, &a2, &b2);
	printAdd(a1, b1, a2, b2); printf("\n");
	printSub(a1, b1, a2, b2); printf("\n");
	printMulti(a1, b1, a2, b2); printf("\n");
	printDiv(a1, b1, a2, b2); printf("\n");
}
//
//
int cmpSort(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
void Pat1035()
{
	int N, srcAry[100], destAry[100], i, j;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)scanf("%d", &srcAry[i]);
	for (i = 0; i < N; ++i)scanf("%d", &destAry[i]);
	//相等的情况
	for (i = 0; i < N - 1 && destAry[i] <= destAry[i + 1]; ++i);
	for (j = i + 1; j < N&&srcAry[j] == destAry[j]; ++j);
	if (j == N)
	{
		if (i == N - 1)i += 1; else i += 2;
		printf("Insertion Sort\n");
		qsort(srcAry, i, sizeof(int), cmpSort);
	}
	else
	{
		printf("Merge Sort\n");
		int flag = 1;
		for (int k = 1; k <= N&&flag; k *= 2)
		{
			int index;
			for (index = 0; index < N&&srcAry[index] == destAry[index]; ++index);
			if (index == N)
				flag = 0;
			for (j = 0; j < N / k; ++j)
				qsort(srcAry + j*k, k, sizeof(int), cmpSort);
			qsort(srcAry + j*k, N%k, sizeof(int), cmpSort);
		}
	}
	for (i = 0; i < N; ++i){ if (i == 0)printf("%d", srcAry[i]); else printf(" %d", srcAry[i]); }
}

void Pat1036()
{
	int N;
	char c;
	scanf("%d %c", &N, &c);
	int row = N / 2.0f + 0.5f;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i == 0 || i == row - 1)
				printf("%c", c);
			else
			{
				if (j == 0 || j == N - 1)
					printf("%c", c);
				else
					printf(" ");
			}
		}
		printf("\n");
	}
}
//17S->1G
//29K->1S
//
void Pat1037()
{
	typedef struct money{
		int Galleon;
		int Sickle;
		int Knut;
	}money;
	money needMoney, payMoney;
	const int kTos = 29;
	const int sToG = 17;
	scanf("%d.%d.%d %d.%d.%d", &needMoney.Galleon, &needMoney.Sickle, &needMoney.Knut, &payMoney.Galleon, &payMoney.Sickle, &payMoney.Knut);
	int need = needMoney.Galleon*sToG*kTos + needMoney.Sickle*kTos + needMoney.Knut;
	int pay = payMoney.Galleon*sToG*kTos + payMoney.Sickle*kTos + payMoney.Knut;
	if (pay >= need)
	{
		int remain = pay - need;
		int remainK = remain % kTos;
		remain = remain / kTos;
		int remainS = remain % sToG;
		remain = remain / sToG;
		printf("%d.%d.%d\n", remain, remainS, remainK);
	}
	else
	{
		int remain = need - pay;
		int remainK = remain % kTos;
		remain = remain / kTos;
		int remainS = remain % sToG;
		remain = remain / sToG;
		printf("-%d.%d.%d\n", remain, remainS, remainK);
	}
}

void Pat1038()
{
	int N, K, score[101];
	scanf("%d", &N);
	for (int i = 0; i < 101; ++i)score[i] = 0;
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		++score[tmp];
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		if (i != K - 1)printf("%d ", score[tmp]);
		else printf("%d", score[tmp]);
	}
	printf("\n");
}

void Pat1039()
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
	bool canBuy = true;
	int lackSum = 0;
	for (int i = 0; i < count; ++i)
	{
		if (b[i].num != 0)
		{
			lackSum += b[i].num;
			canBuy = false;
		}
	}
	if (canBuy)
	{
		printf("Yes %d", destLength - srcLength);
	}
	else
	{
		printf("No %d", lackSum);
	}
}

//取模运算
//(a+b)%c = (a%c+b%c)%c
void Pat1040()
{
	const int inf = 1000000007;
	int p, pa, result;
	p = pa = result = 0;
	char c;
	while ((c = getchar()) != '\n')
	{
		if (c == 'P')++p;
		if (c == 'A')pa = (pa + p) % inf;
		if (c == 'T')result = (result + pa) % inf;
	}
	printf("%d\n", result);
}

void Pat1041()
{
	typedef struct info{
		char id[14];
		int testID;
		int examID;
	}info;
	info ifo[1000];
	int N, M, checkAry[1000];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s %d %d", ifo[i].id, &ifo[i].testID, &ifo[i].examID);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &checkAry[i]);
		for (int j = 0; j < N; ++j)
		{
			if (ifo[j].testID == checkAry[i])
			{
				printf("%s %d\n", ifo[j].id, ifo[j].examID);
				break;
			}
		}
	}
}

void Pat1042()
{
	char str[1000];
	int num[26];
	for (int i = 0; i < 26; ++i)
	{
		num[i] = 0;
	}
	gets(str);
	int length = strlen(str);
	for (int i = 0; i < length; ++i)
	{
		if (str[i] >= 65 && str[i] <= 90)
			num[str[i] - 65] += 1;
		if (str[i] >= 97 && str[i] <= 122)
			num[str[i] - 97] += 1;
	}
	int maxNdx = 0;
	for (int i = 1; i < 26; ++i)
	{
		if (num[maxNdx] < num[i])
		{
			maxNdx = i;
		}
	}
	printf("%c %d\n", maxNdx + 97, num[maxNdx]);
}

void Pat1043()
{
	char str[10000];
	gets(str);
	int num[6];
	int sum = 0;
	for (int i = 0; i < 6; ++i)
	{
		num[i] = 0;
	}
	int length = strlen(str);
	for (int i = 0; i < length; ++i)
	{
		if (str[i] == 'P')num[0] += 1;
		if (str[i] == 'A')num[1] += 1;
		if (str[i] == 'T')num[2] += 1;
		if (str[i] == 'e')num[3] += 1;
		if (str[i] == 's')num[4] += 1;
		if (str[i] == 't')num[5] += 1;
		if (str[i] == 'P' || str[i] == 'A' || str[i] == 'T' || str[i] == 'e' || str[i] == 's' || str[i] == 't')
			sum += 1;
	}
	while (sum)
	{
		for (int i = 0; i < 6; i++)
		{
			if (num[i] != 0)
			{
				num[i] -= 1;
				sum -= 1;
				if (i == 0)printf("P");
				if (i == 1)printf("A");
				if (i == 2)printf("T");
				if (i == 3)printf("e");
				if (i == 4)printf("s");
				if (i == 5)printf("t");
			}
		}
	}
	printf("\n");
}

//输入
//数字转换成火星数字整数的时候不带零
void Pat1044()
{
	const char *MarsLow[] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	const char *MarsUp[] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	int N, space;
	char str[10];
	scanf("%d", &N);
	getchar();
	for (int i = 0; i<N; ++i)
	{
		space = 0;
		memset(str, 0, sizeof(char)* 10);
		int j = 0;
		while ((str[j] = getchar()) != '\n')
		{
			if (str[j] == ' ')space = 1;
			++j;
		}
		if (isdigit(str[0]))
		{
			int n = atoi(str);
			int a = n / 13;
			if (a)
			{
				printf("%s", *(MarsUp + a - 1));
				if (n % 13)printf(" %s\n", *(MarsLow + n % 13)); else printf("\n");
			}

			else printf("%s\n", *(MarsLow + n % 13));
		}
		else
		if (space)
		{
			char s[10];
			int j = 0, found = 0, sum = 0;
			while (str[j] != ' '){ s[j] = str[j]; ++j; }
			int spacePos = j + 1;
			s[j--] = '\0';
			for (j = 0; j<12; ++j)
			{
				if (!strcmp(*(MarsUp + j), s)){ found = 1; break; }
			}
			if (found)sum += (j + 1) * 13;
			j = 0; found = 0;
			while (str[spacePos] != '\n'){ s[j] = str[spacePos]; ++spacePos; ++j; }
			s[j] = '\0';
			for (j = 0; j<13; ++j)
			{
				if (!strcmp(*(MarsLow + j), s)){ found = 1; break; }
			}
			if (found)sum += j;
			printf("%d\n", sum);
		}
		else
		{
			char s[10];
			int j = 0, k = 0, found = 0, sum = 0;
			while (str[j] != '\0'){ s[j] = str[j]; ++j; }
			s[--j] = '\0';
			for (j = 0; j<12; ++j)
			{
				if (!strcmp(*(MarsUp + j), s)){ found = 1; break; }
			}
			for (k = 0; k<13; ++k)
			{
				if (!strcmp(*(MarsLow + k), s)){ break; }
			}
			if (found)sum += (j + 1) * 13; else sum += k;
			printf("%d\n", sum);
		}
	}
}

//主元为0时仍然输出一行回车
void Pat1045()
{
	int N, ary[100000], minAry[100000], maxAry[100000], count = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)scanf("%d", ary + i);
	maxAry[0] = ary[0];
	for (int i = 1; i < N; ++i)if (ary[i] >= maxAry[i - 1])maxAry[i] = ary[i]; else maxAry[i] = maxAry[i - 1];
	minAry[N - 1] = ary[N - 1];
	for (int i = N - 2; i >= 0; --i)if (ary[i] <= minAry[i + 1])minAry[i] = ary[i]; else minAry[i] = minAry[i + 1];
	for (int i = 0; i < N; ++i)if (minAry[i] == maxAry[i])++count;
	printf("%d\n", count);
	if (count == 0)printf("\n");
	for (int i = 0; i < N; ++i)
	{
		if (minAry[i] == maxAry[i])
		{
			--count;
			if (count)printf("%d ", ary[i]); else printf("%d", ary[i]);
		}
	}
}

void Pat1046()
{
	int N;
	int a1, a2, b1, b2, c1, c2;
	c1 = c2 = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
		if (a1 + b1 == a2&&a1 + b1 == b2)
			continue;
		if (a1 + b1 == a2)
			c2 += 1;
		if (a1 + b1 == b2)
			c1 += 1;
	}
	printf("%d %d\n", c1, c2);
}

void Pat1047()
{
	int N;
	int teamScore[1001], teamID, stuID, score, maxScoreTeamID;
	for (int i = 1; i < 1001; ++i)
	{
		teamScore[i] = 0;
	}
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d-%d %d", &teamID, &stuID, &score);
		teamScore[teamID] += score;
	}
	maxScoreTeamID = 1;
	for (int i = 2; i < 1001; ++i)
	{
		if (teamScore[i]>teamScore[maxScoreTeamID])
			maxScoreTeamID = i;
	}
	printf("%d %d\n", maxScoreTeamID, teamScore[maxScoreTeamID]);
}

//不足的地方要补零
void Pat1048()
{
	char A[101], B[101];
	scanf("%s %s", A, B);
	int c = strlen(A) - strlen(B), maxLen = max(strlen(A), strlen(B)), pos = 1;
	if (c>0)
	{
		int len = strlen(B);
		++len;
		while (len >= 0){ B[len + c] = B[len]; --len; }
		while (c--)B[c] = '0';
	}
	else
	{
		c = abs(c);
		int len = strlen(A);
		++len;
		while (len >= 0){ A[len + c] = A[len]; --len; }
		while (c--)A[c] = '0';
	}
	for (int i = maxLen - 1; i >= 0; --i)
	{
		if (pos % 2 == 0)
		{
			int tmp = B[i] - A[i];
			if (tmp<0)tmp += 10;
			B[i] = tmp + '0';
		}
		else
		{
			int tmp = (A[i] - '0' + B[i] - '0') % 13;
			if (tmp < 10)B[i] = tmp + '0';
			else
			{
				if (tmp == 10)B[i] = 'J';
				if (tmp == 11)B[i] = 'Q';
				if (tmp == 12)B[i] = 'K';
			}
		}
		++pos;
	}
	printf("%s\n", B);
}

void Pat1049()
{
	int N;
	scanf("%d", &N);
	double d[100000];
	double sum = 0.0f;
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf", &d[i]);
		sum += d[i] * (N - i)*(i + 1);
	}
	printf("%.2lf\n", sum);
}
//
//
//
int cmpMatrix(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}
void Pat1050()
{
	int N;
	scanf("%d", &N);
	int *p = (int*)malloc(sizeof(int)*N);
	int *matrix = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i<N; ++i)scanf("%d", p + i);
	qsort(p, N, sizeof(int), cmpMatrix);
	int m, n;
	for (m = 0;; ++m)
	{
		if (m*m >= N&&N%m == 0)break;
	}
	n = N / m;
	int horizontal = n, vertical = m, index = 0, y = 0, x = -1;
	while (horizontal>0 && vertical>0)
	{
		for (int i = 0; i<horizontal&&vertical>0; ++i)
			matrix[y*n + ++x] = p[index++];
		--vertical;
		for (int i = 0; i<vertical&&horizontal>0; ++i)
			matrix[++y*n + x] = p[index++];
		--horizontal;
		for (int i = 0; i<horizontal&&vertical>0; ++i)
			matrix[y*n + --x] = p[index++];
		--vertical;
		for (int i = 0; i<vertical&&horizontal>0; ++i)
			matrix[--y*n + x] = p[index++];
		--horizontal;
	}
	for (int i = 0; i<m; ++i)
		for (int j = 0; j<n; ++j)
			printf("%d%c", matrix[i*n + j], (j + 1) % n ? ' ' : '\n');
}

void Pat1051()
{
	double R1, P1, R2, P2;
	scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);
	double a1 = R1 * cos(P1), b1 = R1 * sin(P1);
	double a2 = R2 * cos(P2), b2 = R2 * sin(P2);
	if (b1*a2 + a1*b2 < 0)
		if (a1*a2 - b1*b2 != 0)printf("%.2lf%.2lfi\n", a1*a2 - b1*b2, b1*a2 + a1*b2); else printf("%.2lfi\n", b1*a2 + a1*b2);
	else if (b1*a2 + a1*b2 > 0)
		if (a1*a2 - b1*b2 != 0)printf("%.2lf+%.2lfi\n", a1*a2 - b1*b2, b1*a2 + a1*b2); else printf("%.2lfi\n", b1*a2 + a1*b2);
	else
		if (a1*a2 - b1*b2 != 0)printf("%.2lf\n", a1*a2 - b1*b2); else printf("0");
}
//第2、第3个测试点注意用户可能输入小于1的数字（下越界）
void Pat1052()
{
	char handEmoji[10][5], eyeEmoji[10][5], mouthEmoji[10][5], ch[100];
	int flag = 0, i = 0, k = 0, hNum, eNum, mNum;
	gets(ch);
	while (ch[k] != '\0')
	{
		if (ch[k] == '[')flag = 1;
		if (flag)
		{
			int j = 0;
			++k;
			while (ch[k] != ']'){ handEmoji[i][j] = ch[k]; ++k; ++j; }
			handEmoji[i][j--] = '\0';
			flag = 0;
			++i;
		}
		++k;
	}
	hNum = i;
	k = i = 0;
	gets(ch);
	while (ch[k] != '\0')
	{
		if (ch[k] == '[')flag = 1;
		if (flag)
		{
			int j = 0;
			++k;
			while (ch[k] != ']'){ eyeEmoji[i][j] = ch[k]; ++k; ++j; }
			eyeEmoji[i][j--] = '\0';
			flag = 0;
			++i;
		}
		++k;
	}
	eNum = i;
	k = i = 0;
	gets(ch);
	while (ch[k] != '\0')
	{
		if (ch[k] == '[')flag = 1;
		if (flag)
		{
			int j = 0;
			++k;
			while (ch[k] != ']'){ mouthEmoji[i][j] = ch[k]; ++k; ++j; }
			mouthEmoji[i][j--] = '\0';
			flag = 0;
			++i;
		}
		++k;
	}
	mNum = i;
	int K, a, b, c, d, e;
	scanf("%d", &K);
	for (i = 0; i<K; ++i)
	{
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		if (a<1 || b<1 || c<1 || d<1 || e<1){ printf("Are you kidding me? @\\/@\n"); continue; }
		if (a>hNum || e > hNum){ printf("Are you kidding me? @\\/@\n"); continue; }
		if (b > eNum || d > eNum){ printf("Are you kidding me? @\\/@\n"); continue; }
		if (c > mNum){ printf("Are you kidding me? @\\/@\n"); continue; }
		printf("%s(%s%s%s)%s\n", handEmoji[a - 1], eyeEmoji[b - 1], mouthEmoji[c - 1], eyeEmoji[d - 1], handEmoji[e - 1]);
	}
}

//
void Pat1053()
{
	int N, D, K, count = 0, nullRoom = 0, mayNullRoom = 0;
	double e;
	scanf("%d %lf %d", &N, &e, &D);
	for (int i = 0; i<N; ++i)
	{
		scanf("%d", &K);
		count = 0;
		for (int j = 0; j<K; ++j)
		{
			double tmp;
			scanf("%lf", &tmp);
			if (tmp<e)++count;
		}
		if (count >= K / 2 + 1)
			if (K > D)++nullRoom; else ++mayNullRoom;
	}
	printf("%.1lf%% %.1lf%%\n", (double)mayNullRoom / N * 100, (double)nullRoom / N * 100);
}

void Pat1054()
{
	int N, count = 0;
	scanf("%d", &N);
	double d, sum = 0.0f;
	char str[100];
	for (int i = 0; i < N; ++i)
	{		
		scanf("%s", str);
		int dotNum = 0, dotNumberNum = 0, flag = 1, j = 0;
		for (j; str[j] != '\0'; ++j)
		{
			if (str[j] == '-'&& j == 0)continue;
			if ((str[j] < 48 || str[j]>57) && str[j] != '.'){ flag = 0; break; }
			if (str[j] == '.'&& dotNum){ flag = 0; break; }
			if (dotNum)dotNumberNum += 1;
			if (str[j] == '.')dotNum += 1;
			if (dotNumberNum > 2){ flag = 0; break; }
		}

		if (flag && atof(str) >= -1000 && atof(str) <= 1000)
		{
			sum += atof(str);
			count += 1;
		}
		else
		{
			printf("ERROR: %s is not a legal number\n", str);
		}

		//int length = strlen(str);
		//d = strtod(str, &endPtr);
		//char *dotPtr = strchr(str, '.');
		//int dotRight = 0;
		//if (dotPtr)
		//{
		//	int dotLength = strlen(dotPtr);
		//	if (dotLength == 2 || dotLength == 3)
		//	{
		//		int dotNum = 0;
		//		for (int j = 1; j < dotLength; ++j)
		//		{
		//			if (dotPtr[j] == '.')
		//			{
		//				dotNum += 1;
		//			}
		//		}
		//		if (dotNum >= 1)
		//			dotRight = 0;
		//		else
		//			dotRight = 1;
		//	}
		//}
		//else
		//	dotRight = 1;
		//if (d < -1000 ||
		//	d>1000 ||
		//	!dotRight ||
		//	*endPtr)
		//{
		//	printf("ERROR: %s is not a legal number\n", str);
		//}
		//else
		//{
		//	sum += d;
		//	count += 1;
		//}
	}
	if (count == 0)
		printf("The average of 0 numbers is Undefined\n");
	if (count == 1)
		printf("The average of 1 numbers is %.2lf\n", sum);
	if (count >= 2)
		printf("The average of %d numbers is %.2lf\n", count, sum / count);
	
}

typedef struct peo{
	char name[10];
	int height;
}peo;

int cmpHeight(const void *a, const void *b)
{
	if ((*(peo*)b).height == (*(peo*)a).height)
		return strcmp((*(peo*)a).name, (*(peo*)b).name);
	else
		return (*(peo*)b).height - (*(peo*)a).height;
}

void Pat1055()
{
	int N, K, i = 0;
	scanf("%d %d", &N, &K);
	peo *p = (peo*)malloc(sizeof(peo)*N);
	for (i = 0; i<N; ++i)
	{
		scanf("%s %d", (*(p + i)).name, &(*(p + i)).height);
	}
	int perRow = N / K, lastRow = N % K + perRow, pos = 0;
	qsort(p, N, sizeof(peo), cmpHeight);
	int x = 0;
	for (x = lastRow / 2 * 2 - 1; x > 0; x -= 2)
	{
		printf("%s ", (*(p + x)).name);
	}
	for (x = 0; x < lastRow; x += 2)
	{
		if (x == lastRow - 1 || x == lastRow - 2)printf("%s\n", (*(p + x)).name);
		else printf("%s ", (*(p + x)).name);
	}

	for (int j = lastRow; j < N; j += perRow)
	{
		for (x = perRow / 2 * 2 - 1; x + j > j; x -= 2)
		{
			printf("%s ", (*(p + j + x)).name);
		}
		for (x = 0; x < perRow; x += 2)
		{
			if (x == perRow - 1 || x == perRow - 2)printf("%s\n", (*(p + j + x)).name);
			else printf("%s ", (*(p + j + x)).name);
		}
	}
}

void Pat1056()
{
	int N, a[10], sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &a[i]); 
		sum += (a[i] * 10 + a[i])*(N - 1);
	}
	printf("%d\n", sum);	
}

void Pat1057()
{
	char c;
	int sum = 0, zeroCount = 0, oneCount = 0;
	while ((c = getchar()) != '\n')
	{
		if (c >= 65 && c <= 90)sum += c - 64;
		if (c >= 97 && c <= 122)sum += c - 96;
	}
	if (sum)++oneCount;
	while (sum / 2)
	{
		if (sum % 2)++oneCount; else ++zeroCount;
		sum = sum / 2;
	}
	printf("%d %d\n", zeroCount, oneCount);
}

//
typedef struct option{
	int score;
	int optionNum;
	int rightNum;
	char rightChoose[6];
}option;

void Pat1058()
{
	option opt[100];
	int N, M, wrongCnt[100];
	memset(wrongCnt, 0, sizeof(int) * 100);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d%d%d", &opt[i].score, &opt[i].optionNum, &opt[i].rightNum);
		for (int j = 0; j < opt[i].rightNum; ++j)
			scanf(" %c", &opt[i].rightChoose[j]);
		opt[i].rightChoose[opt[i].rightNum] = '\0';
	}
	for (int i = 0; i < N; ++i)
	{ 
		int score = 0;
		scanf("\n");
		for (int j = 0; j < M; ++j)
		{
			if (j != 0)scanf(" ");
			int num;
			char ans[6];
			scanf("(%d", &num);
			for (int k = 0; k < num; ++k)
				scanf(" %c", &ans[k]);
			ans[num] = '\0';
			scanf(")");
			if (num != opt[j].rightNum)
			{
				++wrongCnt[j];
				continue;
			}
			else
			{
				if (!strcmp(ans, opt[j].rightChoose))
					score += opt[j].score;
				else
					++wrongCnt[j];
			}
		}
		printf("%d\n", score);
	}
	int maxWrongTimes = 0;
	for (int i = 0; i < M; ++i)
	{
		if (wrongCnt[i]>maxWrongTimes)
			maxWrongTimes = wrongCnt[i];
	}
	if (!maxWrongTimes)
		printf("Too simple\n");
	else
	{
		printf("%d", maxWrongTimes);
		for (int i = 0; i < M; ++i)
		{
			if (wrongCnt[i] == maxWrongTimes)printf(" %d", i + 1);
		}
	}
}

void Pat1059()
{
	int N, K, flag, i, j;
	int rank[10001], id[10001], prime[10001];
	prime[1] = 0;
	id[1] = 0;
	for (int i = 2; i <= 10000; ++i)
	{
		prime[i] = 1;
		id[i] = 0;
		for (int j = 2; j <= sqrt(i); ++j)
			if (i%j == 0){ prime[i] = 0; break; }
	}
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)scanf("%d", &rank[i]);
	scanf("%d", &K);
	for (i = 1; i <= K; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		if (id[tmp] == 0)
		{
			for (j = 1; j <= N; ++j)
			{
				if (rank[j] == tmp)
				{
					if (j == 1)printf("%04d: Mystery Award\n", tmp);
					else if (prime[j])printf("%04d: Minion\n", tmp);
					else printf("%04d: Chocolate\n", tmp);
					id[tmp] = 1;
					break;
				}
			}
			if (j > N){ printf("%04d: Are you kidding?\n", tmp); id[tmp] = -1; }
		}
		else if (id[tmp] == -1)printf("%04d: Are you kidding?\n", tmp);
		else printf("%04d: Checked\n", tmp);
	}
}
//理解题目意思
//自己的方法待改进
int cmpEddington(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}
void Pat1060()
{
	int N, ary[100000], max = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)scanf("%d", ary + i);
	qsort(ary, N, sizeof(int), cmpEddington);
	for (int i = 0; i < N; ++i)
	{
		if (i + 1 >= ary[i])
			break;
		else
			++max;
	}
	printf("%d", max);
	//int N, ary[100000], ary2[100000], max = 0;
	//memset(ary2, 0, sizeof(int) * 100000);
	//scanf("%d", &N);
	//for (int i = 0; i < N; ++i)
	//{
	//	scanf("%d", ary + i);
	//	for (int j = ary[i] - 2; j >= 0; --j)
	//		ary2[j] += 1;
	//}
	//for (int i = 0; i < N; ++i)
	//	if (i + 1 == ary2[i] && i + 1 > max)
	//		max = i + 1;
	//printf("%d", max);
	//return 0;	
}

void Pat1061()
{
	int N, M, score[100], answer[100];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &score[i]);
	}
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &answer[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		int tmp, sum = 0;
		for (int j = 0; j < M; ++j)
		{		
			scanf("%d", &tmp);
			if (tmp == answer[j])sum += score[j];
		}
		printf("%d\n", sum);
	}	
}

//不要用浮点型，会有精度损失
//最大公约数可能等于K本身(测试点4)
void Pat1062()
{
	int N1, M1, N2, M2, K;
	scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);
	if (N1*M2>M1*N2)
	{
		int tmp;
		tmp = N1; N1 = N2; N2 = tmp;
		tmp = M1; M1 = M2; M2 = tmp;
	}
	int i = 1, k[1000], pos = 0, flag = 1;
	while (N1*K >= i*M1)++i;
	while (i*M2 < N2*K)
	{
		if (gcd(i, K) == 1)
		{
			k[pos] = i; ++pos;
		}
		++i;
	}
	for (i = 0; i < pos; ++i)
	{
		if (i == 0)printf("%d/%d", k[i], K);
		else printf(" %d/%d", k[i], K);
	}
	/*
	int N1, M1, N2, M2, K;
	scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);
	if (N1*M2>M1*N2)
	{
		int tmp;
		tmp = N1; N1 = N2; N2 = tmp;
		tmp = M1; M1 = M2; M2 = tmp;
	}
	int i = 1, k[1000], pos = 0, flag = 1;
	while (N1*K>i*M1)++i;
	while (i*M2 < N2*K)
	{
		flag = 1;
		if (i % 2 == 0 && K % 2 == 0){ ++i; continue; }
		for (int j = 3; j <= min(i, K); j+=2)
		{			
			if (i%j == 0 && K%j == 0){ flag = 0; break; }
		}
		if (flag){ k[pos] = i; ++pos; }
		++i;
	}
	for (i = 0; i < pos; ++i)
	{
		if (i == 0)printf("%d/%d", k[i], K);
		else printf(" %d/%d", k[i], K);
	}
	
	*/
}

void Pat1063()
{
	int a, b, N;
	double max = 0.0f;
	scanf("%d", &N);
	for (int i = 0; i<N; ++i)
	{
		scanf("%d %d", &a, &b);
		if (sqrt(a*a + b*b)>max)max = sqrt(a*a + b*b);
	}
	printf("%.2lf\n", max);
}

void Pat1064()
{
	int N, num[50], tmp = 0, count = 0;
	char str[5];
	scanf("%d", &N);
	for (int i = 0; i < 50; ++i)num[i] = 0;
	for (int i = 0; i<N; ++i)
	{
		tmp = 0;
		scanf("%s", str);
		for (int j = 0; str[j] != '\0'; ++j)tmp += str[j] - '0';
		++num[tmp];
	}
	for (int i = 0; i < 50; ++i)if (num[i])++count;
	printf("%d\n", count);
	for (int i = 0; i<50; ++i)
		if (num[i]){ --count; if (count)printf("%d ", i); else printf("%d", i); }
}

//注意输出补0
//有个测试点最后一行不能换行

typedef struct guest{
	int isJoinParty;
	int partner;
}guest;

int cmpSingleDog(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

void Pat1065()
{
	int N, M, singleDog[10000], count;
	guest g[100000];
	for (int i = 0; i<100000; ++i){ g[i].partner = -1; g[i].isJoinParty = 0; }
	scanf("%d", &N);
	for (int i = 0; i<N; ++i)
	{
		int husband, wife;
		scanf("%d%d", &husband, &wife);
		g[husband].partner = wife;
		g[wife].partner = husband;
	}
	scanf("%d", &M);
	count = M;
	for (int i = 0; i<M; ++i)
	{
		scanf("%d", &singleDog[i]);
		g[singleDog[i]].isJoinParty = 1;
	}

	for (int i = 0; i<M; ++i)
	{
		if (g[singleDog[i]].partner == -1)continue;
		if (g[g[singleDog[i]].partner].isJoinParty)
		{
			singleDog[i] = -1; --count;
		}
	}
	qsort(singleDog, M, sizeof(int), cmpSingleDog);
	printf("%d\n", count);
	count = 0;
	for (int i = 0; i<M; ++i)
	{
		if (singleDog[i] != -1)
			if (count++ == 0)printf("%05d", singleDog[i]); else printf(" %05d", singleDog[i]);
	}
	//	printf("\n");
}

void Pat1066()
{
	int M, N, A, B, replaceValue, value, count = 0;
	scanf("%d %d %d %d %d", &M, &N, &A, &B, &replaceValue);
	for (int i = 0; i<M; ++i)
		for (int j = 0; j<N; ++j)
		{
		scanf("%d", &value);
		if (value >= A&&value <= B)
			if (++count%N == 0)printf("%03d\n", replaceValue); else printf("%03d ", replaceValue);
		else
			if (++count%N == 0)printf("%03d\n", value); else printf("%03d ", value);
		}
}

//输入可能是xxx xxxx，也可能是输入为空，所以不适合用scanf,
void Pat1067()
{
	char rightPsw[21], psw[100];
	int N, len = 0, count = 0;
	scanf("%s %d", rightPsw, &N);
	getchar();
	while (1)
	{
		gets(psw);
		++count;
		len = strlen(psw);
		if (len == 1 && psw[0] == '#')break;
		if ((!strcmp(rightPsw, psw)) && count <= N)
		{
			printf("Welcome in\n"); break;
		}
		else
		{
			if (count <= N)
			{
				printf("Wrong password: %s\n", psw);
				if (count == N)
				{
					printf("Account locked\n"); break;
				}
			}
		}
	}
}
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
//绝对值、唯一
void Pat1068()
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
}

void Pat1069()
{
	int M, N, S, count = 0, flag = 0, j = 0, isReward = 0;
	char name[20], str[1000][20];
	scanf("%d %d %d", &M, &N, &S);
	for (int i = 0; i<M; ++i)
	{
		++count;
		scanf("%s", name);
		isReward = 0;
		if (count == S || count - N == S)
		{
			for (int k = 0; k<j; ++k)
			{
				if (!strcmp(str[k], name))
					isReward = 1;
			}
			if (isReward)++S;
			else
			{
				printf("%s\n", name);
				strcpy(str[j++], name);
				S = count;
				flag = 1;
			}
		}
	}
	if (!flag)printf("Keep going...");
}


int cmpRope(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

//精度损失
//9.xx / 2 = 4.xx = 4 * 2 = 8
void Pat1070()
{
	int N;
	scanf("%d", &N);
	int *r = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i<N; ++i)scanf("%d", &r[i]);
	qsort(r, N, sizeof(int), cmpRope);
	double d = (double)r[0] / 2;
	for (int i = 1; i<N; ++i)
	{
		if (i == N - 1)
			d = d + (double)r[i] / 2;
		else
			d = (d + (double)r[i] / 2) / 2; 
	}
	printf("%d\n", (int)d);
}



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