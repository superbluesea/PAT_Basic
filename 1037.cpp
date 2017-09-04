#include<stdio.h>

int main()
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
	return 0;
}