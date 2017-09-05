/*
0.00+x.xxi

*/
#include<stdio.h>
#include<math.h>

int main()
{
	double R1, P1, R2, P2;
	scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);
	double A, B;
	A = (R1*R2)*cos(P1 + P2);
	B = (R1*R2)*sin(P1 + P2);
	if (fabs(A) < 0.01)A = 0.0f;// else A = a1*a2 - b1*b2;
	if (fabs(B) < 0.01)B = 0.0f;// else B = b1*a2 + a1*b2;
	if (B < 0)
		printf("%.2lf-%.2lfi\n", A, fabs(B));
	else
		printf("%.2lf+%.2lfi\n", A, B);
	return 0;
}