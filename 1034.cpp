#include<stdio.h>

long gcd(long a, long b)
{
	return b == 0 ? a : gcd(b, a%b);
}

void print(long a, long b, long c, long d, int flag)
{
	long g = 1;
	if (a < 0)g = gcd(-a, b); else g = gcd(a, b);
	a /= g; b /= g;
	if (c < 0)g = gcd(-c, d); else g = gcd(c, d);
	c /= g; d /= g;
	if (a<0)printf("(");
	if (b != 1)
	if (a / b)printf("%ld %ld/%ld", a / b, a%b < 0 ? -a%b : a%b, b); else if (a)printf("%ld/%ld", a, b); else printf("0");
	else
		printf("%ld", a);
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
	if (c / d)printf("%ld %ld/%ld", c / d, c%d < 0 ? -c%d : c%d, d); else if (c)printf("%ld/%ld", c, d); else printf("0");
	else
		printf("%ld", c);
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
	if (num / den)printf("%ld %ld/%ld", num / den, num%den<0 ? -num%den : num%den, den); else
	if (num)printf("%ld/%ld", num, den); else printf("0");
	else
		printf("%ld", num);
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
	if (num / den)printf("%ld %ld/%ld", num / den, num%den<0 ? -num%den : num%den, den); else
	if (num)printf("%ld/%ld", num, den); else printf("0");
	else
		printf("%ld", num);
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
	if (num / den)printf("%ld %ld/%ld", num / den, num%den<0 ? -num%den : num%den, den); 
	else if (num)printf("%ld/%ld", num, den); else printf("0");
	else printf("%ld", num);
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
	if (num / den)printf("%ld %ld/%ld", num / den, num%den<0 ? -num%den : num%den, den); else
	if (num)printf("%ld/%ld", num, den); else printf("0");
	else
		printf("%ld", num);
	if (num<0)printf(")");
}

int main()
{
	long a1, b1, a2, b2;
	scanf("%ld/%ld%ld/%ld", &a1, &b1, &a2, &b2);
	printAdd(a1, b1, a2, b2); printf("\n");
	printSub(a1, b1, a2, b2); printf("\n");
	printMulti(a1, b1, a2, b2); printf("\n");
	printDiv(a1, b1, a2, b2); printf("\n");
	return 0;
}